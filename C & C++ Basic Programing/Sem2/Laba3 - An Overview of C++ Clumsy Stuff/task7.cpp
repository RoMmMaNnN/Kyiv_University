#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Dice {
private:
    int value;

public:
    Dice() : value(0) {}

    void roll() {
        value = rand() % 6 + 1;
    }

    void display() const {
        cout << value << " ";
    }
};

int main() {
    Dice dice1, dice2, dice3, dice4;

    srand(time(0));

    for (int i = 0; i < 5; i++) {
        cout << "Throw " << i + 1 << ": ";
        dice1.roll();
        dice2.roll();
        dice3.roll();
        dice4.roll();
        
        dice1.display();
        dice2.display();
        dice3.display();
        dice4.display();
        
        cout << endl;
    }

    return 0;
}
