#include <iostream>
using namespace std;

class date {
    char d[9]; // mm/dd/yy
public:
    friend istream& operator>>(istream& in, date& dt);
    friend ostream& operator<<(ostream& out, const date& dt);
};

istream& operator>>(istream& in, date& dt) {
    cout << "Enter date (mm/dd/yy): ";
    in >> dt.d;
    return in;
}

ostream& operator<<(ostream& out, const date& dt) {
    out << "Date: " << dt.d;
    return out;
}

int main() {
    date today;
    cin >> today;
    cout << today << endl;
    return 0;
}
