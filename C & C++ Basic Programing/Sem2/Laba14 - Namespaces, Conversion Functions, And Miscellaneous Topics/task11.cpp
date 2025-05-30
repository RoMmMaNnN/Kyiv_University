#include <iostream>
#include <cstring>
using namespace std;

class MyString {
    char* str;
public:
    MyString(const char* s) {
        str = new char[strlen(s) + 1];
        strcpy(str, s);
    }

    void show() const {
        cout << str << endl;
    }

    ~MyString() {
        delete[] str;
    }
};

int main() {
    MyString a("Hello");
    MyString b = "World"; //перетворення з const char*

    a = b; // один відділ пам'яті тому виклик двічі деструтора для одного і того ж відділу
    a.show();
    b.show();
    return 0;
}
