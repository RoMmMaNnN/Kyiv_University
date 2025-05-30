#include <iostream>
using namespace std;

class coord {
    int x, y;
public:
    coord() { x = 0; y = 0; }
    coord(int i, int j) { x = i; y = j; }
    
    void get_xy(int &i, int &j) { i = x; j = y; }
    
    int operator==(const coord &obj) { 
        return x == obj.x && y == obj.y; 
    }

    int operator&&(const coord &obj) { 
        return (x && obj.x) && (y && obj.y); 
    }

    coord operator-(const coord &obj) {
        return coord(x - obj.x, y - obj.y);
    }

    coord operator--() {
        x--;
        y--;
        return *this;
    }

    coord operator--(int) {
        coord temp = *this;
        x--;
        y--;
        return temp;
    }
};

int main() {
    int x, y;
    coord obj1(10, 10), obj2(5, 3), obj3(10, 10), obj4(0, 0);

    if (obj1 == obj2)
        cout << "obj1 is the same as obj2\n";
    else
        cout << "obj1 and obj2 differ\n";
    
    if (obj1 == obj3)
        cout << "obj1 is the same as obj3\n";
    else
        cout << "obj1 and obj3 differ\n";
    
    if (obj1 && obj2)
        cout << "obj1 && obj2 is true\n";
    else
        cout << "obj1 && obj2 is false\n";
    
    if (obj1 && obj4)
        cout << "obj1 && obj4 is true\n";
    else
        cout << "obj1 && obj4 is false\n";

    coord obj5 = obj1 - obj2;
    obj5.get_xy(x, y);
    cout << "obj1 - obj2: X: " << x << ", Y: " << y << "\n";

    --obj1;
    obj1.get_xy(x, y);
    cout << "After pre-decrement obj1: X: " << x << ", Y: " << y << "\n";

    obj1--;
    obj1.get_xy(x, y);
    cout << "After post-decrement obj1: X: " << x << ", Y: " << y << "\n";

    return 0;
}
