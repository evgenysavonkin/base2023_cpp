#include <iostream>
#include <cstdlib>

using namespace std;

const int X_SIZE = 3;
const int Y_SIZE = 3;
const string VERT_DELIMITER = " | ";
const string HOR_DELIMITER = "---";
const char X_CHAR = 'X';
const char O_CHAR = 'O';
const int MAX_NUMBER_OF_GAMES = 6;
const int MAX_NUMBER_OF_GAMES_FOR_EACH_COMMAND = 3;
const int WINNING_NUM_POINTS = 3;
const int TIE_NUM_POINTS = 1;
const int LOOSING_NUM_POINTS = 0;

bool isTie = false;
int numberOfMachineActions = 0;
char userUnit = 'X';
char machineUnit = 'X';
bool isUserWon = false;
bool isUserActing = false;
char numbersField[X_SIZE][Y_SIZE]{'1', '2', '3', '4', '5', '6', '7', '8', '9'};
char gameField[X_SIZE][Y_SIZE]{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
int cornerCellNumbers[4]{1, 3, 7, 9};

void printField(char field[X_SIZE][Y_SIZE]);
void startGameWithUser();
void processUserUnitOfGame(char unit);
void userTurnToAction();
void machineTurnToAction();
bool isCellFree(int cellNumber);
void processGame();
bool isSomeoneWon();
int getIValueFromCellNumber(int cellNumber);
int getJValueFromCellNumber(int cellNumber);
void takeCell(int cellNumber, char unit);
bool isDrawGame();
bool isCenterTaken();
bool tryToTakeCorner();
bool checkHorizontalWinningProbability(char unit, bool loosingDetectionEnabled);
bool checkVerticalWinningProbability(char unit, bool loosingDetectionEnabled);
bool checkDiagonalWinningProbability(char unit, bool loosingDetectionEnabled);
bool checkWinningProbability(char unit, bool loosingDetectionEnabled);
void resetGame();
void resetGameField();

int main() {
    startGameWithUser();
    return 0;
}

void resetGameField() {
    for (int i = 0; i < Y_SIZE; ++i) {
        for (int j = 0; j < X_SIZE; ++j) {
            gameField[i][j] = ' ';
        }
    }
}

void resetGame() {
    resetGameField();
    isTie = false;
    numberOfMachineActions = 0;
    userUnit = 'X';
    machineUnit = 'X';
    isUserWon = false;
    isUserActing = false;
}

void startGameWithUser() {
    char userUnitChoice;
    char exitChoice;

    while (true) {
        cout << endl << endl << "Game: tic tac toe." << endl;
        cout << "The rules assign a unique number to each cell. " << endl;

        printField(numbersField);

        cout << endl << "What will you choose? X or O ?" << endl;
        cout << "\tYour answer: " << endl;
        cin >> userUnitChoice;

        processUserUnitOfGame(userUnitChoice);

        processGame();

        if (isTie) {
            cout << endl << "We have a tie!" << endl;
        } else {
            cout << endl << "We have a winner!" << endl;
            cout << "Congratulations, " << (isUserWon ? "Human" : "AI") << endl;
        }

        cout << "Do you want to continue? (Y/N)" << endl;
        cin >> exitChoice;

        if (exitChoice == 'N') {
            break;
        }

        resetGame();
    }

}

bool isSomeoneWon() {
    char currUserUnit = userUnit;
    char currMachineUnit = machineUnit;

    if ((gameField[0][0] == currUserUnit && gameField[0][1] == currUserUnit && gameField[0][2] == currUserUnit) ||
        (gameField[1][0] == currUserUnit && gameField[1][1] == currUserUnit && gameField[1][2] == currUserUnit) ||
        (gameField[2][0] == currUserUnit && gameField[2][1] == currUserUnit && gameField[2][2] == currUserUnit) ||
        (gameField[0][0] == currUserUnit && gameField[1][0] == currUserUnit && gameField[2][0] == currUserUnit) ||
        (gameField[0][1] == currUserUnit && gameField[1][1] == currUserUnit && gameField[2][1] == currUserUnit) ||
        (gameField[0][2] == currUserUnit && gameField[1][2] == currUserUnit && gameField[2][2] == currUserUnit) ||
        (gameField[0][0] == currUserUnit && gameField[1][1] == currUserUnit && gameField[2][2] == currUserUnit) ||
        (gameField[2][0] == currUserUnit && gameField[1][1] == currUserUnit && gameField[0][2] == currUserUnit)) {

        isUserWon = true;
        return true;
    }
    if ((gameField[0][0] == currMachineUnit && gameField[0][1] == currMachineUnit &&
         gameField[0][2] == currMachineUnit) ||
        (gameField[1][0] == currMachineUnit && gameField[1][1] == currMachineUnit &&
         gameField[1][2] == currMachineUnit) ||
        (gameField[2][0] == currMachineUnit && gameField[2][1] == currMachineUnit &&
         gameField[2][2] == currMachineUnit) ||
        (gameField[0][0] == currMachineUnit && gameField[1][0] == currMachineUnit &&
         gameField[2][0] == currMachineUnit) ||
        (gameField[0][1] == currMachineUnit && gameField[1][1] == currMachineUnit &&
         gameField[2][1] == currMachineUnit) ||
        (gameField[0][2] == currMachineUnit && gameField[1][2] == currMachineUnit &&
         gameField[2][2] == currMachineUnit) ||
        (gameField[0][0] == currMachineUnit && gameField[1][1] == currMachineUnit &&
         gameField[2][2] == currMachineUnit) ||
        (gameField[2][0] == currMachineUnit && gameField[1][1] == currMachineUnit &&
         gameField[0][2] == currMachineUnit)) {

        return true;
    }

    return false;
}

bool isDrawGame() {
    for (int i = 0; i < Y_SIZE; ++i) {
        for (int j = 0; j < X_SIZE; ++j) {
            if (gameField[i][j] == ' ') {
                return false;
            }
        }
    }

    isTie = true;
    return true;
}

void processGame() {

    int counter = 0;
    while (true) {
        if (isSomeoneWon() || isDrawGame()) {
            printField(gameField);
            break;
        }

        if (counter > 0) {
            printField(gameField);
        }

        if (isUserActing) {
            userTurnToAction();
            isUserActing = false;
        } else {
            machineTurnToAction();
            numberOfMachineActions++;
            isUserActing = true;
        }

        counter++;
    }
}

void machineTurnToAction() {
    cout << endl << "AI is thinking what cell to take.." << endl;

    if (checkWinningProbability(machineUnit, false)) {
        return;
    }
    if (checkWinningProbability(userUnit, true)) {
        return;
    }
    if (!isCenterTaken()) {
        takeCell(5, machineUnit);
        return;
    }
    if (numberOfMachineActions == 0 && isCenterTaken()) {
        tryToTakeCorner();
        return;
    }

    if (checkWinningProbability(machineUnit, false)) {
        return;
    }

    int randomCell = (rand() % 9) + 1;

    while (true) {
        if (isCellFree(randomCell)) {
            takeCell(randomCell, machineUnit);
            isUserActing = true;
            break;
        }
        randomCell = (rand() % 9) + 1;
    }
}

int getIValueFromCellNumber(int cellNumber) {
    if (cellNumber <= X_SIZE) {
        return 0;
    }
    if (cellNumber <= X_SIZE * 2) {
        return 1;
    }

    return 2;
}

int getJValueFromCellNumber(int cellNumber) {
    if (cellNumber == 1 || cellNumber == 4 || cellNumber == 7) {
        return 0;
    }
    if (cellNumber == 2 || cellNumber == 5 || cellNumber == 8) {
        return 1;
    }

    return 2;
}

bool isCellFree(int cellNumber) {
    int iPos = getIValueFromCellNumber(cellNumber);
    int jPos = getJValueFromCellNumber(cellNumber);

    if (gameField[iPos][jPos] != ' ') {
        return false;
    }

    return true;
}

void takeCell(int cellNumber, char unit) {
    int iPos = getIValueFromCellNumber(cellNumber);
    int jPos = getJValueFromCellNumber(cellNumber);

    gameField[iPos][jPos] = unit;
}

void userTurnToAction() {
    int cellNumber = 0;

    while (true) {
        cout << endl << "Enter a number of cell: " << endl;
        cin >> cellNumber;

        if (isCellFree(cellNumber)) {
            takeCell(cellNumber, userUnit);
            break;
        }

        cout << "Cell by number " << cellNumber << "is already taken!" << endl;
    }

    isUserActing = false;
}

bool isCenterTaken() {
    if (isCellFree(5)) {
        return false;
    }

    return true;
}

bool tryToTakeCorner() {
    int randomNumber = (rand() % 4) + 1;
    int randomCell = cornerCellNumbers[randomNumber];

    if (isCellFree(randomCell)) {
        takeCell(randomCell, machineUnit);
        return true;
    }

    return false;
}

bool checkHorizontalWinningProbability(char unit, bool loosingDetectionEnabled) {
    char currUnit = unit;
    if (gameField[0][0] == currUnit && gameField[0][1] == currUnit && isCellFree(X_SIZE)) {
        loosingDetectionEnabled ? takeCell(X_SIZE, machineUnit) : takeCell(X_SIZE, currUnit);
        return true;
    }
    if (gameField[0][2] == currUnit && gameField[0][1] == currUnit && isCellFree(X_SIZE - 2)) {
        loosingDetectionEnabled ? takeCell(X_SIZE - 2, machineUnit) : takeCell(X_SIZE - 2, currUnit);
        return true;
    }
    if (gameField[1][0] == currUnit && gameField[1][1] == currUnit && isCellFree(2 * X_SIZE)) {
        loosingDetectionEnabled ? takeCell(2 * X_SIZE, machineUnit) : takeCell(2 * X_SIZE, currUnit);
        return true;
    }
    if (gameField[1][2] == currUnit && gameField[1][1] == currUnit && isCellFree((2 * X_SIZE) - 2)) {
        loosingDetectionEnabled ? takeCell((2 * X_SIZE) - 2, machineUnit) : takeCell((2 * X_SIZE) - 2, currUnit);
        return true;
    }
    if (gameField[2][0] == currUnit && gameField[2][1] == currUnit && isCellFree(3 * X_SIZE)) {
        loosingDetectionEnabled ? takeCell(3 * X_SIZE, machineUnit) : takeCell(3 * X_SIZE, currUnit);
        return true;
    }
    if (gameField[2][2] == currUnit && gameField[2][1] == currUnit && isCellFree(3 * X_SIZE - 2)) {
        loosingDetectionEnabled ? takeCell(3 * X_SIZE - 2, machineUnit) : takeCell(3 * X_SIZE - 2, currUnit);
        return true;
    }
    if (gameField[0][0] == currUnit && gameField[0][2] == currUnit && isCellFree(2)) {
        loosingDetectionEnabled ? takeCell(2, machineUnit) : takeCell(2, currUnit);
        return true;
    }
    if (gameField[1][0] == currUnit && gameField[1][2] == currUnit && isCellFree(5)) {
        loosingDetectionEnabled ? takeCell(5, machineUnit) : takeCell(5, currUnit);
        return true;
    }
    if (gameField[2][0] == currUnit && gameField[2][2] == currUnit && isCellFree(8)) {
        loosingDetectionEnabled ? takeCell(8, machineUnit) : takeCell(8, currUnit);
        return true;
    }
    return false;
}

bool checkVerticalWinningProbability(char unit, bool loosingDetectionEnabled) {
    char currUnit = unit;
    if (gameField[0][0] == currUnit && gameField[1][0] == currUnit && isCellFree(7)) {
        loosingDetectionEnabled ? takeCell(7, machineUnit) : takeCell(7, currUnit);
        return true;
    }
    if (gameField[2][0] == currUnit && gameField[1][0] == currUnit && isCellFree(1)) {
        loosingDetectionEnabled ? takeCell(1, machineUnit) : takeCell(1, currUnit);
        return true;
    }
    if (gameField[0][1] == currUnit && gameField[1][1] == currUnit && isCellFree(8)) {
        loosingDetectionEnabled ? takeCell(8, machineUnit) : takeCell(8, currUnit);
        return true;
    }
    if (gameField[2][1] == currUnit && gameField[1][1] == currUnit && isCellFree(2)) {
        loosingDetectionEnabled ? takeCell(2, machineUnit) : takeCell(2, currUnit);
        return true;
    }
    if (gameField[0][2] == currUnit && gameField[1][2] == currUnit && isCellFree(9)) {
        loosingDetectionEnabled ? takeCell(9, machineUnit) : takeCell(9, currUnit);
        return true;
    }
    if (gameField[2][2] == currUnit && gameField[1][2] == currUnit && isCellFree(3)) {
        loosingDetectionEnabled ? takeCell(3, machineUnit) : takeCell(3, currUnit);
        return true;
    }
    if (gameField[0][0] == currUnit && gameField[2][0] == currUnit && isCellFree(4)) {
        loosingDetectionEnabled ? takeCell(4, machineUnit) : takeCell(4, currUnit);
        return true;
    }
    if (gameField[0][1] == currUnit && gameField[2][1] == currUnit && isCellFree(5)) {
        loosingDetectionEnabled ? takeCell(5, machineUnit) : takeCell(5, currUnit);
        return true;
    }
    if (gameField[2][2] == currUnit && gameField[0][2] == currUnit && isCellFree(6)) {
        loosingDetectionEnabled ? takeCell(6, machineUnit) : takeCell(6, currUnit);
        return true;
    }
    return false;
}

bool checkDiagonalWinningProbability(char unit, bool loosingDetectionEnabled) {
    char currUnit = unit;
    if (gameField[0][0] == currUnit && gameField[1][1] == currUnit && isCellFree(9)) {
        loosingDetectionEnabled ? takeCell(9, machineUnit) : takeCell(9, currUnit);
        return true;
    }
    if (gameField[2][2] == currUnit && gameField[1][1] == currUnit && isCellFree(1)) {
        loosingDetectionEnabled ? takeCell(1, machineUnit) : takeCell(1, currUnit);
        return true;
    }
    if (gameField[2][0] == currUnit && gameField[1][1] == currUnit && isCellFree(3)) {
        loosingDetectionEnabled ? takeCell(3, machineUnit) : takeCell(3, currUnit);
        return true;
    }
    if (gameField[0][2] == currUnit && gameField[1][1] == currUnit && isCellFree(7)) {
        loosingDetectionEnabled ? takeCell(7, machineUnit) : takeCell(7, currUnit);
        return true;
    }
    if (gameField[0][0] == currUnit && gameField[2][2] == currUnit && isCellFree(5)) {
        loosingDetectionEnabled ? takeCell(5, machineUnit) : takeCell(5, currUnit);
        return true;
    }
    if (gameField[0][2] == currUnit && gameField[2][0] == currUnit && isCellFree(5)) {
        loosingDetectionEnabled ? takeCell(5, machineUnit) : takeCell(5, currUnit);
        return true;
    }
    return false;
}


bool checkWinningProbability(char unit, bool loosingDetectionEnabled) {
    if (checkHorizontalWinningProbability(unit, loosingDetectionEnabled)) {
        return true;
    }
    if (checkVerticalWinningProbability(unit, loosingDetectionEnabled)) {
        return true;
    }
    if (checkDiagonalWinningProbability(unit, loosingDetectionEnabled)) {
        return true;
    }
    return false;
}

void processUserUnitOfGame(char unit) {
    if (unit == X_CHAR) {
        userUnit = X_CHAR;
        machineUnit = O_CHAR;
        isUserActing = true;
        return;
    }

    userUnit = O_CHAR;
    machineUnit = X_CHAR;
}

void printField(char field[X_SIZE][Y_SIZE]) {
    cout << endl;
    for (int i = 0; i < Y_SIZE; ++i) {
        for (int j = 0; j < X_SIZE; ++j) {
            if (j == X_SIZE - 1) {
                cout << field[i][j];
                continue;
            }
            cout << field[i][j] << VERT_DELIMITER;
        }

        cout << endl;
        if (i == Y_SIZE - 1) {
            continue;
        }

        int counter = 0;
        while (counter < X_SIZE) {
            cout << HOR_DELIMITER;
            counter++;
        }
        cout << endl;
    }
}
