#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

class DataStruct {
public:
    virtual void push(int val) = 0;
    virtual int pop() = 0;
    virtual bool is_empty() const = 0;
    virtual ~DataStruct() {}
};

class Stack : public DataStruct {
private:
    vector<int> data;
public:
    void push(int val) override {
        data.push_back(val);
    }

    int pop() override {
        if (data.empty()) throw underflow_error("Stack is empty");
        int val = data.back();
        data.pop_back();
        return val;
    }

    bool is_empty() const override {
        return data.empty();
    }
};

class Queue : public DataStruct {
private:
    vector<int> data;
public:
    void push(int val) override {
        data.push_back(val);
    }

    int pop() override {
        if (data.empty()) throw underflow_error("Queue is empty");
        int val = data.front();
        data.erase(data.begin());
        return val;
    }

    bool is_empty() const override {
        return data.empty();
    }
};

DataStruct* DataStructFactory(char what) {
    if (what == 's') return new Stack();
    if (what == 'q') return new Queue();
    return nullptr;
}

int main() {
    char choice;
    cout << "Enter 's' for Stack or 'q' for Queue: ";
    cin >> choice;

    DataStruct* ds = DataStructFactory(choice);
    if (!ds) {
        cout << "Invalid choice.\n";
        return 1;
    }

    ds->push(10);
    ds->push(20);
    ds->push(30);

    while (!ds->is_empty()) {
        cout << ds->pop() << " ";
    }
    cout << endl;

    delete ds;
    return 0;
}
