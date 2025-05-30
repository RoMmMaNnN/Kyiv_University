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

    bool operator==(const three_d& obj) const {
        return (x == obj.x && y == obj.y && z == obj.z);
    }

    bool operator!=(const three_d& obj) const {
        return !(*this == obj);
    }

    bool operator||(const three_d& obj) {
        return (x || y || z) || (obj.x || obj.y || obj.z);
    }

    three_d operator+(int val) {
        return three_d(x + val, y + val, z + val);
    }

    friend three_d operator+(int val, const three_d& obj) {
        return three_d(obj.x + val, obj.y + val, obj.z + val);
    }
};

int main() {
    int x, y, z;
    three_d obj1(1, 2, 3), obj2(4, 5, 6), result;

    obj1.show();
    obj2.show();

    result = obj1 + obj2;
    
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

    if (obj1 == obj2)
        cout << "obj1 is equal to obj2.\n";
    else
        cout << "obj1 is not equal to obj2.\n";

    if (obj1 != obj2)
        cout << "obj1 is not equal to obj2.\n";
    else
        cout << "obj1 is equal to obj2.\n";

    if (obj1 || obj2)
        cout << "At least one object has non-zero values.\n";

    result = obj1 + 5;
    result.get(x, y, z);
    cout << "obj1 + 5: (" << x << ", " << y << ", " << z << ")\n";

    result = 5 + obj2;
    result.get(x, y, z);
    cout << "5 + obj2: (" << x << ", " << y << ", " << z << ")\n";

    return 0;
}
