#include <iostream>
using namespace std;

class dynarray {
    int *ptr;
    int size;
public:
    dynarray(int s) {
        size = s;
        ptr = new int[size];
        for (int i = 0; i < size; i++)
            ptr[i] = 0;
    }

    ~dynarray() {
        delete[] ptr;
    }

    int &put(int i) {
        if (i >= 0 && i < size)
            return ptr[i];
        throw out_of_range("Index out of bounds");
    }

    int get(int i) {
        if (i >= 0 && i < size)
            return ptr[i];
        throw out_of_range("Index out of bounds");
    }

    dynarray& operator=(const dynarray &obj) {
        if (this == &obj) return *this;

        delete[] ptr;
        size = obj.size;
        ptr = new int[size];

        for (int i = 0; i < size; i++)
            ptr[i] = obj.ptr[i];

        return *this;
    }
};

int main() {
    dynarray arr1(5);
    arr1.put(0) = 10;
    arr1.put(1) = 20;

    dynarray arr2(5);
    arr2 = arr1;

    cout << "arr1[0]: " << arr1.get(0) << endl;
    cout << "arr1[1]: " << arr1.get(1) << endl;
    cout << "arr2[0]: " << arr2.get(0) << endl;
    cout << "arr2[1]: " << arr2.get(1) << endl;

    return 0;
}
