#include <iostream>
using namespace std;

class coord {
    int x, y;
public:
    coord() { x = 0; y = 0; }
    coord(int i, int j) { x = i; y = j; }
    void get_xy(int &i, int &j) { i = x; j = y; }

    coord operator+(const coord &obj);
    coord operator-(const coord &obj);
    coord operator*(const coord &obj);
    coord operator/(const coord &obj);
    coord operator%(const coord &obj);
    
    void display(const string &label) {
        cout << label << " X: " << x << ", Y: " << y << "\n";
    }
};

coord coord::operator+(const coord &obj) {
    return coord(x + obj.x, y + obj.y);
}

coord coord::operator-(const coord &obj) {
    return coord(x - obj.x, y - obj.y);
}

coord coord::operator*(const coord &obj) {
    return coord(x * obj.x, y * obj.y);
}

coord coord::operator/(const coord &obj) {
    return coord(obj.x != 0 ? x / obj.x : 0, obj.y != 0 ? y / obj.y : 0);
}

coord coord::operator%(const coord &obj) {
    return coord(obj.x != 0 ? x % obj.x : 0, obj.y != 0 ? y % obj.y : 0);
}

int main() {
    coord obj1(10, 7), obj2(3, 2), obj3;
    
    obj1.display("obj1");
    obj2.display("obj2");

    obj3 = obj1 + obj2;
    obj3.display("(obj1 + obj2)");

    obj3 = obj1 - obj2;
    obj3.display("(obj1 - obj2)");

    obj3 = obj1 * obj2;
    obj3.display("(obj1 * obj2)");

    obj3 = obj1 / obj2;
    obj3.display("(obj1 / obj2)");

    obj3 = obj1 % obj2;
    obj3.display("(obj1 % obj2)");

    return 0;
}
