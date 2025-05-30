#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

class strtype {
    char *p;
    int len;
public:
    strtype(const char *ptr = "") {
        len = strlen(ptr) + 1;
        p = new char[len];
        if (!p) {
            cout << "Allocation error\n";
            exit(1);
        }
        strcpy(p, ptr);
    }

    ~strtype() {
        delete[] p;
    }

    friend ostream &operator<<(ostream &stream, const strtype &obj) {
        stream << obj.p;
        return stream;
    }

    friend istream &operator>>(istream &stream, strtype &obj) {
        char temp[256];
        stream.getline(temp, 256);
        delete[] obj.p;
        obj.len = strlen(temp) + 1;
        obj.p = new char[obj.len];
        if (!obj.p) {
            cout << "Allocation error\n";
            exit(1);
        }
        strcpy(obj.p, temp);
        return stream;
    }
};

int main() {
    strtype s1, s2;
    cout << "Enter first string: ";
    cin >> s1;
    cout << "Enter second string: ";
    cin >> s2;

    cout << "\nYou entered:\n";
    cout << s1 << '\n' << s2 << endl;

    return 0;
}
