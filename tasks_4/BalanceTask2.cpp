//#include <iostream>
//#include <map>
//#include <stack>
//
//using namespace std;
//
//const string bracketsStr = "<({>)}";
//map<char, int> bracketsMap{
//        {'(', 0},
//        {'[', 0},
//        {'{', 0},
//        {'<', 0},
//        {')', 0},
//        {']', 0},
//        {'}', 0},
//        {'>', 0},
//};
//
//bool checkTheBracketsBalance(string brackets);
//
//int main() {
//    cout << (checkTheBracketsBalance(bracketsStr) ? "Brackets are balanced" : "Brackets aren't balanced") << endl;
//    return 0;
//}
//
//bool checkTheBracketsBalance(string brackets) {
//    stack<char> openingBracketsStack;
//    bool result = true;
//    bool openingBracket = false;
//    int counter = 0;
//    for (int i = 0; brackets[i] != '\0'; ++i) {
//        char currChar = brackets[i];
//        if (currChar == '(' || currChar == '[' || currChar == '{' || currChar == '<') {
//            openingBracketsStack.push(currChar);
//            openingBracket = true;
//        }
//        if (openingBracket) {
//            counter = bracketsMap[currChar];
//            bracketsMap[currChar] = ++counter;
//            openingBracket = false;
//        } else {
//            counter = bracketsMap[currChar];
//            bracketsMap[currChar] = ++counter;
//        }
//    }
//
//    while (!openingBracketsStack.empty()) {
//        char currChar = openingBracketsStack.top();
//        openingBracketsStack.pop();
//        if (currChar == '(' && bracketsMap[currChar] != bracketsMap[')']) {
//            return false;
//        }
//        if (currChar == '[' && bracketsMap[currChar] != bracketsMap[']']) {
//            return false;
//        }
//        if (currChar == '{' && bracketsMap[currChar] != bracketsMap['}']) {
//            return false;
//        }
//        if (currChar == '<' && bracketsMap[currChar] != bracketsMap['>']) {
//            return false;
//        }
//    }
//
//    return result;
//}
