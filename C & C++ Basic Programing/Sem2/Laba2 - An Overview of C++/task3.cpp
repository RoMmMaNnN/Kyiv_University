#include <iostream>
using namespace std;

int main() {
    int a, b, d, min;

    cout << "Enter two numbers: ";
    cin >> a >> b;
    min = (a < b) ? a : b;
    for (d = min; d <= a * b; d++) {
        if (d % a == 0 && d % b == 0) break;
    }
    if (d == a * b) {
        cout << "No common denominators\n";
    } else cout << "The lowest common denominator is " << d << endl;

    return 0;
}
