#include <iostream>
using namespace std;

#define SIZE 10

class stack {
    char stck[SIZE];
    int tos;

public:
    stack() { tos = 0; }

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

    friend ostream &operator<<(ostream &out, stack &stk) {
        if (stk.tos == 0) {
            out << "Stack is empty\n";
        } else {
            for (int i = stk.tos - 1; i >= 0; i--) {
                out << stk.stck[i] << " ";
            }
            out << endl;
        }
        return out;
    }
};

int main() {
    stack stk;
    stk.push('A');
    stk.push('B');
    stk.push('C');
    
    cout << "Stack contents: ";
    cout << stk;

    stk.pop();
    cout << "Stack after pop: ";
    cout << stk;

    return 0;
}
