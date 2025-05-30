#include <iostream>
#include <cstring>

using namespace std;

class strtype {
private:
    char* p;
    int len;

public:
    strtype(const char* ptr) {
        len = strlen(ptr);
        p = new char[len + 1];
        strcpy(p, ptr);
    }

    ~strtype() {
        cout << "Freeing p" << endl;
        delete[] p;
    }

    void show() const {
        cout << p << " length: " << len << endl;
    }
};

int main() {
    strtype s1("This is a test."), s2("I like C++.");

    s1.show();
    s2.show();

    return 0;
}
