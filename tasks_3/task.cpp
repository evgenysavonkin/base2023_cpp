//#include <iostream>
//
//using namespace std;
//
//
//int linearSearch(int key, int arr[], int size) {
//    for (int i = 0; i < size; ++i) {
//        if (arr[i] == key) {
//            return arr[i];
//        }
//    }
//
//    return -1;
//}
//
//void bubbleSort(int arr[], int size) {
//    for (int i = 0; i < size; ++i) {
//        for (int j = 0; j < size - i; ++j) {
//            if (arr[j] > arr[j + 1]) {
//                int temp = arr[j];
//                arr[j] = arr[j + 1];
//                arr[j + 1] = temp;
//            }
//        }
//    }
//}
//
//int main() {
//    int arr[5]{3, 1, 4, -1, 3};
//    bubbleSort(arr);
//
//    return 0;
//}