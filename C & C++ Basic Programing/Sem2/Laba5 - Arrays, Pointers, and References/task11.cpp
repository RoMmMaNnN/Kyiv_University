#include <iostream>
using namespace std;

void neg(int* num) {
    *num = -*num;
}

void neg(int& num) {
    num = -num;
}

int main() {
    int a = 77;
    int *ptr = &a;
    cout << a << endl;
    neg(ptr);
    cout << a << endl;
    neg(&a);
    cout << a << endl;
    return 0;
}