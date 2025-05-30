#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int base, exponent;
    
    cout << "Enter first number: ";
    cin >> base;
    cout << "Enter second number: ";
    cin >> exponent;
    double result = pow(base, exponent);
    cout << base << "^" << exponent << " = " << result << std::endl;

    return 0;
}
