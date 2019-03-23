//给定日期, 判断是一年中的第几天
#include <iostream>
#include <cstdlib>
using namespace std;

int getDays(int year, int month, int date) {
    int months[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) months[1] = 29;
    if (year < 1 || month < 1 || month > 12 || date > months[month - 1] || date < 1) return -1;
    int days = 0;
    for (int i = 0; i < month - 1; i++) {
        days += months[i];
    }
    days += date;
    return days;
}

int main() {
    int year, month, date;
    cin >> year >> month >> date;
    cout << getDays(year, month, date) << endl;
    system("pause");
    return 0;
}
