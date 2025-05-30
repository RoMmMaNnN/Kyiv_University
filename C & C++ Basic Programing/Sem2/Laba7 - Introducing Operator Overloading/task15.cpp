#include <iostream>
using namespace std;

class coord {
    int x, y;
public:
    coord() : x(0), y(0) {}
    coord(int x_val, int y_val) : x(x_val), y(y_val) {}

    coord& operator<<(int i) {
        x <<= i;
        y <<= i;
        return *this;
    }

    coord& operator>>(int i) {
        x >>= i;
        y >>= i;
        return *this;
    }

    void show() const {
        cout << "x: " << x << ", y: " << y << endl;
    }
};

int main() {
    coord obj(10, 20);

    cout << "Initial values: ";
    obj.show();

    obj << 2;
    cout << "After << 2: ";
    obj.show();

    obj >> 1;
    cout << "After >> 1: ";
    obj.show();

    return 0;
}
