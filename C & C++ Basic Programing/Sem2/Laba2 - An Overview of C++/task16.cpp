#include <iostream>

using namespace std;

class stack {
private:
    char* stck;
    int tos;
    int size;

public:
    stack(int s) {
        size = s;
        stck = new char[size];
        tos = 0;
        cout << "Constructing a stack of size " << size << endl;
    }

    ~stack() {
        delete[] stck;
        cout << "Destroying a stack\n";
    }

    void push(char ch) {
        if (tos == size) {
            cout << "Stack is full\n";
        } else {
            stck[tos] = ch;
            tos++;
        }
    }

    char pop() {
        if (tos == 0) {
            cout << "Stack is empty\n";
            return '\0';
        } else {
            tos--;
            return stck[tos];
        }
    }
};

int main() {
    stack s1(5), s2(3);

    s1.push('a');
    s2.push('x');
    s1.push('b');
    s2.push('y');
    s1.push('c');
    s2.push('z');

    for (int i = 0; i < 3; i++) {
        cout << "Pop s1: " << s1.pop() << endl;
    }

    for (int i = 0; i < 3; i++) {
        cout << "Pop s2: " << s2.pop() << endl;
    }

    return 0;
}
