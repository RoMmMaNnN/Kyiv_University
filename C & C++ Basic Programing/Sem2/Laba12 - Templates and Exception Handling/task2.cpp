#include <iostream>
using namespace std;

template <class T>
int find(T object, T* list, int size) {
    for (int i = 0; i < size; i++) {
        if (list[i] == object) {
            return i;
        }
    }
    return -1;
}

int main() {
    int a[] = {3, 5, 7, 9};
    char b[] = {'a', 'b', 'c', 'd'};

    cout << "find(7, a, 4) = " << find(7, a, 4) << endl;
    cout << "find(4, a, 4) = " << find(4, a, 4) << endl;
    cout << "find('c', b, 4) = " << find('c', b, 4) << endl;
    cout << "find('x', b, 4) = " << find('x', b, 4) << endl;

    return 0;
}
