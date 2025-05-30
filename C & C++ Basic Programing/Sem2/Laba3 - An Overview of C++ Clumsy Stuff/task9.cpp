#include <iostream>
using namespace std;

class who {
private:
    char who_is;

public:
    who(char x) : who_is(x) {
        cout << "Constructing who #" << who_is << endl;
    }

    ~who() {
        cout << "Destroying who #" << who_is << endl;
    }
};

who make_who(char x) {
    who obj(x);
    return obj;
}

int main() {
    who w1('D');
    cout << "Calling make_who() with 'C'" << endl;
    who w2 = make_who('C');
    cout << "--------------------------" << endl;
    return 0;
}
