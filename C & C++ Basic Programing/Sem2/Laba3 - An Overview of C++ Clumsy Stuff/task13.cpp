#include <iostream>
#include <cstring>

using namespace std;

#define SIZE 26

class stack {
private:
    char stck[SIZE];
    int tos;

public:
    stack() : tos(0) {}

    bool is_full() const {
        return tos == SIZE;
    }

    bool is_empty() const {
    return tos == 0;
    }

    void push(char ch) {
        if (is_full()) {
            cout << "Stack is full!" << endl;
            return;
        }
        stck[tos++] = ch;
    }

    char pop() {
        if (is_empty()) {
            cout << "Stack is empty!" << endl;
            return '\0';
        }
        return stck[--tos];
    }

    void display() const {
        for (int i = 0; i < tos; ++i) {
            cout << stck[i] << ", ";
        }
        cout << endl;
    }

    void loadstack(int upper_case = 0) {
        char start_char = (upper_case == 1) ? 'A' : 'a';
        for (int i = 0; i < SIZE; ++i) {
            push(start_char + i);
        }
    }

    stack clone() const {
        stack clone_stack;
        for (int i = 0; i < tos; ++i) {
            clone_stack.push(stck[i]);
        }
        return clone_stack;
    }
};

int main() {
    stack s1, s2, s3;
    s1.loadstack();
    cout << "\n(lowercase)\nStack s1: ";
    s1.display();

    s2 = s1.clone();
    cout << "\n(lowercase clone)\nStack s2: ";
    s2.display();

    s3.loadstack(1);
    cout << "\n(uppercase)\nStack s3: ";
    s3.display();

    return 0;
}
