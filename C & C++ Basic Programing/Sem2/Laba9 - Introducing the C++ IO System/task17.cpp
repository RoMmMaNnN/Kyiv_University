#include <iostream>
#include <cmath>
using namespace std;

class pwr {
    int base;
    int exponent;
    double result;

public:
    pwr(int b, int e) {
        base = b;
        exponent = e;
        result = 1;
        for (int i = 0; i < exponent; ++i) {
            result *= base;
        }
    }
    
    friend ostream& operator<<(ostream& out, const pwr& obj) {
        out << "Base: " << obj.base << ", Exponent: " << obj.exponent << ", Result: " << obj.result;
        return out;
    }

    friend istream& operator>>(istream& in, pwr& obj) {
        in >> obj.base >> obj.exponent;
        obj.result = 1;
        for (int i = 0; i < obj.exponent; ++i) {
            obj.result *= obj.base;
        }
        return in;
    }
};

int main() {
    pwr obj(2, 3);
    cout << obj << endl;

    cout << "Enter base and exponent: ";
    pwr obj2(0, 0);
    cin >> obj2;
    cout << obj2 << endl;

    return 0;
}
