#include <iostream>
#include <cmath>

using namespace std;

class Area {
public:
    double height;
    double width;

    Area(double h, double w) : height(h), width(w) {}

    virtual double area() const = 0;
};

class Rectangle : public Area {
public:
    Rectangle(double h, double w) : Area(h, w) {}

    double area() const override {
        return height * width;
    }
};

class Isosceles : public Area {
public:
    double side;

    Isosceles(double h, double w, double s) : Area(h, w), side(s) {}

    double calculateHeight() const {
        return sqrt(side * side - (width / 2) * (width / 2));
    }

    double area() const override {
        double h = calculateHeight();
        return 0.5 * width * h;
    }
};

class Cylinder : public Area {
public:
    Cylinder(double h, double d) : Area(h, d) {}

    double area() const override {
        double r = width / 2;
        return 2 * M_PI * r * r + M_PI * width * height;
    }
};

int main() {
    Rectangle rect(24, 7);
    Isosceles iso(0, 12, 10);
    Cylinder cyl(15, 48);

    cout << "Rectangle area: " << rect.area() << endl;
    cout << "Isosceles area: " << iso.area() << endl;
    cout << "Cylinder surface area: " << cyl.area() << endl;

    return 0;
}
