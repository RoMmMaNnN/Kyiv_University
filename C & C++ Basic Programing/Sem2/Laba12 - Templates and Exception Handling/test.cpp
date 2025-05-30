#include <iostream>
#include <string>
using namespace std;

class Animal
{
protected:
    string m_name;
    Animal(string name) : m_name(name) {}

public:
    string getName() { return m_name; }
    virtual const char* speak() { return "???"; }
};

class Cat : public Animal
{
public:
    Cat(string name) : Animal(name) {}
    virtual const char* speak() { return "Meow"; }
};

class Cat_1 : public Cat
{
public:
    Cat_1(string name) : Cat(name) {}
    const char* speak() { return "Mu"; }
};

class Dog : public Animal
{
public:
    Dog(string name) : Animal(name) {}
    const char* speak() { return "Woof"; }
};

void report(Animal& animal)
{
    cout << animal.getName() << " says " << animal.speak() << '\n';
}

class A {
public:
    virtual const char* getName() { return "A"; }
};

class B : public A {
public:
    virtual const char* getName() { return "B"; }
};

class C : public B {
public:
    virtual const char* getName() { return "C"; }
};


class D : public C {
public:
    virtual const char* getName() { return "D"; }
};

int main()
{
    Cat cat("Matros");
    Dog dog("Barsik");
    Cat_1 cat_1("British");

    report(cat);
    report(dog);
    report(cat_1);

    C c;

    A &parent = c;
    cout << "Parent is a " << parent.getName() << endl;

    return 0;
}
