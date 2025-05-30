#include <iostream>
#include <cstdlib>
using namespace std;

class array {
    int size;
    char *p;
public:
    array(int num) {
        size = num;
        p = new char[size];
        cout << "Array created with size: " << size << endl;
    }

    ~array() {
        cout << "Array destroyed." << endl;
        delete[] p;
    }

    char &operator[](int i) {
        if (i < 0 || i >= size) {
            cout << "Index out of bounds: " << i << endl;
            exit(1);
        }
        return p[i];
    }
};

int main() {
    array arr(2);

    arr[0] = '1';
    arr[1] = '2';
    cout << "arr[0]: " << arr[0] << ", arr[1]: " << arr[1] << endl;

    arr[45] = 'w';
    arr[2] = '0';

    return 0;
}
