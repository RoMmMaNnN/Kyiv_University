#include <iostream>
using namespace std;

class samp {
    int a;
public:
    void set_a(int n) { a = n; }
    int get_a() { return a; }
};

int main() {
    samp obj[4][2];

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 2; j++) {
            (*(obj[i] + j)).set_a(i * 2 + j);
        }
    }

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 2; j++) {
            cout << (*(obj[i] + j)).get_a() << " ";
        }
        cout << endl;
    }

    return 0;
}
