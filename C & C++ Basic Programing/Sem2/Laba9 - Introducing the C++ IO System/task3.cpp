#include <iostream>
using namespace std;

int main() {
    double a = 493434;
    double b = -4876;
    double c = 0;

    cout << "cout standart" << endl;
    cout << a << " " << b << " " << c << endl;

    cout.setf(ios::showpoint);
    cout.setf(ios::scientific);
    cout.setf(ios::uppercase);

    cout << "\ncout custom" << endl;
    cout << a << " " << b << " " << c << endl;

    return 0;
}
