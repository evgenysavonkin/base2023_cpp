#include <iostream>

using namespace std;

int const CUBE_SIZE = 4;

bool cube[CUBE_SIZE][CUBE_SIZE][CUBE_SIZE];
int holeCoordinate[6] = {0};

void fillCube();
void drawCubeLayers();
void fillCoordinates(int x1, int y1, int z1, int x2, int y2, int z2);
bool checkHole();
bool checkXSide(int i, int j);
bool checkYSide(int i, int j);
bool checkZSide(int i, int j);

int main() {
    cout << "Checking the cube for holes" << endl;
    fillCube();
    drawCubeLayers();
    if (checkHole()) {
        cout << "There's a hole in the cube!" << endl;
        cout << "From X:" << holeCoordinate[0] << " Y:" << holeCoordinate[1] << " Z:" << holeCoordinate[2];
        cout << " | To X:" << holeCoordinate[3] << " Y:" << holeCoordinate[4] << " Z:" << holeCoordinate[5] << endl;
        return 0;
    }

    cout << "There's no hole in the cube!" << endl;
    return 0;
}

void fillCube() {
    srand(time(NULL));

    for (int i = 0; i < CUBE_SIZE; ++i) {
        for (int j = 0; j < CUBE_SIZE; ++j) {
            for (int k = 0; k < CUBE_SIZE; ++k) {
                cube[i][j][k] = rand() % 2;
            }
        }
    }
}

void drawCubeLayers() {
    int layer = 0;

    cout << "Cube is divided by layers, top view" << endl;
    cout << "X means horizontal dimension | Y means vertical dimension | Z means layer number" << endl;

    for (int i = 0; i < CUBE_SIZE; ++i) {
        cout << "Layer #" << layer << endl;
        for (int j = 0; j < CUBE_SIZE; ++j) {
            for (int k = 0; k < CUBE_SIZE; ++k) {
                cout << cube[i][j][k] << " ";
            }
            cout << endl;
        }
        cout << endl;
        layer++;
    }
}

bool checkHole() {
    for (int i = 0; i < CUBE_SIZE; ++i) {
        for (int j = 0; j < CUBE_SIZE; ++j) {
            if (checkXSide(i, j))
                return true;
            if (checkYSide(i, j))
                return true;
            if (checkZSide(i, j))
                return true;
        }
    }

    return false;
}

bool checkXSide(int i, int j) {
    bool isHole = false;

    for (int k = 1; k < CUBE_SIZE; ++k) {
        if (cube[i][j][k] == cube[i][j][k - 1] && cube[i][j][k] == 0) {
            isHole = true;
        } else {
            return false;
        }
    }
    fillCoordinates(0, j, i, CUBE_SIZE - 1, j, i);

    return isHole;
}

bool checkYSide(int i, int j) {
    bool isHole = false;

    for (int k = 1; k < CUBE_SIZE; ++k) {
        if (cube[i][k][j] == cube[i][k - 1][j] && cube[i][k][j] == 0) {
            isHole = true;
        } else {
            return false;
        }
    }
    fillCoordinates(j, 0, i, j, CUBE_SIZE - 1, i);

    return isHole;
}

bool checkZSide(int i, int j) {
    bool isHole = false;

    for (int k = 1; k < CUBE_SIZE; ++k) {
        if (cube[k][i][j] == cube[k - 1][i][j] && cube[k][i][j] == 0) {
            isHole = true;
        } else {
            return false;
        }
    }
    fillCoordinates(j, i, 0, j, i, CUBE_SIZE - 1);

    return isHole;
}

void fillCoordinates(int x1, int y1, int z1, int x2, int y2, int z2) {
    holeCoordinate[0] = x1;
    holeCoordinate[1] = y1;
    holeCoordinate[2] = z1;
    holeCoordinate[3] = x2;
    holeCoordinate[4] = y2;
    holeCoordinate[5] = z2;
}