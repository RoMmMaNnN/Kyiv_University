#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

template <class T>
class Num {
public:
    T x;
    Num(T i) { x = i; }
    virtual T get_val() { return x; }
    virtual ~Num() {}
};

template <class T>
class Square : public Num<T> {
public:
    Square(T i) : Num<T>(i) {}
    T get_val() override { return this->x * this->x; }
};

int main() {
    Num<double>* ptrb = new Square<double>(5.5);
    
    // каст до іншого шаблонного типу не працює
    // Square<double>* ptrd = dynamic_cast<Num<int>*>(ptrb); не пов’язані типи

    Square<double>* ptrd = dynamic_cast<Square<double>*>(ptrb);
    if (ptrd) {
        cout << "Square<double> object: value = " << ptrd->get_val() << endl;
    } else {
        cout << "Cast failed." << endl;
    }

    delete ptrb;
    return 0;
}
