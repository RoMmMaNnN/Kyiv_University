#include <iostream>
#include <stdexcept>
using namespace std;

class dynarray {
    int *ptr;
    int size;
public:
    dynarray(int s) {
        size = s;
        ptr = new int[size];
        for (int i = 0; i < size; i++) {
            ptr[i] = 0;
        }
    }
    ~dynarray() {
        delete[] ptr;
    }

    int& operator[](int i) {
        if (i >= 0 && i < size) {
            return ptr[i];
        }
        throw out_of_range("Index out of bounds");
    }

    dynarray& operator=(const dynarray &obj) {
        if (this == &obj) return *this;
        delete[] ptr;
        size = obj.size;
        ptr = new int[size];
        for (int i = 0; i < size; i++) {
            ptr[i] = obj.ptr[i];
        }
        return *this;
    }
};

int main() {
    dynarray arr1(5);

    arr1[0] = 10;
    arr1[1] = 20;
    arr1[2] = 30;

    dynarray arr2(5);
    arr2 = arr1;

    cout << "arr1[0]: " << arr1[0] << endl;
    cout << "arr1[1]: " << arr1[1] << endl;
    cout << "arr1[2]: " << arr1[2] << endl;

    cout << "arr2[0]: " << arr2[0] << endl;
    cout << "arr2[1]: " << arr2[1] << endl;
    cout << "arr2[2]: " << arr2[2] << endl;

    try {
        arr1[5] = 99;
    } catch (const out_of_range& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}
