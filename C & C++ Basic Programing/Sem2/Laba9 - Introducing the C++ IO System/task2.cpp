#include <iostream>
using namespace std;

int main() {
    int a = 493434;
    int b = -4876;
    int c = 0;

    cout << "showpos wasn't installed:" << endl;
    cout << a << " " << b << " " << c << endl;
    cout.setf(ios::showpos);
    cout << "\nshowpos was installed:" << endl;
    cout << a << " " << b << " " << c << endl;

    return 0;
}
