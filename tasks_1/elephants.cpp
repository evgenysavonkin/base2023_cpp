//#include <iostream>
//
//const int minValue = 1;
//const int maxValue = 8;
//
//using namespace std;
//
//bool checkCords(int x1, int y1, int x2, int y2) {
//    if (!(x1 >= minValue && x1 <= maxValue) || !(x2 >= minValue && x2 <= maxValue)) {
//        return false;
//    }
//    if (!(y1 >= minValue && y1 <= maxValue) || !(y2 >= minValue && y2 <= maxValue)) {
//        return false;
//    }
//    return true;
//}
//
//bool processCordsAndGetResult(int x1, int y1, int x2, int y2) {
//    if (x1 == x2 && y1 == y2) {
//        cout << "Can't be in one place!" << endl;
//        return false;
//    }
//    if (!checkCords(x1, y1, x2, y2)) {
//        cout << "Incorrect values!" << endl;
//        return false;
//    }
//    if (abs(x1 - x2) == abs(y1 - y2)) {
//        return true;
//    }
//    return false;
//}
//
//void inputCords() {
//    int x1 = 0;
//    int y1 = 0;
//    int x2 = 0;
//    int y2 = 0;
//    cout << "Enter x1: " << endl;
//    cin >> x1;
//    cout << "Enter y1: " << endl;
//    cin >> y1;
//    cout << "Enter x2: " << endl;
//    cin >> x2;
//    cout << "Enter y2: " << endl;
//    cin >> y2;
//    cout << (processCordsAndGetResult(x1, y1, x2, y2) ? "Can beat each other" : "Can't beat each other") << endl;
//}
//
//int main() {
//    inputCords();
//    return 0;
//}
