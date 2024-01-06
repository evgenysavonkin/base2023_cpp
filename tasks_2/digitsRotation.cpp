//#include <iostream>
//
//using namespace std;
//
//bool isRotating(long number);
//
//double pow(double number, int power);
//
//int getNumberOfDigits(long number);
//
//long getBinaryNumberFromDecimal(long number);
//
//long reverseNumber(long number, int numberOfDigits);
//
//int main() {
//    long number = 0;
//
//    cout << "Using this program you can find out if a number is rotating." << endl <<
//         "Example: 21 -> Is rotating because 21 -> 10101 in binary representation." << endl;
//    cout << "Enter a number: " << endl;
//    cin >> number;
//    cout << "Binary representation of this number is " << getBinaryNumberFromDecimal(number) << endl;
//    cout << (isRotating(number) ? "Is rotating" : "Isn't rotating");
//
//    return 0;
//}
//
//bool isRotating(long number) {
//    int prev = number % 2;
//    number = number / 2;
//
//    while (number > 0) {
//        if (prev == number % 2) {
//            return false;
//        }
//
//        prev = number % 2;
//        number = number / 2;
//    }
//
//    return true;
//}
//
//long getBinaryNumberFromDecimal(long number) {
//    long result = 0;
//    int remain = 0;
//    int numberOfDigits = getNumberOfDigits(number);
//    int numberOfDigitsCopy = numberOfDigits;
//
//    while (number > 0) {
//        numberOfDigitsCopy--;
//        remain = number % 2;
//        if (remain == 1) {
//            result += (long) pow(10, numberOfDigitsCopy);
//        }
//        number = number / 2;
//    }
//
//    return reverseNumber(result, numberOfDigits);
//}
//
//int getNumberOfDigits(long number) {
//    int numberOfDigits = 0;
//
//    while (number > 0) {
//        number = number / 2;
//        numberOfDigits++;
//    }
//
//    return numberOfDigits;
//}
//
//long reverseNumber(long number, int numberOfDigits) {
//    int resultNumber = 0;
//
//    while (number > 0) {
//        numberOfDigits--;
//        int remain = number % 10;
//        resultNumber += remain * (long) pow(10, numberOfDigits);
//        number /= 10;
//    }
//
//    return resultNumber;
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
//
//
//
