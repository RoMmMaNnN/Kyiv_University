#include <iostream>
using namespace std;

const int SIZE = 100;

template <class T1, class T2>
class Stack {
    pair<T1, T2> stck[SIZE];
    int tos;

public:
    Stack() { tos = 0; }

    void push(T1 a, T2 b) {
        if (tos == SIZE) {
            cout << "Stack is full.\n";
            return;
        }
        stck[tos] = make_pair(a, b);
        tos++;
    }

    pair<T1, T2> pop() {
        if (tos == 0) {
            cout << "Stack is empty.\n";
            return pair<T1, T2>();
        }
        tos--;
        return stck[tos];
    }

    bool isEmpty() {
        return tos == 0;
    }
};

int main() {
    Stack<int, string> s;

    s.push(1, "one");
    s.push(2, "two");
    s.push(3, "three");

    while (!s.isEmpty()) {
        pair<int, string> p = s.pop();
        cout << "(" << p.first << ", " << p.second << ")\n";
    }

    return 0;
}
