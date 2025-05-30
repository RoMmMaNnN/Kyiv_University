#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ofstream out("input.txt", ios::binary);

    if (!out) {
        cerr << "Failed to open file for writing." << endl;
        return 1;
    }

    out.seekp(80, ios::beg);
    out << " :) (: =) ";

    out.close();

    ifstream in("input.txt", ios::binary | ios::ate);
    if (!in) {
        cerr << "Failed to open file for reading." << endl;
        return 1;
    }

    streampos size = in.tellg();
    cout << "File size after writing: " << size << " bytes." << endl;

    in.close();
    return 0;
}
