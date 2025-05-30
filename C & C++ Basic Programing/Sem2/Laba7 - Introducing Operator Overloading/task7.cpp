#include <iostream>
using namespace std;

class coord {
    int x, y;
public:
    coord() { x = 0; y = 0; }
    coord(int i, int j) { x = i; y = j; }
    void get_xy(int &i, int &j) { i = x; j = y; }
    friend coord operator-(coord obj);
    friend coord operator-(const coord &obj1, const coord &obj2);
    friend coord operator/(const coord &obj1, const coord &obj2);
    friend coord operator++(coord &obj);
    friend coord operator++(coord &obj, int notused);
};

coord operator-(coord obj) {
    obj.x = -obj.x;
    obj.y = -obj.y;
    return obj;
}

coord operator-(const coord &obj1, const coord &obj2) {
    return coord(obj1.x - obj2.x, obj1.y - obj2.y);
}

coord operator/(const coord &obj1, const coord &obj2) {
    if (obj2.x != 0 && obj2.y != 0)
        return coord(obj1.x / obj2.x, obj1.y / obj2.y);
    else
        return coord(0, 0);
}

coord operator++(coord &obj) {
    obj.x++;
    obj.y++;
    return obj;
}

coord operator++(coord &obj, int notused) {
    coord temp = obj;
    obj.x++;
    obj.y++;
    return temp;
}

int main() {
    coord obj1(10, 10), obj2(5, 7), obj3(0, 0);
    int x, y;

    obj3 = obj1 - obj2;
    obj3.get_xy(x, y);
    cout << "(obj1 - obj2) X: " << x << ", Y: " << y << "\n";

    obj3 = -obj1;
    obj3.get_xy(x, y);
    cout << "(-obj1) X: " << x << ", Y: " << y << "\n";

    obj3 = obj1 / obj2;
    obj3.get_xy(x, y);
    cout << "(obj1 / obj2) X: " << x << ", Y: " << y << "\n";

    ++obj1;
    obj1.get_xy(x, y);
    cout << "(++obj1) X: " << x << ", Y: " << y << "\n";

    obj1++;
    obj1.get_xy(x, y);
    cout << "(obj1++) X: " << x << ", Y: " << y << "\n";

    return 0;
}
