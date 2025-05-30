#include <iostream>

using namespace std;

char min(char a, char b);
int min(int a, int b);
double min(double a, double b);

int main() {
    cout << "Min of 'a' and 'b': " << min('a', 'b') << endl;
    cout << "Min of -3 and 7: " << min(-3, 70) << endl;
    cout << "Min of 1461.16737 and 164613.4896: " << min(1461.16737, 164613.4896) << endl;

    return 0;
}

char min(char a, char b) {
    return (a < b) ? a : b;
}

int min(int a, int b) {
    return (a < b) ? a : b;
}

double min(double a, double b) {
    return (a < b) ? a : b;
}
