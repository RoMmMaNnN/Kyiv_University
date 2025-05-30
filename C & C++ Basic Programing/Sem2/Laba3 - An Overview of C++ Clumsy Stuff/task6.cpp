#include <iostream>
    
using namespace std;

#define SIZE 10

class stack {
private:
    char stck[SIZE];
    int tos;

public:
    stack() : tos(0) {}

    void init() {
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

    bool isEmpty() {
        return tos == 0;
    }

    bool isFull() {
        return tos == SIZE;
    }
};

int main() {
    stack s1, s2;

    s1.init();
    s2.init();

    s1.push('a');
    s2.push('x');
    s1.push('b');
    s2.push('y');
    s1.push('c');
    s2.push('z');

    cout << "Pop s1: " << s1.pop() << "\n";
    cout << "Pop s1: " << s1.pop() << "\n";
    cout << "Pop s1: " << s1.pop() << "\n";
    cout << "Pop s2: " << s2.pop() << "\n";
    cout << "Pop s2: " << s2.pop() << "\n";
    cout << "Pop s2: " << s2.pop() << "\n";

    return 0;
}
