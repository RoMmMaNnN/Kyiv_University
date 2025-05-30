#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

#define SIZE 40

class inventory {
    char item[SIZE]; 
    int onhand;      
    double cost;     

public:
    inventory() {
        strcpy(item, "");
        onhand = 0;
        cost = 0.0;
    }

    inventory(const char* i, int o, double c) {
        strncpy(item, i, SIZE);
        item[SIZE - 1] = '\0';
        onhand = o;
        cost = c;
    }

    void store(fstream &stream) {
        stream.write((char*)this, sizeof(*this));
    }

    void retrieve(fstream &stream, int record_number) {
        stream.seekg(record_number * sizeof(*this), ios::beg);
        stream.read((char*)this, sizeof(*this));
    }

    friend ostream& operator<<(ostream &stream, const inventory &obj);
    friend istream& operator>>(istream &stream, inventory &obj);
};

ostream& operator<<(ostream &stream, const inventory &obj) {
    stream << obj.item << ": " << obj.onhand << " on hand at $" << obj.cost << "\n";
    return stream;
}

istream& operator>>(istream &stream, inventory &obj) {
    cout << "Enter item name: ";
    stream >> ws;
    stream.getline(obj.item, SIZE);
    cout << "Enter number on hand: ";
    stream >> obj.onhand;
    cout << "Enter cost: ";
    stream >> obj.cost;
    return stream;
}

int main() {
    const char* filename = "inventory.dat";

    fstream fout(filename, ios::out | ios::binary);
    if (!fout) {
        cerr << "Cannot open file for writing.\n";
        return 1;
    }

    inventory inv1("Sword", 11, 777.00);
    inventory inv2("Pickaxe", 7, 999.57);
    inventory inv3("Axe", 3, 9999.99);

    inv1.store(fout);
    inv2.store(fout);
    inv3.store(fout);

    fout.close();

    fstream fin(filename, ios::in | ios::binary);
    if (!fin) {
        cerr << "Cannot open file for reading.\n";
        return 1;
    }

    int record_number;
    cout << "Enter record number to retrieve: ";
    cin >> record_number;

    inventory retrieved;
    retrieved.retrieve(fin, record_number);
    cout << "Retrieved record:\n" << retrieved;

    fin.close();
    return 0;
}
