#include <iostream>
#include <stack>

using namespace std;

const string brackets = "([])";

bool checkTheBracketsBalance(string brackets);

int main() {
    cout << (checkTheBracketsBalance(brackets) ? "true" : "false") << endl;
    return 0;
}

bool checkTheBracketsBalance(string brackets) {
    stack<char> bracketsStack;

    for (int i = 0; brackets[i] != '\0'; ++i) {
        if (brackets[i] == '(' || brackets[i] == '{' || brackets[i] == '[') {
            bracketsStack.push(brackets[i]);
            continue;
        }
        if (bracketsStack.empty()){
            return false;
        }
        if (brackets[i] == ')' && bracketsStack.top() == '(') {
            bracketsStack.pop();
            continue;
        }
        if (brackets[i] == '}' && bracketsStack.top() == '{') {
            bracketsStack.pop();
            continue;
        }
        if (brackets[i] == ']' && bracketsStack.top() == '[') {
            bracketsStack.pop();
            continue;
        }
        return false;
    }

    return bracketsStack.empty();
}
