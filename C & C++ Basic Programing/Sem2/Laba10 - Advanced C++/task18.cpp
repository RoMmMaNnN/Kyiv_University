#include <iostream>
#include <cctype>
using namespace std;

istream& findalpha(istream& is) {
    char ch;
    while (is.get(ch)) {
        if (isalpha(static_cast<unsigned char>(ch))) {
            is.putback(ch);
            break;
        }
    }
    return is;
}

int main() {
    char c;

    cout << "Enter chars: ";
    cin >> findalpha >> c;

    cout << "First char is alfa: " << c << endl;

    return 0;
}
