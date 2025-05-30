#include <iostream>

class Pwr {
    int base;
    int exp;
public:
    Pwr(int b, int e) {
        base = b;
        exp = e;
    }

    operator int() {
        int result = 1;
        for (int i = 0; i < exp; ++i)
            result *= base;
        return result;
    }
};

int main() {
    Pwr p(7, 7);
    int result = p;

    std::cout << "Result of base^exp: " << result << '\n';

    return 0;
}
