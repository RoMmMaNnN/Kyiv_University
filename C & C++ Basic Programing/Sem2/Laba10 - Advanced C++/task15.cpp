#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

void reverseWholeFile() {
    ifstream fin("text.txt");
    if (!fin) {
        cerr << "Error opening file!" << endl;
        return;
    }

    string content((istreambuf_iterator<char>(fin)), istreambuf_iterator<char>());
    fin.close();

    reverse(content.begin(), content.end());
    cout << "Version 1: Reverse entire file contents:\n" << content << endl;
}

void reverseEachLine() { 
    ifstream fin("text.txt");
    if (!fin) {
        cerr << "Error opening file!" << endl;
        return;
    }

    string line;
    cout << "Version 2: Reverse each line individually:\n";
    while (getline(fin, line)) {
        reverse(line.begin(), line.end());
        cout << line << endl;
    }

    fin.close();
}

int main() {
    reverseWholeFile();
    reverseEachLine();
    return 0;
}
