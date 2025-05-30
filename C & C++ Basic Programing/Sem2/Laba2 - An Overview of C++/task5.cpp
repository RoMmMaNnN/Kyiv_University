#include <iostream>
using namespace std;

#define SIZE 10

class queue_class {
private:
    int queue[SIZE];
    int head, tail;
public:
    queue_class() {
        head = 0;
        tail = 0;
    }

    void init() {
        head = 0;
        tail = 0;
    }

    void add_in_queue(int num) {
        if ((tail + 1) % SIZE == head) {
            cout << "Queue is full!" << endl;
            return;
        }
        queue[tail] = num;
        cout << "Added element: " << num << endl;  // Вивід доданого елемента
        tail = (tail + 1) % SIZE;
    }

    int remove_from_queue() {
        if (head == tail) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        int num = queue[head];
        head = (head + 1) % SIZE;
        return num;
    }

    bool isEmpty() {
        return head == tail;
    }

    void show_queue() {
        if (isEmpty()) {
            cout << "\nQueue is empty!" << endl;
            return;
        }
        cout << "\nQueue elements: ";
        int i = head;
        while (i != tail) {
            cout << queue[i] << " ";
            i = (i + 1) % SIZE;
        }
        cout << endl;
    }
};

int main() {
    queue_class q;
    q.init();

    q.add_in_queue(1);
    q.add_in_queue(2);
    q.add_in_queue(3);
    q.add_in_queue(4);
    q.add_in_queue(5);

    cout << "Current queue state:" << endl;
    q.show_queue();

    cout << "Dequeuing elements:" << endl;
    for (int i = 0; i < 5; i++) {
        cout << "\nDequeue: " << q.remove_from_queue() << endl;
    }

    cout << "\nTrying to add more elements:" << endl;
    q.add_in_queue(6);
    q.add_in_queue(7);

    cout << "\nCurrent queue state after additions:" << endl;
    q.show_queue();

    return 0;
}
