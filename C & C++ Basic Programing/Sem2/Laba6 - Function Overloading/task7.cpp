#include <iostream>
using namespace std;

float f(float t) {
    return t / 2.0;
}
double f(double t) { 
    return t / 3.0; 
}

void f(unsigned char c) {
    cout << "unsigned char: " << c << endl;
}
void f(char c) {
    cout << "char: " << c << endl;
}

int f(int a, int b) { return a + b; }
int f(int a, int &b) { return a - b; }

int f1(int a) { return a * a; }
int f1(int a, int b = 0) { return a * b; }

int main() {
    int a = 2, b = 10;
    float x = 10.09;
    double y = 10.09;

    cout << f(x) << endl;
    cout << f(y) << endl;
    cout << f1(b) << endl;
    cout << f1(a, b) << endl;

    return 0;
}
