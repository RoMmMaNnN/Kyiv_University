#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
    char str[100];

    cout << "Enter a number with decimal point: ";
    cin >> str;

    double num = atof(str); // перетворення рядка у double

    cout << "Converted number: " << num << endl;

    return 0;
}
