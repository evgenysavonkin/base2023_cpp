#include <iostream>
#include <cstdlib>
#include <windows.h>

using namespace std;

const int X_SIZE = 3;
const int Y_SIZE = 3;
const string VERT_DELIMITER = " | ";
const string HOR_DELIMITER = "---";
const char X_CHAR = 'X';
const char O_CHAR = 'O';
const int MAX_NUMBER_OF_GAMES = 6;
const int WINNING_NUM_POINTS = 3;
const int TIE_NUM_POINTS = 1;

int numberOfPointsForUser = 0;
int numberOfPointsForMachine = 0;
bool isTournament = false;
int numberOfUserGames = 0;
int numberOfMachineGames = 0;
bool isTie = false;
int numberOfMachineActions = 0;
int numberOfUserActions = 0;
char userUnit = 'X';
char machineUnit = 'X';
bool isUserWon = false;
bool isMachineWon = false;
bool isUserActing = false;
char numbersField[X_SIZE][Y_SIZE]{'1', '2', '3', '4', '5', '6', '7', '8', '9'};
char gameField[X_SIZE][Y_SIZE]{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
int cornerCellNumbers[4]{1, 3, 7, 9};
int userCellsNotAllowedArr[X_SIZE]{0, 0, 0};
int machineCellsNotAllowedArr[X_SIZE]{0, 0, 0};

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
bool isCellAllowed(int cellNumber, int arr[]);
void resetCellsNotAllowedArr(int arr[]);
void printCellsNotAllowed(int arr[]);
void addToCellsNotAllowedArr(int cellNumber, bool isUser);
void processTournamentChoice(char choice);
bool tryToTakeCornerWithTournament();
int getRandomNumberFromOneToNine();

int main() {
    char userInput;
    cout << "Do you want to turn on tournament mode? (Y/N)" << endl;
    cin >> userInput;
    processTournamentChoice(userInput);
    startGameWithUser();
    return 0;
}

void processTournamentChoice(char choice) {
    if (choice == 'Y' || choice == 'y') {
        isTournament = true;
        cout << "Tournament mode is enabled." << endl;
        return;
    }

    cout << "Tournament mode is disabled." << endl;
    isTournament = false;
}

bool isCellAllowed(int cellNumber, int arr[]) {
    for (int i = 0; i < X_SIZE; ++i) {
        if (arr[i] == cellNumber) {
            return false;
        }
    }

    return true;
}

void printCellsNotAllowed(int arr[]) {
    for (int i = 0; i < X_SIZE; ++i) {
        cout << arr[i] << " ";
    }
}

void addToCellsNotAllowedArr(int cellNumber, bool isUser) {
    if (isUser) {
        userCellsNotAllowedArr[numberOfUserGames] = cellNumber;
        return;
    }

    machineCellsNotAllowedArr[numberOfMachineGames] = cellNumber;
}

void resetCellsNotAllowedArr(int arr[]) {
    for (int i = 0; i < X_SIZE; ++i) {
        arr[i] = 0;
    }
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
    numberOfUserActions = 0;
    userUnit = 'X';
    machineUnit = 'X';
    isUserWon = false;
    isMachineWon = false;
    isUserActing = false;
}

void processGameCommands(char userUnitChoice, char exitChoice) {
    int counter = 0;

    while (true) {
        if (isTournament) {
            counter++;
        }
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

            if (isUserWon) {
                numberOfPointsForUser += WINNING_NUM_POINTS;
            } else if (isMachineWon) {
                numberOfPointsForMachine += WINNING_NUM_POINTS;
            } else {
                numberOfPointsForUser += TIE_NUM_POINTS;
                numberOfPointsForMachine += TIE_NUM_POINTS;
            }
        }

        cout << "Do you want to continue? (Y/N)" << endl;
        cin >> exitChoice;

        if (exitChoice == 'N') {
            break;
        }

        resetGame();

        if (isTournament) {
            if (counter == MAX_NUMBER_OF_GAMES) {
                break;
            }
            if (numberOfUserGames == 2) {
                resetCellsNotAllowedArr(userCellsNotAllowedArr);
                numberOfUserGames = 0;
                continue;
            }
            if (numberOfMachineGames == 2) {
                resetCellsNotAllowedArr(machineCellsNotAllowedArr);
                numberOfMachineGames = 0;
                continue;
            }

            userUnitChoice == X_CHAR ? numberOfUserGames++ : numberOfMachineGames++;
        }
    }
}

void startGameWithUser() {
    char userUnitChoice;
    char exitChoice;

    if (isTournament) {
        processGameCommands(userUnitChoice, exitChoice);

        if (numberOfPointsForUser == numberOfPointsForMachine) {
            cout << endl <<"The tournament is over! We have a tie!" << endl;
            return;
        }
        cout << endl << "The tournament is over! The winner is ";
        if (numberOfPointsForUser > numberOfPointsForMachine) {
            cout << "Human." << endl;
        } else if (numberOfPointsForMachine > numberOfPointsForUser) {
            cout << "AI." << endl;
        }
        cout << "Human points: " << numberOfPointsForUser << endl;
        cout << "AI points: " << numberOfPointsForMachine << endl;
        return;
    }

    processGameCommands(userUnitChoice, exitChoice);
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

        isMachineWon = true;
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
            printField(numbersField);
            cout << endl;
            printField(gameField);
        }
        if (isUserActing) {
            userTurnToAction();
            numberOfUserActions++;
            isUserActing = false;
        } else {
            machineTurnToAction();
            numberOfMachineActions++;
            isUserActing = true;
        }

        counter++;
    }
}

