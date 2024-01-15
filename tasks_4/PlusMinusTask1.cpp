//#include <iostream>
//
//using namespace std;
//
//const char digits[]{'0','1', '2', '3', '4', '5', '6', '7', '8', '9'};
//const int DIGITS_ARR_SIZE = 10;
//const string MINUS_STR = "-";
//const string PLUS_STR = "+";
//const string TEXT_TO_PROCESS = "70 notepads with processor i5 were sold by 239 USD.";
//
//string processText(string text);
//bool isDigit(char symbol);
//string getStringFromNumber(int number);
//
//int main() {
//    cout << "The result of converting a text is: " << processText(TEXT_TO_PROCESS) << endl;
//    return 0;
//}
//
//bool isDigit(char symbol) {
//    for (int i = 0; i < DIGITS_ARR_SIZE; ++i) {
//        if (digits[i] == symbol) {
//            return true;
//        }
//    }
//    return false;
//}
//
//string getStringFromNumber(int number) {
//    bool isMinus = false;
//    string resultStr;
//
//    if  (number == 0){
//        return resultStr;
//    }
//
//    if (number % 2 != 0) {
//        isMinus = true;
//    }
//    for (int i = 0; i < number; ++i) {
//        if (isMinus) {
//            resultStr.append(MINUS_STR);
//            continue;
//        }
//        resultStr.append(PLUS_STR);
//    }
//
//    return resultStr;
//}
//
//string processText(string text) {
//    string result;
//    string tempStr;
//
//    for (int i = 0; text[i] != '\0'; ++i) {
//        if (isDigit(text[i])) {
//            tempStr = text[i];
//            int number = stoi(tempStr);
//            string resultOfConvertingNumber = getStringFromNumber(number);
//            result.append(resultOfConvertingNumber);
//            tempStr.clear();
//            continue;
//        }
//        tempStr = text[i];
//        result.append(tempStr);
//        tempStr.clear();
//    }
//
//    return result;
//}
//
//
//
