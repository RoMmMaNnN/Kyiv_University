#include <iostream>
using namespace std;

template <typename T>
class coord {
    T x, y;
public:
    coord() {
        x = 0;
        y = 0;
        cout << "Constructing default.\n";
    }

    coord(T i, T j) {
        x = i;
        y = j;
        cout << "Constructing with values.\n";
    }

    void get_xy(T &i, T &j) {
        i = x;
        j = y;
    }

    coord operator+(const coord &obj) {
        return coord(x + obj.x, y + obj.y);
    }

    ~coord() {
        cout << "Destructing.\n";
    }
};

int main() {
    coord<int> obj1(10, 10), obj2(5, 3), obj3;
    int x, y;

    obj3 = obj1 + obj2;
    obj3.get_xy(x, y);

    cout << "(obj1 + obj2) X: " << x << ", Y: " << y << "\n";

    return 0;
}
