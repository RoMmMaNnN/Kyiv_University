#include <iostream>
using namespace std;

class A {
    int i;
public:
    A(int a) { i = a; }
    void showA() { cout << "i = " << i << endl; }
};

class B {
    int j;
public:
    B(int a) { j = a; }
    void showB() { cout << "j = " << j << endl; }
};

class C : public A, public B {
    int k;
public:
    C(int a, int b, int c) : A(a), B(b), k(c) {}
    void showC() {
        showA();
        showB();
        cout << "k = " << k << endl;
    }
};

int main() {
    C obj(1, 2, 3);
    obj.showC();
    return 0;
}
