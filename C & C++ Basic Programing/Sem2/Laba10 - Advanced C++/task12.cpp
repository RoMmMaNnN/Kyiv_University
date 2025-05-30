#include <iostream>
#include <fstream>
#include <iomanip>
#include <limits>
using namespace std;

class account {
    int custnum;
    char name[80];
    double balance;
public:
    void readData() {
        while (true) {
            cout << "Enter customer number: ";
            if (cin >> custnum) break;
            else {
                cout << "Invalid input. Try again.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Enter name: ";
        int i = 0;
        char ch;
        while (i < 79 && cin.get(ch) && ch != '\n') {
            name[i++] = ch;
        }
        name[i] = '\0';
        while (true) {
            cout << "Enter balance: ";
            if (cin >> balance) break;
            else {
                cout << "Invalid input. Try again.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    void writeToFile(ofstream& fout) {
        fout << left << setw(5) << custnum
             << setw(25) << name
             << right << fixed << setprecision(2) << setw(12) << balance << endl;
    }
};

int main() {
    account acc[3];

    for (int i = 0; i < 3; ++i) {
        cout << "\nAccount " << i + 1 << ":\n";
        acc[i].readData();
    }

    ofstream fout("accounts2.txt");
    if (!fout) {
        cerr << "File error!" << endl;
        return 1;
    }

    fout << left << setw(5) << "ID"
         << setw(25) << "Name"
         << right << setw(12) << "Balance" << endl;
    fout << string(42, '-') << endl;

    for (int i = 0; i < 3; ++i)
        acc[i].writeToFile(fout);

    fout.close();
    return 0;
}
