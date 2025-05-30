#include <iostream>
using namespace std;

class mybase {
protected:
    int a, b;
public:
    void setab(int i, int j) { a = i; b = j; }
    void getab(int &i, int &j) { i = a; j = b; }
};

class derived1 : public mybase { 
    int c;
public:
    void setc(int value) { c = value; }
    int getc() { return c; }
};

class derived2 : private mybase { 
    int c;
public:
    void setc(int value) { c = value; }
    int getc() { return c; }
    void setBase(int i, int j) { setab(i, j); }
    void getBase(int &i, int &j) { getab(i, j); }
};

int main() {
    derived1 obj1;
    derived2 obj2;
    int i, j;

    obj1.setab(5, 10);
    obj1.getab(i, j);
    cout << "obj1: a = " << i << ", b = " << j << endl;
    // obj2.getab(i, j); // буде помилка компіляції
    obj2.setBase(3, 6);
    obj2.getBase(i, j);
    cout << "obj2: a = " << i << ", b = " << j << endl;
    // obj1.c = 10; помилка
    // obj2.c = 10; помилка

    obj1.setc(20);
    cout << "obj1: c = " << obj1.getc() << endl;

    obj2.setc(30);
    cout << "obj2: c = " << obj2.getc() << endl;

    return 0;
}
