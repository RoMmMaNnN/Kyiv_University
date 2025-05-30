#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    double a = 493434;
    double b = -4876;
    double c = 0;

    cout << "task 5" << endl;
    cout << "cout standard:" << endl;
    cout << a << " " << b << " " << c << endl;
    cout << "\ncout custom:" << endl;
    cout << showpoint << scientific << uppercase;
    cout << a << " " << b << " " << c << endl;
    cout << "task 6" << endl;
    cout << "┌──────────┬──────────┬──────────┐" << endl;
    cout << "│  Number  │   ln(x)  │ log10(x) │" << endl;
    cout << "├──────────┼──────────┼──────────┤" << endl;
    for (int i = 2; i <= 100; ++i) {
        cout << "│"
             << setw(10) << right << i << "│"
             << setw(10) << fixed << setprecision(5) << log(i) << "│"
             << setw(10) << fixed << setprecision(5) << log10(i) << "│"
             << endl;
    }
    cout << "└──────────┴──────────┴──────────┘" << endl;

    return 0;
}
