#include <iostream>
#include <cstring>

using namespace std;

class strtype {
    char str[80];
    int len;
public:
    strtype(const char *s) {
        strcpy(str, s);
        len = strlen(s);
    }
    operator const char*() const {  // const, бо не змінює об'єкт
        return str;
    }
    int length() const {  // гетер — const
        return len;
    }
};

class Pwr {
    int base, exp;
public:
    Pwr(int b, int e) : base(b), exp(e) {}
    operator int() const {  // const, бо метод лише читає дані
        int result = 1;
        for (int i = 0; i < exp; i++)
            result *= base;
        return result;
    }
};

class Counter {
    static int count;
public:
    Counter() { count++; }
    ~Counter() { count--; }
    static int getCount() {  // static, бо не залежить від об'єкта
        return count;
    }
};

int Counter::count = 0;

int main() {
    strtype s("Hello");
    cout << "String: " << s << ", length: " << s.length() << "\n";

    Pwr power(2, 10);
    cout << "2^10 = " << int(power) << "\n";

    cout << "Objects before creating: " << Counter::getCount() << "\n";
    Counter c1, c2;
    cout << "Objects after creating: " << Counter::getCount() << "\n";
    
    Counter c3;
    cout << "Objects inside block: " << Counter::getCount() << "\n";

    cout << "Objects after block: " << Counter::getCount() << "\n";

    return 0;
}
