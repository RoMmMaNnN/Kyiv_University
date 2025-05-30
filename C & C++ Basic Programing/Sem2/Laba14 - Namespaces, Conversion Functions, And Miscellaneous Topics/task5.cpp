#include <iostream>
using namespace std;

class Counter {
    static int count;
public:
    Counter() {
        count++;
        cout << "Constructor called. Current count: " << count << endl;
    }

    ~Counter() {
        count--;
        cout << "Destructor called. Current count: " << count << endl;
    }

    static int getCount() {
        return count;
    }
};

int Counter::count = 0;

int main() {
    cout << "Program start." << endl;
    Counter a;
    {
        Counter b, c;
        cout << "Inside block. Current count: " << Counter::getCount() << endl;
    }
    cout << "After block. Current count: " << Counter::getCount() << endl;

    Counter d;
    cout << "End of program. Current count: " << Counter::getCount() << endl;

    return 0;
}
