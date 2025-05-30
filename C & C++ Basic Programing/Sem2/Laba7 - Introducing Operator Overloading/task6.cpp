#include <iostream>
using namespace std;

class coord {
    int x, y;
public:
    coord() { x = 0; y = 0; }
    coord(int i, int j) { x = i; y = j; }

    void get_xy(int &i, int &j) { i = x; j = y; }

    coord operator+(const coord &obj) {
        return coord(x + obj.x, y + obj.y);
    }

    coord operator+() {
        if (x < 0) x = -x;
        if (y < 0) y = -y;
        return *this;
    }
};

int main() {
    coord obj1(10, -5), obj2(5, 3), obj3;

    obj3 = obj1 + obj2;
    int x, y;
    obj3.get_xy(x, y);
    cout << "(obj1 + obj2) X: " << x << ", Y: " << y << "\n";

    +obj1;
    obj1.get_xy(x, y);
    cout << "(+obj1) X: " << x << ", Y: " << y << "\n";

    return 0;
}
