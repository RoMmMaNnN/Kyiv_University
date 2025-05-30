#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;

class account {
    int custnum;
    char name[80];
public:
    double balance;

    account(int c, const char* n, double b) {
        custnum = c;
        strcpy(name, n);
        balance = b;
    }

    void writeToFile(ofstream& fout) {
        fout << left << setw(5) << custnum
             << setw(25) << name
             << right << fixed << setprecision(2) << setw(12) << balance << endl;
    }
};

int main() {
    account acc1(1, "Petro Petrenko", 874.83);
    account acc2(2, "Ivan Ivanenko", 465461.80);
    account acc3(3, "Mikola Mikolenco", 7634.77);

    ofstream fout("accounts.txt");
    if (!fout) {
        cerr << "Failed to open file!" << endl;
        return 1;
    }

    fout << left << setw(5) << "ID"
         << setw(25) << "Name"
         << right << setw(12) << "Balance" << endl;
    fout << string(42, '-') << endl;

    acc1.writeToFile(fout);
    acc2.writeToFile(fout);
    acc3.writeToFile(fout);

    fout.close();
    return 0;
}
