#include <iostream>
#include <list>
#include <algorithm>
#include <cctype>

using namespace std;

class List {
public:
    virtual void store(int value) = 0;
    virtual int retrieve() = 0;
    virtual ~List() {}
};

class Queue : public List {
    list<int> q;
public:
    void store(int value) override {
        q.push_back(value);
    }

    int retrieve() override {
        int val = q.front();
        q.pop_front();
        return val;
    }
};

class Stack : public List {
    list<int> s;
public:
    void store(int value) override {
        s.push_back(value);
    }

    int retrieve() override {
        int val = s.back();
        s.pop_back();
        return val;
    }
};

class Sorted : public List {
    list<int> sorted_list;
public:
    void store(int value) override {
        sorted_list.push_back(value);
        sorted_list.sort();
    }

    int retrieve() override {
        int val = sorted_list.front();
        sorted_list.pop_front();
        return val;
    }
};

int main() {
    List* p;
    Queue qob;
    Stack sob;
    Sorted sorted_list;

    for (int i = 0; i < 5; i++) {
        p = &sob;
        p->store(i);

        p = &qob;
        p->store(i * 10);
    }

    cout << "Removing elements from Stack and Queue:\n";
    for (int i = 0; i < 5; i++) {
        p = &sob;
        cout << "From Stack: " << p->retrieve() << "\n";

        p = &qob;
        cout << "From Queue: " << p->retrieve() << "\n";
    }

    for (int i = 0; i < 5; i++) {
        p = &sorted_list;
        p->store(i * 2);
    }

    cout << "Retrieving elements from Sorted List:\n";
    for (int i = 0; i < 5; i++) {
        cout << "From Sorted List: " << sorted_list.retrieve() << "\n";
    }

    return 0;
}
