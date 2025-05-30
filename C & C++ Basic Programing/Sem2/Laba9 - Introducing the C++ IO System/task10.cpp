#include <iostream>
using namespace std;

class planet {
protected:
    double distance;
    int revolve;

public:
    planet(double d, int r) {
        distance = d;
        revolve = r;
    }

    friend ostream& operator<<(ostream& out, const planet& obj) {
        out << "Distance from Sun: " << obj.distance << " miles\n";
        out << "Days in orbit: " << obj.revolve << " days\n";
        return out;
    }
};

class earth : public planet {
private:
    double circumference;

public:
    earth(double d, int r) : planet(d, r) {
        circumference = 2 * distance * 3.1416;
    }

    friend ostream& operator<<(ostream& out, const earth& obj) {
        out << static_cast<const planet&>(obj);
        out << "Circumference of orbit: " << obj.circumference << " miles\n";
        return out;
    }
};

int main() {
    earth obj(93000000, 365);
    cout << obj;
    return 0;
}
