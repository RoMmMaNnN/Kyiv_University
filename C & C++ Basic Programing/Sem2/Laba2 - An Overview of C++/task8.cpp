#include <iostream>
#include <cmath>
using namespace std;

double myroot(int n);
double myroot(long n);
double myroot(double n);

int main() {
    cout << "Square root of 33: " << myroot(33) << endl;
    cout << "Square root of 111111L: " << myroot(111111L) << endl;
    cout << "Square root of 1514.4979: " << myroot(1514.4979) << endl;
    return 0;
}

double myroot(int n) {
    return sqrt(n);
}

double myroot(long n) {
    return sqrt(n);
}

double myroot(double n) {
    return sqrt(n);
}
