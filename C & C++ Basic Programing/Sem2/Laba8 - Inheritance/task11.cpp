#include <iostream>
using namespace std;

enum motor {gas, electric, diesel};
enum steering {power, rack_pin, manual};   

class vehicle {
    int num_wheels;
    int range;
public:
    vehicle(int w, int r) : num_wheels(w), range(r) {}
    void showv() {
        cout << "Wheels: " << num_wheels << endl;
        cout << "Range: " << range << endl;
    }
};

class motorized : virtual public vehicle {
    motor mtr;
public:
    motorized(motor m, int w, int r) : vehicle(w, r), mtr(m) {}
    void showm() {
        cout << "Motor: ";
        switch (mtr) {
            case gas:
                cout << "Gas" << endl;
                break;
            case electric:
                cout << "Electric" << endl;
                break;
            case diesel:
                cout << "Diesel" << endl;
                break;
        }
    }
};

class road_use : virtual public vehicle {
    int passengers;
public:
    road_use(int p, int w, int r) : vehicle(w, r), passengers(p) {}
    void showr() {
        cout << "Passengers: " << passengers << endl;
    }
};

class car : public motorized, public road_use {
    steering strng;
public:
    car(steering s, motor m, int w, int r, int p) : 
        vehicle(w, r), motorized(m, w, r), road_use(p, w, r), strng(s) {}
    
    void show() {
        vehicle::showv();
        showr();
        showm();
        cout << "Steering: ";
        switch (strng) {
            case power:
                cout << "Power" << endl;
                break;
            case rack_pin:
                cout << "Rack and Pinion" << endl;
                break;
            case manual:
                cout << "Manual" << endl;
                break;
        }
    }
};

int main() {
    car c(power, gas, 4, 500, 5);
    c.show();
    return 0;
}
