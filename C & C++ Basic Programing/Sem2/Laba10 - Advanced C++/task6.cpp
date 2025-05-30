#include <iostream>
#include <string>
using namespace std;

istream& skipchar1(istream& in) {
    string input;
    getline(in, input);
    for (size_t i = 0; i < input.size(); i++) {
        if ((i / 5) % 2 == 0) // read 5, skip 5
            cout << input[i];
    }
    return in;
}

istream& skipchar2(istream& in) {
    string input;
    getline(in, input);
    for (size_t i = 0; i < input.size(); i++) {
        if ((i / 4) % 2 == 1) // skip 4, then read 4
            cout << input[i];
    }
    return in;
}

int main() {
    cout << "Enter text for skipchar1:" << endl;
    skipchar1(cin);

    cout << "\nEnter text for skipchar2:" << endl;
    skipchar2(cin);

    return 0;
}
