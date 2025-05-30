#include <iostream>
using namespace std;

class area {
public:
    virtual double getarea() = 0;
    void setarea(double d1, double d2) {
        dim1 = d1;
        dim2 = d2;
    }

    void getdim(double &d1, double &d2) {
        d1 = dim1;
        d2 = dim2;
    }

protected:
    double dim1, dim2;
};

class rectangle : public area {
public:
    double getarea() override {
        return dim1 * dim2;
    }
};

class triangle : public area {
public:
    double getarea() override {
        return 0.5 * dim1 * dim2;
    }
};

class base {
public:
    virtual void func() {
        cout << "Using base version of func()\n";
    }
};

class derived1 : public base {
public:
    void func() override {
        cout << "Using derived1 version of func()\n";
    }
};

class derived2 : public derived1 {
public:
    // У цьому класі не перевизначено функцію, тому викликлатиметься з першого дочірнього
};

int main() {
    rectangle r;
    area a;
    r.setarea(3.3, 4.5);
    cout << "Rectangle has area: " << r.getarea() << "\n";

    triangle t;
    t.setarea(4.0, 5.0);
    cout << "Triangle has area: " << t.getarea() << "\n";

    base* p;

    base obj; 
    derived1 objd1;
    derived2 objd2;

    // Використання базової
    p = &obj;
    p->func();
    // з derived1
    p = &objd1;
    p->func();
    // з derived2
    p = &objd2;
    p->func();

    return 0;
}
