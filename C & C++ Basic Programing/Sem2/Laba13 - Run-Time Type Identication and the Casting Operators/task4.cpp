#include <iostream>
#include <string>
using namespace std;

void f(const double &i) {   
    double &j = const_cast<double&>(i); // Знімаємо const, щоб змінити значення
    j = 100;
}

void g(const double &i) {
    double &j = const_cast<double&>(i);
    j = 42.0;
}

void print(const string &s) {
    string &hack = const_cast<string&>(s);
    hack += " hacked!";
    cout << s << endl;
}

int main() {
    cout << "--- Виправлена функція f() ---" << endl;
    double x = 98.6;
    cout << "До f(x): " << x << endl;
    f(x); 
    cout << "Після f(x): " << x << endl;

    cout << "\n--- Undefined Behavior з константою ---" << endl;
    const double y = 5.5;
    cout << "До g(y): " << y << endl;
    g(y);
    cout << "Після g(y): " << y << " (може бути непередбачувано)" << endl;

    cout << "\n--- Порушення інкапсуляції через print() ---" << endl;
    string name = "User";
    cout << "До print(name): " << name << endl;
    print(name);
    cout << "Після print(name): " << name << endl;

    return 0;
}
