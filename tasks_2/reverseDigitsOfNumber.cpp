//#include <iostream>
//
//using namespace std;
//
//const string result_string = "The number after reversing its digits is ";
//
//int reverseDigits(long number);
//
//int getNumberOfDigits(long number);
//
//double pow(double number, int power);
//
//int main() {
//    long number = 0;
//
//    cout << "Using this program you can get a reversed version of your number." << endl << "Example: 1234 -> 4321."
//         << endl;
//    cout << "Enter a non-negative number without a zero digit on the end: " << endl;
//    cin >> number;
//
//    int reversedNumber = reverseDigits(number);
//    if (reversedNumber > 0) {
//        cout << result_string << reversedNumber << endl;
//        return 0;
//    }
//
//    return reversedNumber;
//}
//
//int reverseDigits(long number) {
//    if (number < 0) {
//        cout << "The number must be positive!" << endl;
//        return -1;
//    } else if (number % 10 == 0) {
//        cout << "The number must be without a zero digit on the end!" << endl;
//        return -2;
//    } else if (number == 0 || (number > 0 && number < 10)) {
//        return number;
//    }
//
//    int numberOfDigits = getNumberOfDigits(number);
//    int resultNumber = 0;
//
//    while (number > 0) {
//        numberOfDigits--;
//        int remain = number % 10;
//        resultNumber += remain * (int) pow(10, numberOfDigits);
//        number /= 10;
//    }
//
//    return resultNumber;
//}
//
//int getNumberOfDigits(long number) {
//    int numberOfDigits = 0;
//
//    while (number > 0) {
//        number /= 10;
//        numberOfDigits++;
//    }
//
//    return numberOfDigits;
//}
//
//double pow(double number, int power) {
//    double result = 1.0;
//
//    while (power > 0) {
//        result *= number;
//        power--;
//    }
//
//    return result;
//}
