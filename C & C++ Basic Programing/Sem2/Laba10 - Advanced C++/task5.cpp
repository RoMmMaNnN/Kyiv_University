#include <iostream>
#include <iomanip>
using namespace std;

ostream& sethex(ostream& out) {
    out << hex << showbase << uppercase;
    return out;
}

ostream& reset(ostream& out) {
    out << dec << nouppercase << noshowbase;
    return out;
}

int main() {
    int num = 255;

    cout << "Decimal: " << num << endl;
    cout << "Hex: " << sethex << num << endl;
    cout << "Back to decimal: " << reset << num << endl;

    return 0;
}
