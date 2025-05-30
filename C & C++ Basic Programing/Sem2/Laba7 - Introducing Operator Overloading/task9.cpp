#include <iostream>
using namespace std;

class coord {
    int x, y;
public:
    coord() { x = 0; y = 0; }
    coord(int i, int j) { x = i; y = j; }

    void get_xy(int &i, int &j) { i = x; j = y; }

    coord operator++() {
        x++;
        y++;
        return *this;
    }

    coord operator++(int notused) {
        coord temp = *this;
        x++;
        y++;
        return temp;
    }

    coord operator-() {
        x = -x;
        y = -y;
        return *this;
    }

    coord operator-(const coord &obj) {
        coord temp;
        temp.x = x - obj.x;
        temp.y = y - obj.y;
        return temp;
    }
};

int main() {
    coord obj1(10, 10), obj2(5, 3), obj3;

    int x, y;

    obj1++;
    obj1.get_xy(x, y);
    cout << "(obj1++) X: " << x << ", Y: " << y << "\n";

    ++obj2;
    obj2.get_xy(x, y);
    cout << "(++obj2) X: " << x << ", Y: " << y << "\n";

    obj3 = obj1 - obj2;
    obj3.get_xy(x, y);
    cout << "(obj1 - obj2) X: " << x << ", Y: " << y << "\n";

    coord obj4 = -obj1;
    obj4.get_xy(x, y);
    cout << "(-obj1) X: " << x << ", Y: " << y << "\n";

    return 0;
}
