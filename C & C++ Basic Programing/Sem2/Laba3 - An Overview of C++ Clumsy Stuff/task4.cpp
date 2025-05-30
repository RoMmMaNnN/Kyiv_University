#include <iostream>

using namespace std;

void testRecursion(int n) {
    if (n > 0) {
        testRecursion(n - 1);
    } else cout << "testRecursion passed" << endl;
}

void testStaticVariable() {
    static int count = 0;
    count++;
    cout << "Static variable count: " << count << endl;
}

void testLoop() {
    for (int i = 0; i < 5; i++) {
        cout << "Iteration: " << i << endl;
    }
}

void testSwitch(int x) {
    switch (x) {
        case 1:
            cout << "x = 1" << endl;
            break;
        case 2:
            cout << "x = 2" << endl;
            break;
        default:
            cout << "x = ?" << endl;
            break;
    }
}

int main() {
    cout << "Testing recursion: " << endl;
    testRecursion(10000);

    cout << "\nTesting static variable: " << endl;
    for(int i = 0; i < 5; ++i) {
        testStaticVariable();
    }

    cout << "\nTesting loop: " << endl;
    testLoop();

    cout << "\nTesting switch statement: " << endl;
    for(int i = 1; i < 5; i++) {
        testSwitch(i);
    }

    return 0;
}
