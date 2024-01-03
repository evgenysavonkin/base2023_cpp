//#include <iostream>
//
//using namespace std;
//
//const int maxDayValue = 31;
//const int minDayValue = 0;
//const int minMonthValue = 0;
//const int maxMonthValue = 12;
//
//int main() {
//    int day = 0;
//    int month = 0;
//    int year = 0;
//
//    cout << "Enter day: " << endl;
//    cin >> day;
//    if (!(day > minDayValue && day <= maxDayValue)) {
//        cout << "Incorrect day. Must be in a range of (01-31)";
//        return -1;
//    }
//    cout << "Enter month: " << endl;
//    cin >> month;
//    if (!(month > minMonthValue && month <= maxMonthValue)) {
//        cout << "Incorrect month. Must be in a range of (01-12)";
//        return -2;
//    }
//    cout << "Enter year: " << endl;
//    cin >> year;
//    int sum = 0;
//
//    if (day < 10) {
//        sum += day;
//    } else {
//        sum += day / 10;
//        sum += day % 10;
//    }
//    if (month < 10) {
//        sum += month;
//    } else {
//        sum += month / 10;
//        sum += month % 10;
//    }
//    sum += year / 1000;
//    sum += year / 100 % 10;
//    sum += year / 10 % 10;
//    sum += year % 10;
//    if (sum < 10) {
//        cout << "Fate number is " << sum;
//        return 0;
//    }
//    int result = sum / 10;
//    result += sum % 10;
//
//    cout << "Fate number is " << result;
//    return 0;
//}
//
