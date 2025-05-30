#include <iostream>
using namespace std;

int& getSafeRef() {
    static int temp = 33;
    return temp;
}

int main() {
    int &ref = getSafeRef();
    ref = 77;

    cout << getSafeRef() << endl;

    return 0;
}