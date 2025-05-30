#include <iostream>

using namespace std;

class myclass {
public:
    myclass();
    myclass(const myclass &obj);

    myclass f();
    myclass g(myclass obj);

    ~myclass() { cout << "Destruction" << endl; }
};

myclass::myclass() {
    cout << "Constructing normally\n";
}

myclass::myclass(const myclass &obj) {
    cout << "Constructing copy\n";
}

myclass myclass::f() {
    myclass temp;
    return temp;
}

myclass myclass::g(myclass obj) {
    myclass temp = obj;
    return temp;
}

int main() {
    myclass obj;
    obj.f();
    obj.g(obj);
    return 0;
}
