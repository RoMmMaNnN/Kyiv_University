#include <iostream>
#include <typeinfo>
using namespace std;

class A {
public:
    virtual void f() {}
};

class B : public A {};
class C : public A {}; //додано клас та вивід

int main() {
    A* p;     
    A obja;  
    B objb;  
    C objc;  
    int i;

    cout << "Enter 0 for A object, ";
    cout << "1 for B object or ";
    cout << "2 for C object.\n";
    cin >> i;

    if (i == 1)
        p = &objb; 
    else if (i == 2)
        p = &objc; 
    else
        p = &obja; 

    cout << "You selected an object of type: " << typeid(*p).name() << endl;

    return 0;
}
