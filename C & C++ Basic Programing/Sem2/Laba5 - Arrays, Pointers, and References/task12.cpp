#include <iostream>
#include <cstdlib>

using namespace std;

class SafeArray {
    int rows, cols;
    int** arr;
public:
    SafeArray(int r, int c) {
        rows = r;
        cols = c;
        arr = new int*[rows];
        for (int i = 0; i < rows; i++) {
            arr[i] = new int[cols];
        }
    }

    ~SafeArray() {
        for (int i = 0; i < rows; i++) {
            delete[] arr[i];
        }
        delete[] arr;
    }

    int& at(int r, int c) {
        if (r < 0 || r >= rows || c < 0 || c >= cols) {
            cout << "Bounds error!\n";
            exit(1);
        }
        return arr[r][c];
    }

    void display() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    SafeArray arr(2, 3);

    arr.at(0, 0) = 1;
    arr.at(0, 1) = 2;
    arr.at(0, 2) = 3;
    arr.at(1, 0) = 4;
    arr.at(1, 1) = 5;
    arr.at(1, 2) = 6;

    arr.display();
    
    arr.at(1, 3) = 7;

    return 0;
}
