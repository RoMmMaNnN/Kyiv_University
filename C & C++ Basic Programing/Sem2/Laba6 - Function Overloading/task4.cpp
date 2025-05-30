#include <iostream>
#include <cstdlib>

using namespace std;

class myclass {
    int *ptr;
public:
    myclass(int i) {
        ptr = new int;
        if (!ptr) { exit(1); }
        *ptr = i;
    }

    myclass(const myclass &obj) {
        ptr = new int;
        *ptr = *obj.ptr;
    }

    ~myclass() {
        delete ptr;
    }

    friend int getval(const myclass &obj);
};

int getval(const myclass &obj) {
    return *obj.ptr;
}

int main() {
    myclass a(1), b(2);
    cout << getval(a) << " " << getval(b) << "\n";
    return 0;
}
