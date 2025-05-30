#include <iostream>
#include <cstdlib>
using namespace std;

class list {
public:
    list* head;
    list* tail;
    list* next;
    int num;

    list() : head(NULL), tail(NULL), next(NULL), num(0) {}

    virtual void store(int i) = 0;
    virtual int retrieve() = 0;
    virtual list& operator+(int i) = 0;
    virtual list& operator-(int& i) = 0;
    virtual ~list() {
    }
};

class queue : public list {
public:
    void store(int i) override {
        queue* item = new queue;
        if (!item) {
            cout << "Allocation error.\n";
            exit(1);
        }
        item->num = i;
        item->next = NULL;

        if (tail) {
            tail->next = item;
        }
        tail = item;

        if (!head) {
            head = item;
        }
    }

    int retrieve() override {
        if (!head) {
            cout << "List empty.\n";
            return -1;
        }

        list* p = head;
        int i = head->num;
        head = head->next;
        if (!head) {
            tail = NULL;
        }
        delete p;
        return i;
    }
    list& operator+(int i) override {
        store(i);
        return *this;
    }
    list& operator-(int& i) override {
        i = retrieve();
        return *this;
    }
};

class stack : public list {
public:
    void store(int i) override {
        stack* item = new stack;
        if (!item) {
            cout << "Allocation error.\n";
            exit(1);
        }
        item->num = i;
        item->next = head;
        head = item;
        if (!tail) {
            tail = item;
        }
    }

    int retrieve() override {
        if (!head) {
            cout << "List empty.\n";
            return -1;
        }

        list* p = head;
        int i = head->num;
        head = head->next;
        delete p;
        if (!head) {
            tail = NULL;
        }
        return i;
    }

    list& operator+(int i) override {
        store(i);
        return *this;
    }

    list& operator-(int& i) override {
        i = retrieve();
        return *this;
    }
};

int main() {
    list* p;

    queue q_ob;
    p = &q_ob;
    *p + 1; 
    *p + 2;
    *p + 3;

    cout << "Queue: ";
    int val;
    *p - val;
    cout << val << " ";
    *p - val;
    cout << val << " ";
    *p - val;
    cout << val << " ";
    cout << '\n';

    stack s_ob;
    p = &s_ob;
    *p + 1; 
    *p + 2;
    *p + 3;

    cout << "Stack: ";
    *p - val
    cout << val << " ";
    *p - val;
    cout << val << " ";
    *p - val;
    cout << val << " ";
    cout << '\n';

    return 0;
}
