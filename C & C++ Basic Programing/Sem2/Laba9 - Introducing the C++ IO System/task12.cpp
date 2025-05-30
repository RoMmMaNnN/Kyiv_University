#include <iostream>

using namespace std;

class DivisorInfo {
    int number;
    int largestDivisor;

    int findLargestDivisor(int n) {
        for (int i = n / 2; i >= 1; --i) {
            if (n % i == 0) return i;
        }
        return 1;
    }

public:
    DivisorInfo(int n = 1) {
        number = n;
        largestDivisor = findLargestDivisor(n);
    }

    friend istream& operator>>(istream& in, DivisorInfo& obj) {
        in >> obj.number;
        obj.largestDivisor = obj.findLargestDivisor(obj.number);
        return in;
    }

    friend ostream& operator<<(ostream& out, const DivisorInfo& obj) {
        out << "Number: " << obj.number << ", Largest Divisor: " << obj.largestDivisor;
        return out;
    }
};

int main() {
    DivisorInfo d;
    cout << "Enter int: ";
    cin >> d;
    cout << d << endl;
    return 0;
}
