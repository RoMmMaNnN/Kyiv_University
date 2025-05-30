#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

struct strtype {
    char *p;
    int len;

    strtype(char const *ptr);
    ~strtype();
    void show();
    char* get_string();
};

strtype::strtype(char const *ptr) {
    len = strlen(ptr);
    p = (char*)malloc(len + 1);
    if (!p) {
        cout << "Allocation error.\n";
        exit(1);
    }
    strcpy(p, ptr);
}

strtype::~strtype() {
    cout << "Freeing p\n";
    free(p);
}

void strtype::show() {
    cout << p << " length: " << len << "\n";
}

char* strtype::get_string() {
    return p;
}

int main() {
    strtype s1("This is a test."), s2("I hate any programming!");

    s1.show();
    s2.show();

    char *str1 = s1.get_string();
    char *str2 = s2.get_string();

    cout << "s1: " << str1 << endl;
    cout << "s2: " << str2 << endl;

    return 0;
}
