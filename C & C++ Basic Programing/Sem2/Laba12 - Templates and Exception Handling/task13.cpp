#include <iostream>
#include <cmath>

template <typename T>
T abs(T num) {
    return (num < 0) ? -num : num;
}

int main() {
    int intNum = -5;
    double doubleNum = -3.14;
    float floatNum = -2.71f;
    char a = 'a';

    std::cout << "Absolute value of int: " << abs(intNum) << std::endl;
    std::cout << "Absolute value of double: " << abs(doubleNum) << std::endl;
    std::cout << "Absolute value of float: " << abs(floatNum) << std::endl;
    std::cout << abs(a) << std::endl;

    return 0;
}
