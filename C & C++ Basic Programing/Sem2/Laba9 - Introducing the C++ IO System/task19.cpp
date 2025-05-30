#include <iostream>
using namespace std;

class box {
    int size;

public:
    box(int s) : size(s) {}
    void draw() {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (i == 0 && j == 0) {
                    cout << "┌";
                } else if (i == 0 && j == size - 1) {
                    cout << "┐";
                } else if (i == size - 1 && j == 0) {
                    cout << "└";
                } else if (i == size - 1 && j == size - 1) {
                    cout << "┘";
                } else if (i == 0 || i == size - 1) {
                    cout << "──";
                } else if (j == 0 || j == size - 1) {
                    cout << "│";
                } else if (i > 0 && i < size - 1 && j > 0 && j < size - 1) {
                    cout << "  ";
                }
            }
            cout << endl;
        }
    }
};

int main() {
    box b(7);
    b.draw();
    return 0;
}
