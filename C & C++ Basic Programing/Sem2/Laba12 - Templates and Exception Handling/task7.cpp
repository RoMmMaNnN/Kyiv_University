#include <iostream>
using namespace std;

template <class T>
T sum(T* arr, int size) {
    T total = 0;
    for (int i = 0; i < size; i++) {
        total += arr[i];
    }
    return total;
}

int main() {
    int a[] = {1, 2, 3, 4, 5};
    double b[] = {1.5, 2.5, 3.5};

    cout << "Sum of int array: " << sum(a, 5) << endl;
    cout << "Sum of double array: " << sum(b, 3) << endl;

    return 0;
}
