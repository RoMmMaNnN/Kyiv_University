#include <iostream>
#include <iomanip>
using namespace std;

ostream& tabField(ostream& os) {
    os << "\t\t\t";
    os.width(20);
    return os;
}

int main() {
    cout << "hello" << tabField << "world" << endl;
    return 0;
}
