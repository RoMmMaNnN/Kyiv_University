#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream fin("accounts2.txt");
    if (!fin) {
        cerr << "Cannot open file!" << endl;
        return 1;
    }

    string line;
    int lineNumber = 1;

    while (getline(fin, line)) {
        cout << lineNumber++ << ": " << line << endl;
    }

    fin.close();
    return 0;
}
