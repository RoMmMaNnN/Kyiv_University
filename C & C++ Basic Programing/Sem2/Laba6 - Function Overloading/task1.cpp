#include <iostream>
#include <cstring>

using namespace std;

class strtype {
    char *p;
    int len;
public:
    strtype() {
        len = 255;
        p = new char[len];
        p[0] = '\0';
    }
    strtype(const char *s, int size) {
        if (size <= 0) size = 255;
        len = size;
        p = new char[len];
        strncpy(p, s, len - 1);
        p[len - 1] = '\0';
    }
    ~strtype() {
        delete[] p;
    }
    
    char *getstring() { return p; }
    int getlength() { return len; }
};

int main() {
    strtype s1;
    strtype s2("Roman", 7);
    
    cout << s1.getstring() << " - length: " << s1.getlength() << endl;
    cout << s2.getstring() << " - length: " << s2.getlength() << endl;

    return 0;
}
