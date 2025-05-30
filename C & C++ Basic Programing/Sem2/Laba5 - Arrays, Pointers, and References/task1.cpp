#include <iostream>
using namespace std;

const int SIZE = 10;

class letters {
    char ch;
public:
    letters() { ch = ' '; }
    letters(char c) { ch = c; }
    char get_ch() const { return ch; }
};

void fillArray(letters arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = letters('A' + i);
    }
}

void printArray(const letters arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i].get_ch() << " ";
    }
    cout << endl;
}

int main() {
    letters arr[SIZE];  

    fillArray(arr, SIZE);  
    printArray(arr, SIZE);  

    return 0;
}
