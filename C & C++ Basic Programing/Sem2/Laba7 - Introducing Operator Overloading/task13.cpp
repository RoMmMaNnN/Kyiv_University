#include <iostream>
#include <cstring>
using namespace std;

class strtype {
    char *ptr;
    int len;
public:
    strtype(const char *s) {
        len = strlen(s) + 1;
        ptr = new char[len];
        strcpy(ptr, s);
        cout << "Created: " << ptr << endl;
    }

    ~strtype() {
        cout << "Destroyed: " << ptr << endl;
        delete[] ptr;
    }

    char &operator[](int i) {
        if (i < 0 || i >= len - 1) {
            cout << "Index out of bounds: " << i << endl;
            exit(1);
        }
        return ptr[i];
    }

    void show() { cout << "String: " << ptr << endl; }
};

int main() {
    strtype s("Hello");

    cout << "s[1]: " << s[1] << endl;
    s[1] = 'a';
    cout << "Modified: ";
    s.show();

    s[10] = 'X';

    return 0;
}
