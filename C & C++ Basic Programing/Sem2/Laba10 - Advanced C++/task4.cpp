#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

ostream& tdm(ostream& out) {
    time_t now = time(0);
    tm* localTime = localtime(&now);
    out << put_time(localTime, "%Y-%m-%d %H:%M:%S");
    return out;
}

int main() {
    cout << "Current date and time: " << tdm << endl;
    return 0;
}
