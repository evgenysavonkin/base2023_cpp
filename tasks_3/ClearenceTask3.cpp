//#include <iostream>
//
//using namespace std;
//
//int const CUBE_SIZE = 4;
//
//bool cube[CUBE_SIZE][CUBE_SIZE][CUBE_SIZE];
//int lumenCoordinates[6] = {0};
//
//void fillCube();
//void drawCubeLayers();
//void fillCoordinates(int x1, int y1, int z1, int x2, int y2, int z2);
//bool checkLumen();
//bool checkXSide(int i, int j);
//bool checkYSide(int i, int j);
//bool checkZSide(int i, int j);
//
//int main() {
//    cout << "Checking the cube for any lumen." << endl;
//    fillCube();
//    drawCubeLayers();
//    if (checkLumen()) {
//        cout << "There's a lumen in the cube!" << endl;
//        cout << "From X:" << lumenCoordinates[0] << " Y:" << lumenCoordinates[1] << " Z:" << lumenCoordinates[2];
//        cout << " | To X:" << lumenCoordinates[3] << " Y:" << lumenCoordinates[4] << " Z:" << lumenCoordinates[5] << endl;
//        return 0;
//    }
//
//    cout << "There's no any lumen in the cube!" << endl;
//    return 0;
//}
//
//void fillCube() {
//    srand(time(NULL));
//
//    for (int i = 0; i < CUBE_SIZE; ++i) {
//        for (int j = 0; j < CUBE_SIZE; ++j) {
//            for (int k = 0; k < CUBE_SIZE; ++k) {
//                cube[i][j][k] = rand() % 2;
//            }
//        }
//    }
//}
//
//void drawCubeLayers() {
//    int layer = 0;
//
//    cout << "Cube is divided by layers, top view" << endl;
//    cout << "X means horizontal dimension | Y means vertical dimension | Z means layer number" << endl;
//
//    for (int i = 0; i < CUBE_SIZE; ++i) {
//        cout << "Layer #" << layer << endl;
//        for (int j = 0; j < CUBE_SIZE; ++j) {
//            for (int k = 0; k < CUBE_SIZE; ++k) {
//                cout << cube[i][j][k] << " ";
//            }
//            cout << endl;
//        }
//        cout << endl;
//        layer++;
//    }
//}
//
//bool checkLumen() {
//    for (int i = 0; i < CUBE_SIZE; ++i) {
//        for (int j = 0; j < CUBE_SIZE; ++j) {
//            if (checkXSide(i, j))
//                return true;
//            if (checkYSide(i, j))
//                return true;
//            if (checkZSide(i, j))
//                return true;
//        }
//    }
//
//    return false;
//}
//
//bool checkXSide(int i, int j) {
//    bool isLumen = false;
//
//    for (int k = 1; k < CUBE_SIZE; ++k) {
//        if (cube[i][j][k] == cube[i][j][k - 1] && cube[i][j][k] == 0) {
//            isLumen = true;
//        } else {
//            return false;
//        }
//    }
//    fillCoordinates(0, j, i, CUBE_SIZE - 1, j, i);
//
//    return isLumen;
//}
//
//bool checkYSide(int i, int j) {
//    bool isLumen = false;
//
//    for (int k = 1; k < CUBE_SIZE; ++k) {
//        if (cube[i][k][j] == cube[i][k - 1][j] && cube[i][k][j] == 0) {
//            isLumen = true;
//        } else {
//            return false;
//        }
//    }
//    fillCoordinates(j, 0, i, j, CUBE_SIZE - 1, i);
//
//    return isLumen;
//}
//
//bool checkZSide(int i, int j) {
//    bool isLumen = false;
//
//    for (int k = 1; k < CUBE_SIZE; ++k) {
//        if (cube[k][i][j] == cube[k - 1][i][j] && cube[k][i][j] == 0) {
//            isLumen = true;
//        } else {
//            return false;
//        }
//    }
//    fillCoordinates(j, i, 0, j, i, CUBE_SIZE - 1);
//
//    return isLumen;
//}
//
//void fillCoordinates(int x1, int y1, int z1, int x2, int y2, int z2) {
//    lumenCoordinates[0] = x1;
//    lumenCoordinates[1] = y1;
//    lumenCoordinates[2] = z1;
//    lumenCoordinates[3] = x2;
//    lumenCoordinates[4] = y2;
//    lumenCoordinates[5] = z2;
//}