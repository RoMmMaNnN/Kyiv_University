#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream fin("text1.txt");
    ofstream fout("output.txt");

    if (!fin || !fout) {
        cerr << "File error\n";
        return 1;
    }

    char ch;
    int count = 0;
    while (fin.get(ch)) {
        fout.put(ch);
        count++;
    }

    cout << "Copied characters: " << count << endl;

    fin.close();
    fout.close();

    return 0;
}
