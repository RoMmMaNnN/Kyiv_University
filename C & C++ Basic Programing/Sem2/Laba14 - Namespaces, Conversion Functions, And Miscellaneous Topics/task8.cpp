#include <iostream>
using namespace std;

class MyClass {
    int value;
public:
    MyClass(int v) : value(v) {}
    int getValue() { return value; }
};

void printValue(MyClass obj) {
    cout << "Value: " << obj.getValue() << endl;
}

int main() {
    MyClass a = 10;     // автоматичне перетворення int -> MyClass + попередження через невикористанян
    printValue(20);     // автоматичне перетворення int -> MyClass
    return 0;
}
