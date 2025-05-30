#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    cout.setf(ios::right);
    cout << "┌──────────┬──────────┬──────────┐" << endl;
    cout << "│  Number  │   ln(x)  │ log10(x) │" << endl;
    cout << "├──────────┼──────────┼──────────┤" << endl;
    cout.width(10);
    for (int i = 2; i <= 100; ++i) {
        cout << "│";
        cout.width(10);
        cout << i;
        cout.width(10);
        cout.precision(5);
        cout.setf(ios::fixed);
        cout << log(i);
        cout.width(10);
        cout.precision(5);
        cout.setf(ios::fixed);
        cout << log10(i) << "│" << endl;
    }
    cout << "└──────────┴──────────┴──────────┘" << endl;

    return 0;
}