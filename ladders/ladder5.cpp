//#include <iostream>
//#include <cmath>
//
//using namespace std;
//
//int main() {
//    int number = 0;
//    int sum = 0;
//    int min = 9;
//    int max = 0;
//    int countOfDigits = 0;
//    double avg = 0;
//
//    cout << "Enter a number: " << endl;
//    cin >> number;
//
//    while (number > 0) {
//        int reminder = number % 10;
//        if (min > reminder) {
//            min = reminder;
//        }
//        if (max < reminder) {
//            max = reminder;
//        }
//        sum += reminder;
//        number /= 10;
//        countOfDigits++;
//    }
//
//    avg = (double) sum / countOfDigits;
//
//    cout << "Minimum number is " << min << endl;
//    cout << "Maximum number is " << max << endl;
//    cout << "Average number is " << round(avg) << endl;
//
//    return 0;
//}
//
