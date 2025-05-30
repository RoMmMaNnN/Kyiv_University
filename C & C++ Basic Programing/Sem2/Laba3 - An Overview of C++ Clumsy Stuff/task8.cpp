#include <iostream>
using namespace std;

#define SIZE 10

class stack {
private:
    char stck[SIZE];
    int tos;

public:
    stack() {
        tos = 0;
    }

    void push(char ch) {
        if (tos == SIZE) {
            cout << "Stack is full\n";
            return;
        }
        stck[tos] = ch;
        tos++;
    }

    char pop() {
        if (tos == 0) {
            cout << "Stack is empty\n";
            return 0;
        }
        tos--;
        return stck[tos];
    }

    void showstack() const {
        if (tos == 0) {
            cout << "Stack is empty\n";
            return;
        }
        cout << "Stack content: ";
        for (int i = 0; i < tos; i++) {
            cout << stck[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    stack s1, s2;

    s1.push('a');
    s1.push('b');
    s1.push('c');
    s2.push('x');
    s2.push('y');
    s2.push('z');

    cout << "Initial stack s1: ";
    s1.showstack();

    s2 = s1;

    cout << "Stack s2 after cloning: ";
    s2.showstack();

    for (int i = 0; i < 3; i++) {
        cout << "Pop from s1: " << s1.pop() << "\n";
    }
    cout << "Stack s1 after popping elements: ";
    s1.showstack();

    for (int i = 0; i < 3; i++) {
        cout << "Pop from s2: " << s2.pop() << "\n";
    }
    cout << "Stack s2 after popping elements: ";
    s2.showstack();

    return 0;
}
