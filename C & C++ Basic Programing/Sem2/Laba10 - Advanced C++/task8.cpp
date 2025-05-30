#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ofstream fout("phones.txt");

    if (!fout) {
        cerr << "Cannot open file for writing!" << endl;
        return 1;
    }

    int n;
    cout << "How many contsct do you want to add? ";
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; ++i) {
        string firstName, lastName, phone;

        cout << "Enter first name: ";
        getline(cin, firstName);
        cout << "Enter last name: ";
        getline(cin, lastName);
        cout << "Enter phone number (+38XXXXXXXXXX): ";
        getline(cin, phone);

        fout << firstName << " " << lastName << ", " << phone << endl;
    }

    fout.close();
    cout << "Was saved to phones.txt" << endl;

    return 0;
}
