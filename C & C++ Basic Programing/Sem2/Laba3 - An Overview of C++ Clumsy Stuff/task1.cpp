#include <iostream>
#include <cstring>
using namespace std;

enum color { red, yellow, green, orange };

const char* c[] = { "red", "yellow", "green", "orange" };

class Fruit {
public:
    bool annual;
    bool perennial;
    bool tree;
    bool tropical;
    enum color clr;
    char name[40];

    Fruit() { annual = perennial = tree = tropical = false; }
};

class Apple : public Fruit {
    bool cooking;
    bool crunchy;
    bool eating;
public:
    void seta(const char* n, enum color c, bool ck, bool crchy, bool e);
    void seta(const char* n, enum color c, const char* ck, const char* crchy, const char* e);
    void show();
};

class Orange : public Fruit {
    bool juice;
    bool sour;
    bool eating;
public:
    void seto(const char* n, enum color c, bool j, bool sr, bool e);
    void seto(const char* n, enum color c, const char* j, const char* sr, const char* e);
    void show();
};

void out(bool x) {
    cout << (x ? "yes" : "no") << "\n";
}

bool strToBool(const char* s) {
    return (strcmp(s, "yes") == 0);
}

void Apple::seta(const char* n, enum color c, bool ck, bool crchy, bool e) {
    strcpy(name, n);
    annual = false;
    perennial = true;
    tree = true;
    tropical = false;
    clr = c;
    cooking = ck;
    crunchy = crchy;
    eating = e;
}

void Apple::seta(const char* n, enum color c, const char* ck, const char* crchy, const char* e) {
    seta(n, c, strToBool(ck), strToBool(crchy), strToBool(e));
}

void Orange::seto(const char* n, enum color c, bool j, bool sr, bool e) {
    strcpy(name, n);
    annual = false;
    perennial = true;
    tree = true;
    tropical = true;
    clr = c;
    juice = j;
    sour = sr;
    eating = e;
}

void Orange::seto(const char* n, enum color c, const char* j, const char* sr, const char* e) {
    seto(n, c, strToBool(j), strToBool(sr), strToBool(e));
}

void Apple::show() {
    cout << "\n\n" << name << " apple is:\n";
    cout << "Annual: "; out(annual);
    cout << "Perennial: "; out(perennial);
    cout << "Tree: "; out(tree);
    cout << "Tropical: "; out(tropical);
    cout << "Color: " << c[clr] << "\n";
    cout << "Good for cooking: "; out(cooking);
    cout << "Crunchy: "; out(crunchy);
    cout << "Good for eating: "; out(eating);
}

void Orange::show() {
    cout << "\n\n" << name << " orange is:\n";
    cout << "Annual: "; out(annual);
    cout << "Perennial: "; out(perennial);
    cout << "Tree: "; out(tree);
    cout << "Tropical: "; out(tropical);
    cout << "Color: " << c[clr] << "\n";
    cout << "Good for juice: "; out(juice);
    cout << "Sour: "; out(sour);
    cout << "Good for eating: "; out(eating);
}

int main() {
    Apple a1, a2;
    Orange o1, o2;

    a1.seta("Golden", yellow, "yes", "no", "yes");
    o1.seto("Blood Orange", orange, "no", "yes", "yes");
    a2.seta("Jonathan", red, true, false, true);
    o2.seto("Valencia", orange, true, true, false);

    a1.show();
    o1.show();    
    a2.show();
    o2.show();

    return 0;
}
