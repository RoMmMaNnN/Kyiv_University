#include <iostream>
using namespace std;

class MyClass {
    int x;
public:
    MyClass(int val) : x(val) {}

    void show() const {
        cout << "Before: x = " << x << endl;

        MyClass* self = const_cast<MyClass*>(this);
        self->x = 999;

        cout << "After: x = " << x << endl;
    }
};

int main() {
    MyClass obj(123);
    obj.show();  // "константна" функція змінює дані

    return 0;
}
