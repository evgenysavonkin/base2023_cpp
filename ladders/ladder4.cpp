//#include <iostream>
//
//using namespace std;
//
//int main() {
//    int number = 0;
//    int lessCounter = 0;
//    int moreCounter = 0;
//
//    cout << "Enter a number: " << endl;
//    cin >> number;
//
//    if (number < 10) {
//        cout << "Not a sequence" << endl;
//        return 0;
//    }
//
//    int previous = number % 10;
//    number /= 10;
//
//    while (number > 0) {
//        if (previous < number % 10) {
//            lessCounter++;
//        } else if (previous > number % 10) {
//            moreCounter++;
//        } else if (previous == number % 10) {
//            cout << "This sequence is arbitrary" << endl;
//            return 0;
//        }
//        previous = number % 10;
//        number /= 10;
//    }
//
//    if (lessCounter == 0) {
//        cout << "This sequence is increasing" << endl;
//    } else if (moreCounter == 0) {
//        cout << "This sequence is decreasing" << endl;
//    } else {
//        cout << "This sequence is arbitrary" << endl;
//    }
//
//    return 0;
//}
//
