#include <iostream>
#include <cstring>
#include <cstdlib>

class strtype {
    char str[80];
    int len;
public:
    strtype(const char* s) {
        strcpy(str, s);
        len = std::strlen(s);
    }

    operator char*() {
        return str;
    }

    int toInt() {
        return std::atoi(str);
    }

    int getLength() {
        return len;
    }
};

int main() {
    strtype s("12345");
    char* p = s;
    std::cout << "Here is string: " << p << '\n';

    char s2[80];
    std::strcpy(s2, s);
    std::cout << "Here is copy of string: " << s2 << '\n';

    int number = s.toInt();
    std::cout << "Converted to integer: " << number << '\n';

    std::cout << "String length: " << s.getLength() << '\n';

    return 0;
}
