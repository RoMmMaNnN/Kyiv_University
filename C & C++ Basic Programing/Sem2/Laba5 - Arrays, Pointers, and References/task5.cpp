#include <iostream>
using namespace std;

int main() {
    float* f = new float;
    long* l = new long;
    char* c = new char;

    *f = 7.69f;
    *l = 15121L;
    *c = '$';

    cout << "Float: " << *f << endl;
    cout << "Long: " << *l << endl;
    cout << "Char: " << *c << endl;

    delete f;
    delete l;
    delete c;

    return 0;
}
