#include <iostream>
using namespace std;

int main() {
    int number = 100;

    ios::fmtflags originalFlags = cout.flags();

    cout.setf(ios::hex, ios::basefield);
    cout.setf(ios::showbase);
    cout << "Hex with showbase: " << number << endl;

    cout.flags(originalFlags);
    cout << "Back to original format: " << number << endl;

    return 0;
}
