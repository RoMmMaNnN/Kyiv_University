#include <iostream>
using namespace std;

class coord {
    int x, y;
public:
    coord() { x = 0; y = 0; }
    coord(int i, int j) { x = i; y = j; }
    
    void get_xy(int &i, int &j) { i = x; j = y; }
    
    coord operator++();
    coord operator++(int);
    
    coord operator-();
    
    friend coord operator*(const coord &obj, int val);
    friend coord operator*(int val, const coord &obj);
    
    friend coord operator-(const coord &obj1, const coord &obj2);
};

coord coord::operator++() {
    x++;
    y++;
    return *this;
}

coord coord::operator++(int notused) {
    coord temp = *this;
    x++;
    y++;
    return temp;
}

coord coord::operator-() {
    x = -x;
    y = -y;
    return *this;
}

coord operator*(const coord &obj, int val) {
    return coord(obj.x * val, obj.y * val);
}

coord operator*(int val, const coord &obj) {
    return coord(obj.x * val, obj.y * val);
}

coord operator-(const coord &obj1, const coord &obj2) {
    return coord(obj1.x - obj2.x, obj1.y - obj2.y);
}

int main() {
    coord obj1(10, 10), obj2(5, 3), obj3(10, 10), obj4(0, 0);
    int x, y;

    obj1.get_xy(x, y);
    cout << "(obj1) X: " << x << ", Y: " << y << "\n";

    obj2.get_xy(x, y);
    cout << "(obj2) X: " << x << ", Y: " << y << "\n";

    obj3 = obj1 * 2;
    obj3.get_xy(x, y);
    cout << "(obj1 * 2) X: " << x << ", Y: " << y << "\n";

    obj3 = 2 * obj1;
    obj3.get_xy(x, y);
    cout << "(2 * obj1) X: " << x << ", Y: " << y << "\n";

    obj3 = obj1 - obj2;
    obj3.get_xy(x, y);
    cout << "(obj1 - obj2) X: " << x << ", Y: " << y << "\n";

    obj3 = -obj1;
    obj3.get_xy(x, y);
    cout << "(-obj1) X: " << x << ", Y: " << y << "\n";

    ++obj1;
    obj1.get_xy(x, y);
    cout << "(++obj1) X: " << x << ", Y: " << y << "\n";

    obj1++;
    obj1.get_xy(x, y);
    cout << "(obj1++) X: " << x << ", Y: " << y << "\n";

    return 0;
}
