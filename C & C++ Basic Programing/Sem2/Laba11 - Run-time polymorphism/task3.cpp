#include <iostream>
#include <fstream>
using namespace std;

bool isSeparator(char ch) {
    return ch == ' ' || ch == '\n' || ch == '\t';
}

int countWordOccurrences(const string& fileName, const string& targetWord) {
    ifstream inputFile(fileName);
    if (!inputFile) {
        cerr << "Error open file" << endl;
        return -1;
    }

    int count = 0;
    string currentWord;
    char ch;

    while (inputFile.get(ch)) {
        if (!isSeparator(ch)) {
            currentWord += ch;
        } else {
            if (!currentWord.empty() && currentWord == targetWord) {
                count++;
            }
            currentWord.clear();
        }
    }
    if (!currentWord.empty() && currentWord == targetWord) {
        count++;
    }

    return count;
}

int main(int argc, char* argv[]) {
    string fileName = argv[1];
    string targetWord = argv[2];

    int occurrences = countWordOccurrences(fileName, targetWord);

    if (occurrences >= 0) {
        cout << "word was counted " << occurrences << " times" << endl;
    }

    return 0;
}