bool tryToTakeCornerWithTournament() {
    while (true) {
        int randomNumber = (rand() % 4); // 0 -> 3
        int randomCell = cornerCellNumbers[randomNumber];

        if (isCellFree(randomCell) && isCellAllowed(randomCell, machineCellsNotAllowedArr)) {
            takeCell(randomCell, machineUnit);
            addToCellsNotAllowedArr(randomCell, false);
            return true;
        }

        return false;
    }
}

int getRandomNumberFromOneToNine() {
    return (rand() % 9) + 1;
}

void machineTurnToAction() {
    cout << endl << "AI is thinking what cell to take.." << endl;

    if (checkWinningProbability(machineUnit, false)) {
        return;
    }
    if (checkWinningProbability(userUnit, true)) {
        return;
    }
    if (isTournament) {
        if (machineUnit == X_CHAR && numberOfMachineActions == 0) {
            if (!isCenterTaken() && isCellAllowed(5, machineCellsNotAllowedArr)) {
                takeCell(5, machineUnit);
                addToCellsNotAllowedArr(5, false);
                return;
            }
            if (tryToTakeCornerWithTournament()) {
                return;
            }

            int randomCell = getRandomNumberFromOneToNine();

            while (true) {
                if (isCellFree(randomCell) && isCellAllowed(randomCell, machineCellsNotAllowedArr)) {
                    takeCell(randomCell, machineUnit);
                    isUserActing = true;
                    return;
                }

                randomCell = getRandomNumberFromOneToNine();
            }
        }
        if (!isCenterTaken()) {
            takeCell(5, machineUnit);
            return;
        }
        if ((numberOfMachineActions == 0 && isCenterTaken()) || isCenterTaken()) {
            if (tryToTakeCorner()) {
                return;
            }
        }
        if (checkWinningProbability(machineUnit, false)) {
            return;
        }

        int randomCell = getRandomNumberFromOneToNine();
        while (true) {
            if (isCellFree(randomCell)) {
                takeCell(randomCell, machineUnit);
                isUserActing = true;
                break;
            }

            randomCell = getRandomNumberFromOneToNine();
        }
    } else {
        if (!isCenterTaken()) {
            takeCell(5, machineUnit);
            return;
        }
        if ((numberOfMachineActions == 0 && isCenterTaken()) || isCenterTaken()) {
            if (tryToTakeCorner()) {
                return;
            }
        }
        if (checkWinningProbability(machineUnit, false)) {
            return;
        }

        int randomCell = getRandomNumberFromOneToNine();
        while (true) {
            if (isCellFree(randomCell)) {
                takeCell(randomCell, machineUnit);
                isUserActing = true;
                break;
            }
            randomCell = getRandomNumberFromOneToNine();
        }
    }
}

void userTurnToAction() {
    int cellNumber = 0;
    int counter = 0;

    while (true) {
        cout << endl << "Enter a number of cell: " << endl;
        cin >> cellNumber;

        if (isTournament) {
            if (userUnit == X_CHAR && numberOfUserActions == 0) {
                if (isCellAllowed(cellNumber, userCellsNotAllowedArr)) {
                    takeCell(cellNumber, userUnit);
                    addToCellsNotAllowedArr(cellNumber, true);
                    break;
                }

                cout << "The first move should not be repeated with the previous ones!" << endl;
                continue;
            }
        }

        if (isCellFree(cellNumber)) {
            takeCell(cellNumber, userUnit);
            break;
        }

        cout << "Cell by number " << cellNumber << " is already taken!" << endl;
        counter++;
    }

    isUserActing = false;
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

bool isCenterTaken() {
    if (isCellFree(5)) {
        return false;
    }

    return true;
}

bool tryToTakeCorner() {
    while (true) {
        int randomNumber = (rand() % 4);
        int randomCell = cornerCellNumbers[randomNumber];

        if (isCellFree(randomCell)) {
            takeCell(randomCell, machineUnit);
            return true;
        }

        return false;
    }

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
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    cout << endl;
    for (int i = 0; i < Y_SIZE; ++i) {
        for (int j = 0; j < X_SIZE; ++j) {
            if (field[i][j] == X_CHAR) {
                SetConsoleTextAttribute(hConsole, 1);
            } else if (field[i][j] == O_CHAR) {
                SetConsoleTextAttribute(hConsole, 4);
            }

            if (j == X_SIZE - 1) {
                cout << field[i][j];
                continue;
            }

            cout << field[i][j];
            SetConsoleTextAttribute(hConsole, 7);
            cout << VERT_DELIMITER;
        }

        cout << endl;
        if (i == Y_SIZE - 1) {
            continue;
        }

        int counter = 0;
        while (counter < X_SIZE) {
            SetConsoleTextAttribute(hConsole, 7);
            cout << HOR_DELIMITER;
            counter++;
        }
        cout << endl;
    }

    SetConsoleTextAttribute(hConsole, 7);
}
