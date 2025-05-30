#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

class strtype {
private:
    char *p;
    int len;

public:
    strtype(const char *ptr);
    ~strtype();
    void show();
};

strtype::strtype(const char *ptr) {
    len = strlen(ptr);
    p = (char *)malloc(len + 1);
    if (!p) {
        cout << "Allocation error\n";
        exit(1);
    }
    strcpy(p, ptr);
    cout << "Constructing: " << p << " (length: " << len << ")" << endl;
}

strtype::~strtype() {
    cout << "Freeing p: " << p << endl;
    free(p);
}

void strtype::show() {
    cout << "Showing: " << p << " (length: " << len << ")" << endl;
    free(p);
}

strtype make_str(const char *text) {
    strtype temp(text);
    return temp;
}

int main() {
    strtype str("Tom, Billy and Andy");
    str.show();
    
    return 0;
}
