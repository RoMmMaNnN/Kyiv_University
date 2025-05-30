#include <iostream>
#include <string>
using namespace std;

template <class T>
class Input {
    T value;
public:
    Input(const string& prompt, T min_val, T max_val) {
        while (true) {
            cout << prompt;
            cin >> value;
            if (cin.fail() || value < min_val || value > max_val) {
                cin.clear();
                cin.ignore(1000, '\n');
                continue;
            }
            break;
        }
    }

    T get() {
        return value;
    }
};

int main() {
    Input<int> a("Enter an integer (1-10): ", 1, 10);
    cout << "You entered: " << a.get() << endl;

    Input<double> b("Enter a double (0.0 - 5.5): ", 0.0, 5.5);
    cout << "You entered: " << b.get() << endl;

    return 0;
}
