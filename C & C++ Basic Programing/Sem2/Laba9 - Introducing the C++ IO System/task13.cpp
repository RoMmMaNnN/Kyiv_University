#include <iostream>

using namespace std;

int main() {
    int num = 100;

    cout.setf(ios::dec, ios::basefield);
    cout << num << endl;

    cout.setf(ios::hex, ios::basefield);
    cout.setf(ios::showbase);
    cout << num << endl;

    cout.setf(ios::oct, ios::basefield);
    cout << num << endl;

    return 0;
}
