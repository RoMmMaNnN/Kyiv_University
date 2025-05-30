#include <iostream>

using namespace std;

#define abs(x) ((x) < 0 ? -(x) : (x))

int main() {
    int a = -1;
    long b = -1L;
    double c = -1.00;

    cout << "Absolute value of int: " << abs(a) << endl;
    cout << "Absolute value of long: " << abs(b) << endl;
    cout << "Absolute value of double: " << abs(c) << endl;

    return 0;
}
