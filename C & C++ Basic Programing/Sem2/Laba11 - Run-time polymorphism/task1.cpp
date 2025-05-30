#include <iostream>
#include <iomanip>
using namespace std;

ostream& scientific_upper(ostream& os) {
    return os << scientific << uppercase;
}

int main() {
    double num = 6446.12384;
    cout << scientific_upper << setprecision(10) << num << endl;
    return 0;
}