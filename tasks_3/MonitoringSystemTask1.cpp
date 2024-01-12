#include <iostream>

using namespace std;

int const START_LOOP_FROM = 2;
int const SIZE_OF_ARR = 5;

/* |
 * |                  ||
 * |                  ||
 * |              ||  ||
 * |      ||      ||  ||
 * |  ||  ||      ||  ||
 * |__||__||__||__||__||____
 * */

int heights[SIZE_OF_ARR]{2, 3, 1, 4, 6};

void getNotVisibleHeights(int arr[], int step, int size);

double getKRateFromEquationBetweenTwoPoints(int x1, int x2, int y1, int y2);

int getXCordFromNumber(int arr[], int key, int size, int step);

int main() {
    int step = 0;
    cout << "Enter a constant horizontal step:" << endl;
    cin >> step;
    if (step < 0) {
        cout << "The step can be negative!" << endl;
        return -1;
    }
    getNotVisibleHeights(heights, step, SIZE_OF_ARR);
    return 0;
}

double getKRateFromEquationBetweenTwoPoints(int x1, int x2, int y1, int y2) {
    return (double) (y2 - y1) / (x2 - x1);
}

int getXCordFromNumber(int arr[], int key, int size, int step) {
    int result = 0;
    for (int i = 0; i < size; ++i) {
        if (arr[i] == key) {
            result += step;
            return result;
        }
        result += step;
    }

    return -1;
}

void getNotVisibleHeights(int arr[], int step, int size) {
    if (size == 2) {
        cout << "Everything is visible" << endl;
        return;
    }
    int observerX = step;
    int observerY = arr[0];

    int firstColumnX = getXCordFromNumber(arr, arr[1], size, step);
    int firstColumnY = arr[1];
    double kRateToCompare = getKRateFromEquationBetweenTwoPoints(observerX, firstColumnX, observerY, firstColumnY);
    int counter = 0;

    for (int i = START_LOOP_FROM; i < size; ++i) {
        int currX = getXCordFromNumber(arr, arr[i], size, step);
        double currK = getKRateFromEquationBetweenTwoPoints(observerX, currX, observerY, arr[i]);
        if (currK < kRateToCompare) {
            cout << endl << "Can't see a place in pos [" << currX << "," << arr[i] << "]" << endl;
            counter++;
        }
    }
    if (counter == 0) {
        cout << "Everything is visible" << endl;
    }
}