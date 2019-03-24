//判断两天相隔天数
#include <iostream>
#include <cstdlib>
using namespace std;

int getDays(int year, int month, int date) {
    int months[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) months[1] = 29;
    if (year < 1 || month < 1 || month > 12 || date < 0 || date > months[month - 1]) return -1;

    int days = date;
    for (int i = 0; i < month - 1; i++) {
        days += months[i];
    }
    return days;
}

bool isLeapYear(int year) {
    if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) return true;
    return false;
}

int getYearDays(int year1, int year2) {//输入应保证year1 < year2
    int days = 0;
    for (int i = year1; i < year2; i++) {
        if (isLeapYear(i)) days += 366;
        else days += 365;
    }
    return days;
}

int getIntervalDays(int year1, int month1, int date1, int year2, int month2, int date2) {
    int d1, d2;
    if (year1 < year2) {
        d1 = getDays(year1, month1, date1);
        d2 = getDays(year2, month2, date2) + getYearDays(year1, year2);
    }
    else if (year1 > year2) {
        d1 = getDays(year2, month2, date2);
        d2 = getDays(year1, month1, date1) + getYearDays(year2, year1);
    }
    else {
        d1 = getDays(year1, month1, date1);
        d2 = getDays(year2, month2, date2);
    }
    return d2 - d1 > 0 ? d2 - d1 : d1 - d2;
}

int main() {
    int y1, m1, d1;
    int y2, m2, d2;
    cin >> y1 >> m1 >> d1 >> y2 >> m2 >> d2;
    cout << getIntervalDays(y1, m1, d1, y2, m2, d2) << endl;
    system("pause");
    return 0;
}
