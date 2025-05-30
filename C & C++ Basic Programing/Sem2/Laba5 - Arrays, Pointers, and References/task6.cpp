#include <iostream>
using namespace std;

class Contact {
    string name;
    string phone;
public:
    void setName(const string& n) { name = n; }
    void setPhone(const string& p) { phone = p; }

    void display() const {
        cout << "Name: " << name << endl;
        cout << "Phone: " << phone << endl;
    }
};

int main() {
    Contact* contact = new Contact;

    string name = "Roman";
    string phone = "+380000000";

    contact->setName(name);
    contact->setPhone(phone);

    contact->display();

    delete contact;
    
    return 0;
}
