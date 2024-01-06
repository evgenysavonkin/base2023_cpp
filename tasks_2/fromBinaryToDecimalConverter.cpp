//#include <iostream>
//
//using namespace std;
//1111111111111111111111111111111111111111111111111111
//
//const int MAX_BINARY_VAL = 1111111111;
//const int MIN_BINARY_VAL = 0;
//
//
//long convertBinaryToDecimalNumber(long number);
//
//double pow(double number, int power);
//
//int main() {
//    long binaryNumber = 0;
//
//    cout << "Using this program you can convert a number from binary to decimal." << endl <<
//         "Example: 11011 -> 27." << endl;
//    cout << "Enter a binary number from " << MIN_BINARY_VAL << " to " << MAX_BINARY_VAL << ":" << endl;
//    cin >> binaryNumber;
//
//    if (binaryNumber < MIN_BINARY_VAL || binaryNumber > MAX_BINARY_VAL) {
//        cout << "Number is out of bounds!" << endl;
//        return -1;
//    }
//
//    cout << "Result of converting from binary number " << binaryNumber << " to decimal is "
//         << convertBinaryToDecimalNumber(binaryNumber) << endl;
//
//    return 0;
//}
//
//long convertBinaryToDecimalNumber(long number) {
//    int numberOfDigits = 0;
//    long copyOfNumber = number;
//    long result = 0;
//
//    while (copyOfNumber > 0) {
//        numberOfDigits++;
//        copyOfNumber /= 10;
//    }
//
//    int counter = 0;
//    while (number > 0) {
//        int remain = number % 10;
//        if (remain == 1) {
//            result += remain * (long) pow(2, counter);
//        }
//        number /= 10;
//        counter++;
//    }
//
//    return result;
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
