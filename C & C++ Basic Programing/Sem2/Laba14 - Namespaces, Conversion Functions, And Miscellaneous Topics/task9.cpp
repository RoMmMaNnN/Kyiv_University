#include <iostream>
using namespace std;

class MyArray {
    int arr[10];
public:
    // Ввід значень у масив
    friend istream& operator>>(istream& in, MyArray& obj) {
        for (int i = 0; i < 10; i++) {
            in >> obj.arr[i];
        }
        return in;
    }

    // Вивід значень масиву
    friend ostream& operator<<(ostream& out, const MyArray& obj) {
        for (int i = 0; i < 10; i++) {
            out << obj.arr[i] << " ";
        }
        return out;
    }

    // Копіювання значень з іншого масиву
    void copyFrom(const MyArray& other) {
        for (int i = 0; i < 10; i++) {
            arr[i] = other.arr[i];
        }
    }
};

int main() {
    MyArray a1, a2;

    cout << "Enter 10 integers for the first array:\n";
    cin >> a1;

    a2.copyFrom(a1); // Копіювання з a1 в a2

    cout << "Contents of the second array after copying:\n";
    cout << a2 << endl;

    return 0;
}
