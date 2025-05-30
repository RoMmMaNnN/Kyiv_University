#include <iostream>
using namespace std;

class coord {
    int x, y;
public:
    coord() { x = 0; y = 0; }
    coord(int i, int j) { x = i; y = j; }
    void get_xy(int &i, int &j) { i = x; j = y; }

    void operator+(const coord &obj);
    int operator-(const coord &obj);
    coord& operator*(const coord &obj);
    double operator/(const coord &obj);
};

void coord::operator+(const coord &obj) {
    cout << "Sum: (" << x + obj.x << ", " << y + obj.y << ")\n";
}

int coord::operator-(const coord &obj) {
    return x - obj.x + y - obj.y;
}

coord& coord::operator*(const coord &obj) {
    coord temp(x * obj.x, y * obj.y);
    return temp;
}

double coord::operator/(const coord &obj) {
    return (obj.x != 0 && obj.y != 0) ? (double)x / obj.x + (double)y / obj.y : 0;
}

int main() {
    coord obj1(10, 7), obj2(3, 2), obj3;

    obj3 = obj1 + obj2;
    obj3 = obj1 - obj2;
    obj3 = obj1 * obj2;
    obj3 = obj1 / obj2;

    return 0;
}
