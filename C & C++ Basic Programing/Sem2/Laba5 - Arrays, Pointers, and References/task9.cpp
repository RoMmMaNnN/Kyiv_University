#include <iostream>

using namespace std;

int main() {
    double* p;
    p = new double;
    *p = -123.0987;

    cout << *p << endl;

    delete p;

    return 0;
}
