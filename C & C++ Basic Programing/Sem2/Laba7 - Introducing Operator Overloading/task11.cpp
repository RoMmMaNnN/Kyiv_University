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

    strtype(const strtype &obj) { 
        len = strlen(obj.ptr) + 1;
        ptr = new char[len];
        strcpy(ptr, obj.ptr);
        cout << "Copied: " << ptr << endl;
    }

    ~strtype() { 
        cout << "Destroyed: " << ptr << endl;
        delete[] ptr;
    }

    strtype& operator=(const strtype &obj) {
        if (this == &obj) return *this; 

        cout << "Assigned: " << obj.ptr << " -> " << ptr << endl;
        delete[] ptr;
        len = obj.len;
        ptr = new char[len];
        strcpy(ptr, obj.ptr);
        return *this;
    }

    void show() { cout << "String: " << ptr << endl; }
};

void testCopy(strtype obj) {
    cout << "Function call -> ";
    obj.show();
}

int main() {
    cout << "Copy constructor\n";
    strtype a("Hello");
    testCopy(a);
    a.show();  

    cout << "\nAssignment operator\n";
    strtype b("World");
    b = a;
    b.show();

    cout << "\nSelf-assignment\n";
    a = a;

    return 0;
}
