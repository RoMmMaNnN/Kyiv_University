#include <iostream>
#include <fstream>

using namespace std;

int countWords(const string& text) {
    int count = 0;
    bool inWord = false;

    for (char ch : text) {
        if (ch != ' ' && ch != '\n' && ch != '\t') {
            if (!inWord) {
                inWord = true;
                ++count;
            }
        } else {
            inWord = false;
        }
    }

    return count;
}

int main() {
    ifstream fin("text1.txt");
    if (!fin) {
        cerr << "Cannot open input.txt!" << endl;
        return 1;
    }

    string line;
    int totalWords = 0;

    while (getline(fin, line)) {
        totalWords += countWords(line);
    }

    fin.close();

    cout << "Total words: " << totalWords << endl;
    return 0;
}
