#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double result = 10.0 / 3;

    // Version 1 — using ios class member functions
    cout << "Version 1 (using ios::fixed and precision):" << endl;
    cout.setf(ios::fixed);
    cout.precision(4);
    cout << result << endl;

    // Resetting formatting for the next output
    cout.unsetf(ios::fixed);
    cout.precision(6);

    cout << endl;

    // Version 2 — using manipulators
    cout << "Version 2 (using manipulators):" << endl;
    cout << fixed << setprecision(4) << result << endl;

    return 0;
}
