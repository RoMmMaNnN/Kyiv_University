#include <iostream>
#include <chrono>
#include <thread>

using namespace std;
using namespace std::chrono;

class stopwatch {
    steady_clock::time_point start_time;
    bool running;
public:
    stopwatch() : running(false) {}

    stopwatch(bool start_now) {
        running = false;
        if (start_now) start();
    }

    void start() {
        start_time = steady_clock::now();
        running = true;
    }

    void stop() {
        if (!running) {
            cout << "Stopwatch was not started!" << endl;
            return;
        }
        auto end_time = steady_clock::now();
        duration<double> elapsed_secs = end_time - start_time;
        cout << "Time: " << elapsed_secs.count() << " seconds" << endl;
        running = false;
    }
};

int main() {
    stopwatch sw1;
    cout << "Stopwatch 1 started" << endl;
    sw1.start();
    this_thread::sleep_for(chrono::seconds(3));
    sw1.stop();

    stopwatch sw2(false);
    cout << "Stopwatch 2 started" << endl;
    sw2.start();
    this_thread::sleep_for(chrono::seconds(2));
    sw2.stop();

    return 0;
}
