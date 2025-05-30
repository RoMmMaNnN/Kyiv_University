#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int num = 100;
    cout << setiosflags(ios::hex) << setiosflags(ios::showbase);
    cout << num << endl;
    return 0;
}
