#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int num = 123;
    cout.setf(ios::showbase);
    cout.setf(ios::hex);
    cout << num << endl;
    cout.unsetf(ios::showbase);
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    cout << 123.456 << endl;
    return 0;
}
