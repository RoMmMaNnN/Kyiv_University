#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

void myclreol(int positions = -1) {
    if (positions == -1) {
        cout << "\033[K";
    } else {
        cout << "\033[" << positions << "P";
    }
    cout.flush();
}

int main() {
    cout << "Line for first test: Hello, World!";
    cout.flush();
    this_thread::sleep_for(chrono::seconds(1));
    cout << "\033[7D";
    myclreol(6);
    
    this_thread::sleep_for(chrono::seconds(1));
    cout << endl;

    cout << "Line for second test: rdh 8x2ur92xj0";
    cout.flush();
    this_thread::sleep_for(chrono::seconds(1));

    cout << "\033[8D";
    myclreol(); 
    this_thread::sleep_for(chrono::seconds(1));

    return 0;
}
