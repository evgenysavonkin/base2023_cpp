//#include <iostream>
//
//using namespace std;
//
//const char arithmeticSymbols[]{'+', '-', '*', '/'};
//const int ARITHMETIC_SYMBOLS_SIZE = 4;
//const string arithmeticExpressionToEvaluate = "2+4131";
//
//double calculateExpression(string expression);
//bool isArithmeticSymbol(char symbol);
//
//int main() {
//    double result = calculateExpression(arithmeticExpressionToEvaluate);
//
//    if (result == 0) {
//        cout << "An error occured! Check if your string is valid!" << endl;
//        return -1;
//    }
//
//    cout << "Result of evaluating the expression:" << result << endl;
//    return 0;
//}
//
//bool isArithmeticSymbol(char symbol) {
//    for (int i = 0; i < ARITHMETIC_SYMBOLS_SIZE; ++i) {
//        if (symbol == arithmeticSymbols[i]) {
//            return true;
//        }
//    }
//
//    return false;
//}
//
//double calculateExpression(string expression) {
//    double res = 0.0;
//    double firstNumber = 0.0;
//    double secondNumber = 0.0;
//
//    string firstNumberStr;
//    string secondNumberStr;
//    string tempStr;
//
//    char arithmeticAction;
//    bool isFirstNumber = true;
//    for (int i = 0; expression[i] != '\0'; ++i) {
//        if (isArithmeticSymbol(expression[i])) {
//            arithmeticAction = expression[i];
//            isFirstNumber = false;
//            continue;
//        }
//        if (isFirstNumber) {
//            tempStr = expression[i];
//            firstNumberStr.append(tempStr);
//            tempStr.clear();
//            continue;
//        }
//        tempStr = expression[i];
//        secondNumberStr.append(tempStr);
//        tempStr.clear();
//    }
//
//    firstNumber = atof(firstNumberStr.c_str());
//    secondNumber = atof(secondNumberStr.c_str());
//
//    switch (arithmeticAction) {
//        case '+':
//            res = firstNumber + secondNumber;
//            break;
//        case '-':
//            res = firstNumber - secondNumber;
//            break;
//        case '*':
//            res = firstNumber * secondNumber;
//            break;
//        case '/':
//            res = firstNumber / secondNumber;
//            break;
//        default:
//            res = 0;
//    }
//
//    return res;
//}