#include <iostream>
using namespace std;

#define SIZE 5

template <class T>
class Stack {
    T stck[SIZE];
    int tos;
public:
    Stack() : tos(-1) {}

    void push(T obj) {
        if (tos < SIZE - 1) {
            stck[++tos] = obj;
        } else {
            cout << "Stack overflow!" << endl;
        }
    }

    T pop() {
        if (tos >= 0) {
            return stck[tos--];
        } else {
            cout << "Stack underflow!" << endl;
            return T();
        }
    }

    bool isEmpty() {
        return tos == -1;
    }

    void display() {
        for (int i = tos; i >= 0; i--) {
            cout << stck[i] << " ";
        }
        cout << endl;
    }
};

template <class T>
class Queue {
    T queue[SIZE];
    int front, rear;
public:
    Queue() : front(0), rear(0) {}

    void enqueue(T obj) {
        if (rear < SIZE) {
            queue[rear++] = obj;
        } else {
            cout << "Queue is full!" << endl;
        }
    }

    T dequeue() {
        if (front < rear) {
            return queue[front++];
        } else {
            cout << "Queue is empty!" << endl;
            return T();
        }
    }

    bool isEmpty() {
        return front == rear;
    }

    void display() {
        for (int i = front; i < rear; i++) {
            cout << queue[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Stack<int> intStack;
    Queue<int> intQueue;

    intStack.push(10);
    intStack.push(20);
    intStack.push(30);

    cout << "Stack contents: ";
    intStack.display();

    cout << "Popped element: " << intStack.pop() << endl;

    cout << "Stack contents after pop: ";
    intStack.display();

    intQueue.enqueue(100);
    intQueue.enqueue(200);
    intQueue.enqueue(300);

    cout << "Queue contents: ";
    intQueue.display();

    cout << "Dequeued element: " << intQueue.dequeue() << endl;

    cout << "Queue contents after dequeue: ";
    intQueue.display();

    return 0;
}
