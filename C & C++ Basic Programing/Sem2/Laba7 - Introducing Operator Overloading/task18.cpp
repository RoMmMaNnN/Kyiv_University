#include <iostream>
#include <cstring>
using namespace std;

class strtype {
    char* str;
    int length;
public:
    strtype(const char* s = "") {
        length = strlen(s);
        str = new char[length + 1];
        strcpy(str, s);
    }
    ~strtype() {
        delete[] str;
    }

    strtype operator+(const strtype& other) {
        int newLength = length + other.length;
        char* temp = new char[newLength + 1];
        strcpy(temp, str);
        strcat(temp, other.str);

        strtype newStr(temp);
        delete[] temp;
        return newStr;
    }

    strtype& operator=(const strtype& other) {
        if (this == &other) {
            return *this;
        }

        delete[] str;
        length = other.length;
        str = new char[length + 1];
        strcpy(str, other.str);
        return *this;
    }

    bool operator<(const strtype& other) const {
        return strcmp(str, other.str) < 0;
    }

    bool operator>(const strtype& other) const {
        return strcmp(str, other.str) > 0;
    }

    bool operator==(const strtype& other) const {
        return strcmp(str, other.str) == 0;
    }

    void display() const {
        cout << str << endl;
    }
};

int main() {
    strtype str3;
    strtype str1("Hello");
    strtype str2("World");
    strtype result = str1 + str2;

    str1.display();
    str2.display();

    cout << "Concatenation: ";
    result.display();

    str3 = str1;
    cout << "Assigned: ";
    str3.display();

    if (str1 < str2) {
        cout << "str1 is less than str2." << endl;
    }
    if (str1 > str2) {
        cout << "str1 is greater than str2." << endl;
    }
    if (str1 == str3) {
        cout << "str1 is equal to str3." << endl;
    }

    return 0;
}
