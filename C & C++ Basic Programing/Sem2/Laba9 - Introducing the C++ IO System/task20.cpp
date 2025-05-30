#include <iostream>
#include <ctime>

using namespace std;

class watch {
    int hours;
    int minutes;
    int seconds;

public:
    watch() {
        time_t currentTime = time(nullptr);
        struct tm *localTime = localtime(&currentTime);
        hours = localTime->tm_hour;
        minutes = localTime->tm_min;
        seconds = localTime->tm_sec;
    }

    void display() {
        cout << "Current time: ";
        if (hours < 10) cout << "0";
        cout << hours << ":";
        if (minutes < 10) cout << "0";
        cout << minutes << ":";
        if (seconds < 10) cout << "0";
        cout << seconds << endl;
    }
};

int main() {
    watch w;
    w.display();
    return 0;
}
