//#include <iostream>
//
//using namespace std;
//
//double fibonacci(int index);
//
//int main() {
//    int index = 0;
//    cout << "Using this program you can found out the n-th number of fibonacci function." << endl <<
//         "Example: 5 -> 5." << endl;
//    cout << "Enter a number: " << endl;
//    cin >> index;
//    cout << "The " << index << "-th number of fibonacci function is " << fibonacci(index);
//    return 0;
//}
//
//double fibonacci(int index) {
//    double firstNumber = 0;
//    double secondNumber = 1;
//    double result = 0;
//
//    if (index == 0) {
//        return 0;
//    }
//
//    int counter = 0;
//    while (counter <= index) {
//        if (counter < 2) {
//            counter++;
//            continue;
//        }
//
//        result = firstNumber + secondNumber;
//        firstNumber = secondNumber;
//        secondNumber = result;
//        counter++;
//    }
//
//    return secondNumber;
//}
