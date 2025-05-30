#include <iostream>
using namespace std;

class Dist {
    double distance;
public:
    Dist(double d) : distance(d) {}

    double getDistance() const {
        return distance;
    }

    virtual void trav_time() const {
        double time = distance / 60.0;
        cout << "miles: " << time << " hours" << endl;
    }

    virtual ~Dist() {}
};

class Metric : public Dist {
public:
    Metric(double d) : Dist(d) {}

    void trav_time() const override {
        double time = getDistance() / 100.0;
        cout << "kilometers: " << time << " hours" << endl;
    }
};

int main() {
    Dist* ptr;

    Dist d1(758.785);
    Metric m1(842.356);

    ptr = &d1;
    ptr->trav_time();

    ptr = &m1;
    ptr->trav_time();

    return 0;
}
