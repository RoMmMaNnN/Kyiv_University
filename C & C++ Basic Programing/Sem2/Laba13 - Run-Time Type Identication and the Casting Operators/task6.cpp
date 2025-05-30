#include <iostream>
#include <typeinfo>
#include <cmath>
#include <new>
#include <cstdlib>
using namespace std;

template <typename T>
class Number {
protected:
    T value;
public:
    Number(T n) { value = n; }
    virtual T get_value() { return value; }
    virtual ~Number() {}
};

template <typename T>
class Square : public Number<T> {
public:
    Square(T n) : Number<T>(n) {}
    T get_value() override {
        return this->value * this->value;
    }
};

template <typename T>
class Sqr_root : public Number<T> {
public:
    Sqr_root(T n) : Number<T>(n) {}
    T get_value() override {
        return sqrt((double)this->value);
    }
};

Number<double>* generator() {
    Number<double>* ptr = nullptr;
    try {
        switch (rand() % 2) {
            case 0:
                ptr = new (nothrow) Square<double>(rand() % 100);
                if (!ptr) throw bad_alloc();
                break;
            case 1:
                ptr = new (nothrow) Sqr_root<double>(rand() % 100);
                if (!ptr) throw bad_alloc();
                break;
        }
    } catch (bad_alloc& e) {
        cerr << "Memory allocation failed: " << e.what() << endl;
        return nullptr;
    }
    return ptr;
}

int main() {
    srand(time(0));
    for (int i = 0; i < 10; ++i) {
        Number<double>* p = generator();
        if (p == nullptr) {
            cout << "Skipping object due to memory error.\n";
            continue;
        }
        if (dynamic_cast<Square<double>*>(p))
            cout << "Square object: ";
        else if (dynamic_cast<Sqr_root<double>*>(p))
            cout << "Sqr_root object: ";
        else
            cout << "Unknown object: ";
        cout << "Value is: " << p->get_value() << endl;
        delete p;
    }
    return 0;
}
