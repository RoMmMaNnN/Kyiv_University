#include <iostream>
#include <stdexcept>
using namespace std;

const int SIZE = 100;

template <class T1, class T2>
class Stack {
    pair<T1, T2> stck[SIZE];
    int tos;

public:
    Stack() { tos = 0; }

    void push(T1 a, T2 b) {
        if (tos == SIZE)
            throw overflow_error("Stack overflow");
        stck[tos++] = make_pair(a, b);
    }

    pair<T1, T2> pop() {
        if (tos == 0)
            throw underflow_error("Stack underflow");
        return stck[--tos];
    }

    bool isEmpty() {
        return tos == 0;
    }
};

int main() {
    Stack<int, string> s;

    try {
        s.push(1, "one");
        s.push(2, "two");
        s.push(3, "three");

        while (true) {
            auto p = s.pop();
            cout << "(" << p.first << ", " << p.second << ")\n";
        }
    }
    catch (const exception& e) {
        cerr << "Exception: " << e.what() << endl;
    }

    return 0;
}
