#include <iostream>
#include <list>
#include <utility>

using namespace std;

const string arithmeticExpressionToEvaluate = "2-1+8/2*4+3*7";

double calculateExpression(string expression);
string convertToStringNumberWithoutZeros(double number);
list<string> split(string expression);
double calculateNumbers(string expression);
double getLastNumberFromExpression(string expression);
double getFirstNumberFromExpression(string expression);

int main() {
    cout << "The result of calculation of a string \"" << arithmeticExpressionToEvaluate << "\" equals "
         << calculateExpression(arithmeticExpressionToEvaluate) << endl;
    return 0;
}

bool isStringWithoutMultAndDivision(string expression) {
    bool result = true;

    for (int i = 0; expression[i] != '\0'; ++i) {
        if (expression[i] == '*' || expression[i] == '/') {
            return false;
        }
    }

    return result;
}

list<string> split(string expression) {
    list<string> strings;
    string utilStr;
    string currStr;

    for (int i = 0; expression[i] != '\0'; ++i) {
        if (i == expression.size() - 1) {
            utilStr = expression[i];
            currStr.append(utilStr);
            strings.push_back(currStr);
            break;
        }
        if (expression[i] == '*' || expression[i] == '/' || expression[i] == '+' || expression[i] == '-') {
            strings.push_back(currStr);
            currStr.clear();
            continue;
        }
        utilStr = expression[i];
        currStr.append(utilStr);
        utilStr.clear();
    }

    return strings;
}

bool isOneNumber(string expression) {
    list<string> strings = split(std::move(expression));
    return strings.size() == 1;
}

double calculateNumbers(string expression) {
    double result = 0.0;
    while (!isOneNumber(expression)) {
        string utilStr;
        string currNumberStr;
        string tempStr;
        for (int i = 0; expression[i] != '\0'; ++i) {
            string leftSide;
            string rightSide;
            if (expression[i] == '-' || expression[i] == '+') {
                leftSide.append(expression.substr(0, i));
                rightSide.append(expression.substr(i + 1, expression.length()));
                double firstNumber = getLastNumberFromExpression(leftSide);
                double secondNumber = getFirstNumberFromExpression(rightSide);
                double res = 0.0;
                if (expression[i] == '-') {
                    res = firstNumber - secondNumber;
                } else if (expression[i] == '+') {
                    res = firstNumber + secondNumber;
                }
                result = res;
                tempStr.append(convertToStringNumberWithoutZeros(result));
                string secondNumberStr = convertToStringNumberWithoutZeros(secondNumber);
                tempStr.append(rightSide.substr(secondNumberStr.length(), expression.length()));
                expression = tempStr;
                tempStr.clear();
                utilStr.clear();
                currNumberStr.clear();
                break;
            }
            utilStr = expression[i];
            currNumberStr.append(utilStr);
            utilStr.clear();
        }
    }

    return result;
}

double getLastNumberFromExpression(string expression) {
    list<double> numbers;
    list<string> numbersStr = split(std::move(expression));

    for (const auto &str: numbersStr) {
        double currNumber = atof(str.c_str());
        numbers.push_back(currNumber);
    }

    return numbers.back();
}

double getFirstNumberFromExpression(string expression) {
    list<double> numbers;
    list<string> numbersStr = split(std::move(expression));
    for (const auto &str: numbersStr) {
        double currNumber = atof(str.c_str());
        numbers.push_back(currNumber);
        break;
    }

    return numbers.front();
}

string convertToStringNumberWithoutZeros(double number) {
    string str = to_string(number);
    str.erase(str.find_last_not_of('0') + 1, string::npos);
    str.erase(str.find_last_not_of('.') + 1, string::npos);

    return str;
}

double calculateExpression(string expression) {
    double res = 0.0;
    int prevPlusOrMinusIndex = 0;

    while (!isStringWithoutMultAndDivision(expression)) {
        string utilStr;
        string resultStr;
        string leftStr;
        string rightStr;
        for (int i = 0; expression[i]; ++i) {
            if (expression[i] == '/' || expression[i] == '*') {
                char mathAction = expression[i];
                leftStr = resultStr.substr(0, i);
                rightStr = expression.substr(i + 1, expression.length());
                double lastNumberFromLeft = getLastNumberFromExpression(leftStr);
                double firstNumberFromRight = getFirstNumberFromExpression(rightStr);
                double result = 0.0;
                if (mathAction == '/') {
                    result = lastNumberFromLeft / firstNumberFromRight;
                } else {
                    result = lastNumberFromLeft * firstNumberFromRight;
                }
                string firstNumberFromRightStr = convertToStringNumberWithoutZeros(firstNumberFromRight);
                string rightStringToAppend;

                rightStringToAppend.append(rightStr.substr(firstNumberFromRightStr.length(), expression.length()));
                string leftSubstr = leftStr.substr(0, prevPlusOrMinusIndex + 1);

                utilStr.append(leftSubstr);
                utilStr.append(convertToStringNumberWithoutZeros(result));
                utilStr.append(rightStringToAppend);

                expression.assign(utilStr);
                utilStr.clear();
                leftStr.clear();
                leftStr.clear();
                rightStr.clear();
                firstNumberFromRightStr.clear();
                rightStringToAppend.clear();
                leftSubstr.clear();
                break;
            }
            if (expression[i] == '+' || expression[i] == '-') {
                prevPlusOrMinusIndex = i;
            }
            utilStr = expression[i];
            resultStr.append(utilStr);
            utilStr.clear();
        }
    }

    return calculateNumbers(expression);
}