#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Shape {
public:
    virtual void example() = 0;
    virtual ~Shape() {}
};

class Rectangle : public Shape {
public:
    void example() override {
        cout << "*****\n*****\n";
    }
};

class Triangle : public Shape {
public:
    void example() override {
        cout << "  *  \n * * \n*****\n";
    }
};

class Line : public Shape {
public:
    void example() override {
        cout << "******\n";
    }
};

class NullShape : public Shape {
public:
    void example() override {
    }
};

Shape* generator() {
    switch (rand() % 4) {
        case 0: return new Line;
        case 1: return new Rectangle;
        case 2: return new Triangle;
        case 3: return new NullShape;
    }
    return nullptr;
}

int main() {
    srand(static_cast<unsigned>(time(0)));

    for (int i = 0; i < 10; i++) {
        Shape* p = generator();
        if (dynamic_cast<NullShape*>(p) == nullptr) {
            p->example();
        }
        delete p;
    }

    return 0;
}
