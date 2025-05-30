#include <iostream>
using namespace std;

class CountDown {
    int iner;
    int target;
    int current;
public:
    CountDown(int delay, int i = 1) {
        target = delay;
        iner = i;
        current = 0;
    }

    bool counting() { // цф функція не працює з константними змінами
        current += iner;
        if (current >= target) {
            cout << "\a";
            cout << "Time's up!\n";
            return false;
        }
        cout << current << " ";
        return true;
    }
};

int main() {
    CountDown obj(100, 2);
    while (obj.counting());
    return 0;
}
