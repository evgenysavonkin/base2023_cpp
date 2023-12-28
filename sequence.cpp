#include <iostream>

using namespace std;

int main() {
    int n = 0;
    cout << "Enter n number of sequence: " << endl;
    cin >> n;
    int k = 1;
    for (int i = 1; i <= n; i++) {
        if (i == n) {
            cout << k * k << " is the " << n << "th digit of the sequence";
            break;
        }
        k++;
    }
    return 0;
}