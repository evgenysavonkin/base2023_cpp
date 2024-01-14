//#include <iostream>
//#include <cstdlib>
//#include <windows.h>
//
//using namespace std;
//
//const int SIZE_OF_ARR = 5;
//const char LEFT_CHAR = '<';
//const char RIGHT_CHAR = '>';
//
//char arr[SIZE_OF_ARR]{};
//
//void randomInitRecruits(char arr[], int size);
//int getRandomNumber();
//void printArr(char arr[], int size);
//void printArrAndSleep(char arr[], int indexesToSleep[], int size);
//void startTurning(char arr[], int size);
//void resetIndexesToSleep(int arr[], int size);
//
//int main() {
//    randomInitRecruits(arr, SIZE_OF_ARR);
//    cout << "Turn left!" << endl;
//    printArr(arr, SIZE_OF_ARR);
//    startTurning(arr, SIZE_OF_ARR);
//    return 0;
//}
//
//void printArrAndSleep(char arr[], int indexesToSleep[], int size) {
//    int sleepCounter = 0;
//    for (int i = 0; i < size; ++i) {
//        if (i == indexesToSleep[sleepCounter]) {
//            _sleep(1000);
//            cout << arr[i] << " ";
//            sleepCounter++;
//            continue;
//        }
//        cout << arr[i] << " ";
//    }
//    cout << endl;
//}
//
//void resetIndexesToSleep(int arr[], int size) {
//    for (int i = 0; i < size; ++i) {
//        arr[i] = 0;
//    }
//}
//
//void startTurning(char arr[], int size) {
//    bool isTurning = false;
//    int indexesToSleep[size];
//    resetIndexesToSleep(indexesToSleep, size);
//
//    int counter = 0;
//    for (int i = 0; i < size; ++i) {
//        isTurning = false;
//        for (int j = 0; j < size - 1; ++j) {
//            if (arr[j] == RIGHT_CHAR && arr[j + 1] == LEFT_CHAR) {
//                arr[j] = LEFT_CHAR;
//                arr[j + 1] = RIGHT_CHAR;
//                j += 1;
//                indexesToSleep[counter] = j - 1;
//                indexesToSleep[++counter] = j;
//
//                isTurning = true;
//                counter++;
//            }
//            if (!isTurning && j == size - 2) {
//                cout << endl;
//                printArr(arr, size);
//                Beep(530, 1000);
//                return;
//            }
//        }
//        counter = 0;
//
//        printArrAndSleep(arr,indexesToSleep, size);
//        resetIndexesToSleep(indexesToSleep, size);
//    }
//}
//
//void printArr(char arr[], int size) {
//    for (int i = 0; i < size; ++i) {
//        cout << arr[i] << " ";
//    }
//    cout << endl;
//}
//
//void randomInitRecruits(char arr[], int size) {
//    for (int i = 0; i < size; ++i) {
//        int randomNumber = getRandomNumber();
//        if (randomNumber % 2 == 0) {
//            arr[i] = LEFT_CHAR;
//        }
//        if (randomNumber % 2 == 1) {
//            arr[i] = RIGHT_CHAR;
//        }
//    }
//}
//
//int getRandomNumber() {
//    return (rand() % 100) + 1;
//}
