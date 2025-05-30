#include <iostream>

using namespace std;

class building {
protected:
    int floors;
    int rooms;
    double area;
public:
    building(int f, int r, double a) : floors(f), rooms(r), area(a) {}

    void showBuildingInfo() {
        cout << "Number of floors: " << floors << endl;
        cout << "Number of rooms: " << rooms << endl;
        cout << "Total area: " << area << " square meters" << endl;
    }
};

class house : public building {
private:
    int bathrooms;
    int bedrooms;
public:
    house(int f, int r, double a, int b, int be) : building(f, r, a), bathrooms(b), bedrooms(be) {}

    void showHouseInfo() {
        showBuildingInfo();
        cout << "Number of bathrooms: " << bathrooms << endl;
        cout << "Number of bedrooms: " << bedrooms << endl;
    }
};

class office : public building {
private:
    int fireExtinguishers;
    int phones;

public:
    office(int f, int r, double a, int fe, int p) : building(f, r, a), fireExtinguishers(fe), phones(p) {}

    void showOfficeInfo() {
        showBuildingInfo();
        cout << "Number of fire extinguishers: " << fireExtinguishers << endl;
        cout << "Number of phones: " << phones << endl;
    }
};

int main() {
    // Створення об'єкта класу house
    house myHouse(3, 10, 200.5, 2, 3);
    cout << "House Info:" << endl;
    myHouse.showHouseInfo();
    cout << endl;

    // Створення об'єкта класу office
    office myOffice(5, 50, 800.75, 5, 20);
    cout << "Office Info:" << endl;
    myOffice.showOfficeInfo();
    
    return 0;
}
