#include <iostream>

using namespace std;

class base {
protected:
    int a;
public:
    void load_a(int n) { a = n; }

    int get_a() { return a; }
};

class derived : public base {
private:
    int b;
public:
    void load_b(int n) { b = n; }

    int get_b() { return b; }
};

int main() {
    derived d1, d2;
    d1.load_a(1);
    d1.load_b(2);

    d2 = d1;

    cout << "d1: a = " << d1.get_a() << ", b = " << d1.get_b() << endl;
    cout << "d2: a = " << d2.get_a() << ", b = " << d2.get_b() << endl;

    return 0;
}
