#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int num = 100;
    double value = 1000.5364;

    cout << dec << num << endl;
    cout << showbase << hex << num << endl;
    cout << showbase << oct << num << endl;

    cout << left << setfill('*') << setw(20)
         << fixed << setprecision(2) << value << endl;

    return 0;
}
