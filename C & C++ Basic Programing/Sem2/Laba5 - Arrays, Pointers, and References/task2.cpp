#include <iostream>
using namespace std;

const int SIZE = 10;

class squares {
    int num, sqr;
public:
    squares() { num = 0; sqr = 0; }
    squares(int a) { num = a; sqr = a * a; }
    int get_num() const { return num; }
    int get_sqr() const { return sqr; }
};

void fillArray(squares arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = squares(i + 1);
    }
}

void printArray(const squares arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i].get_num() << " << " << arr[i].get_sqr() << endl;
    }
}

int main() {
    squares arr[SIZE];

    fillArray(arr, SIZE);
    printArray(arr, SIZE);

    return 0;
}
