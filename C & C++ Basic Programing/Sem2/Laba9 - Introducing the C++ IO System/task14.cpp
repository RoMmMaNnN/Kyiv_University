#include <iostream>

using namespace std;

int main() {
    double num = 1000.5364;

    cout.setf(ios::left, ios::adjustfield);
    cout.setf(ios::fixed, ios::floatfield);
    cout.precision(2);
    cout.width(20);
    cout.fill('*');

    cout << num << endl;

    return 0;
}
