#include <iostream>
#include <stdexcept>
using namespace std;

double divide(double a, double b) {
    if (b == 0) {
        throw runtime_error("Division by zero error");
    }
    return a / b;
}

int main() {
    try {
        double x, y;
        cout << "Enter numerator: ";
        cin >> x;
        cout << "Enter denominator: ";
        cin >> y;

        double result = divide(x, y);
        cout << "Result: " << result << endl;
    } catch (const exception& e) {
        cout << "Exception caught: " << e.what() << endl;
    }

    return 0;
}
