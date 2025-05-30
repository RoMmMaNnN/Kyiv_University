#include <iostream>
#include <string>

using namespace std;

class Airship {
protected:
    int passengers;
    double weight;
public:
    Airship(int passengers, double weight) : passengers(passengers), weight(weight) {}

    virtual void displayInfo() const {
        cout << "Passengers: " << passengers << endl;
        cout << "Weight: " << weight << " kg" << endl;
    }

    virtual ~Airship() {}
};

class Airplane : public Airship {
private:
    string engineType;
    double range;

public:
    Airplane(int passengers, double weight, const string& engineType, double range)
        : Airship(passengers, weight), engineType(engineType), range(range) {}

    void displayInfo() const override {
        Airship::displayInfo();
        cout << "Engine Type: " << engineType << endl;
        cout << "Flight Range: " << range << " km" << endl;
    }
};

class Balloon : public Airship {
private:
    string gasType;
    double maxHeight; 

public:
    Balloon(int passengers, double weight, const string& gasType, double maxHeight)
        : Airship(passengers, weight), gasType(gasType), maxHeight(maxHeight) {}

    void displayInfo() const override {
        Airship::displayInfo();
        cout << "Gas Type: " << gasType << endl;
        cout << "Max Height: " << maxHeight << " m" << endl;
    }
};

int main() {
    Airplane plane(180, 15000, "jet", 12000);
    Balloon balloon(4, 500, "helium", 3000);

    cout << "=== Airplane Info ===" << endl;
    plane.displayInfo();

    cout << "\n=== Balloon Info ===" << endl;
    balloon.displayInfo();

    return 0;
}
