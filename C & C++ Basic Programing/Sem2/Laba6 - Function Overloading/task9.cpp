#include <iostream>
#include <ctime>
#include <cstdio>
using namespace std;

class Date {
    int day, month, year;
public:
    Date(int m, int d, int y) {
        day = d;
        month = m;
        year = y;
    }
    Date(time_t t) {
        struct tm* timeinfo = localtime(&t);
        day = timeinfo->tm_mday;
        month = timeinfo->tm_mon + 1;
        year = timeinfo->tm_year + 1900;
    }

    void show() {
        cout << month << '.' << day << '.' << year << endl;
    }
};

int main() {
    Date intdate(3, 20, 2024);
    intdate.show();
    time_t now = time(nullptr);
    Date timedate(now);
    timedate.show();

    return 0;
}
