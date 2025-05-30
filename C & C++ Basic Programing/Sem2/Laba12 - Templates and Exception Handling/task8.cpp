#include <iostream>
using namespace std;

template <class T>
class Sorter {
    T* arr;
    int size;

public:
    Sorter(T* a, int s) {
        arr = a;
        size = s;
    }

    void bubbleSort() {
        for (int i = 0; i < size - 1; i++) {
            for (int j = 0; j < size - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    T temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }

    void print() {
        for (int i = 0; i < size; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    int a[] = {5, 2, 9, 1, 5, 6};
    double b[] = {3.3, 1.1, 5.5, 2.2};

    Sorter<int> s1(a, 6);
    Sorter<double> s2(b, 4);

    s1.bubbleSort();
    s2.bubbleSort();

    cout << "Sorted int array: ";
    s1.print();

    cout << "Sorted double array: ";
    s2.print();

    return 0;
}
