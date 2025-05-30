#include <iostream>
using namespace std;

class ft_to_cms {
    double feet;
    double cms;

public:
    ft_to_cms() : feet(0), cms(0) {}

    void input() {
        cout << "Enter length in feet (ft): ";
        cin >> feet;
        cms = feet * 30.48;
    }

    void display() {
        cout << feet << " ft = " << cms << " cm" << endl;
    }
};

int main() {
    ft_to_cms converter;
    converter.input();
    converter.display();
    return 0;
}
