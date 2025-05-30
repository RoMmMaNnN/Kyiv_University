#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void swapPairs(string &s) {
    for (size_t i = 0; i + 1 < s.length(); i += 2) swap(s[i], s[i + 1]);
}

int main() {
    string input;
    cout << "Enter text to save in file: ";
    getline(cin, input);

    ofstream fout("text.txt");
    if (!fout) return 1;
    fout << input;
    fout.close();

    ifstream fin("text.txt");
    if (!fin) return 1;
    string content((istreambuf_iterator<char>(fin)), istreambuf_iterator<char>());
    fin.close();

    swapPairs(content);

    ofstream fout2("text.txt");
    fout2 << content;
    fout2.close();

    cout << "Modified content: " << content << endl;
    return 0;
}
