#include <iostream>
#include <ctime>

using namespace std;

class time_and_date {
private:
    int year, month, day, hour, minute, second;

public:
    time_and_date(int y, int m, int d, int h, int min, int sec) {
        year = y;
        month = m;
        day = d;
        hour = h;
        minute = min;
        second = sec;
    }

    void show() {
        cout << "Date and Time: "
             << year << "-" << month << "-" << day << " "
             << hour << ":" << minute << ":" << second << endl;
    }
};

int main() {
    time_t t = time(0);
    struct tm* currentTime = localtime(&t);
    time_and_date currentDateTime(currentTime->tm_year + 1900, currentTime->tm_mon + 1, currentTime->tm_mday, currentTime->tm_hour, currentTime->tm_min, currentTime->tm_sec);
    currentDateTime.show();

    return 0;
}
