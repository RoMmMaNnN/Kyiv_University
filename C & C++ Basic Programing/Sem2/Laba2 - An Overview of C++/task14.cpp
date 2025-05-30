#include <iostream>
#include <ctime>

using namespace std;

class stopwatch {
private:
    clock_t start_time;
    clock_t end_time;
    bool isStarted;

public:
    stopwatch() : start_time(0), end_time(0), isStarted(false) {}

    void start() {
        if (!isStarted) {
            start_time = clock();
            isStarted = true;
        }
    }

    void stop() {
        if (isStarted) {
            end_time = clock();
            isStarted = false;
        }
    }

    void show() {
        if (isStarted) {
            cout << "Elapsed time: " << (clock() - start_time) / (double)CLOCKS_PER_SEC << " seconds" << endl;
        } else {
            cout << "Elapsed time: " << (end_time - start_time) / (double)CLOCKS_PER_SEC << " seconds" << endl;
        }
    }

    ~stopwatch() {
        if (isStarted) {
            end_time = clock();
        }
        cout << "Elapsed time before destruction: " << (end_time - start_time) / (double)CLOCKS_PER_SEC << " seconds" << endl;
    }
};

int main() {
    stopwatch sw;

    sw.start();
    cout << "Press any key to stop the stopwatch" << endl;
    cin.get();
    sw.stop();
    sw.show();

    return 0;
}
