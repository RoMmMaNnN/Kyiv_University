#include <iostream>
using namespace std;

class three_d {
    int x, y, z;
public:
    three_d(int i, int j, int k) { x = i; y = j; z = k; }
    three_d() { x = 0; y = 0; z = 0; }
    void get(int &i, int &j, int &k) { i = x; j = y; k = z; }

    void show() {
        cout << "Obj (" << x << "," << y << "," << z << ")\n";
    }

    three_d operator+(const three_d& obj) {
        return three_d(x + obj.x, y + obj.y, z + obj.z);
    }

    three_d operator-(const three_d& obj) {
        return three_d(x - obj.x, y - obj.y, z - obj.z);
    }

    three_d operator++() {
        x++;
        y++;
        z++;
        return *this;
    }

    three_d operator--() {
        x--;
        y--;
        z--;
        return *this;
    }
};

int main() {
    three_d obj1(1, 2, 3), obj2(4, 5, 6), result;

    obj1.show();
    obj2.show();

    result = obj1 + obj2;
    int x, y, z;
    result.get(x, y, z);
    cout << "obj1 + obj2: (" << x << ", " << y << ", " << z << ")\n";
    result = obj1 - obj2;
    result.get(x, y, z);
    cout << "obj1 - obj2: (" << x << ", " << y << ", " << z << ")\n";

    ++obj1;
    obj1.get(x, y, z);
    cout << "obj1 after increment: (" << x << ", " << y << ", " << z << ")\n";

    --obj2;
    obj2.get(x, y, z);
    cout << "obj2 after decrement: (" << x << ", " << y << ", " << z << ")\n";

    return 0;
}
