#include <iostream>
using namespace std;

class Num {
    int number;
public:
    Num(int n) : number(n) {}

    int getNumber() const {
        return number;
    }

    virtual void shownum() const {
        cout << "Number: " << number << endl;
    }

    virtual ~Num() {}
};

class outhex : public Num {
public:
    outhex(int n) : Num(n) {}

    void shownum() const override {
        cout << "Hexadecimal: " << hex << getNumber() << endl;
    }
};

class outoct : public Num {
public:
    outoct(int n) : Num(n) {}

    void shownum() const override {
        cout << "Octal: " << oct << getNumber() << endl;
    }
};

int main() {
    Num* ptr;

    outhex h(7989);
    outoct o(4644);

    ptr = &h;
    ptr->shownum();

    ptr = &o;
    ptr->shownum();

    return 0;
}
