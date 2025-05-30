#include <iostream>
#include <fstream>
using namespace std;

bool isWordChar(char ch) {
    return ch != ' ' && ch != '\n' && ch != '\t';
}

int main() {
    ifstream fin("text1.txt", ios::binary);
    ofstream fout("output.txt", ios::binary);

    if (!fin || !fout) {
        cerr << "File error\n";
        return 1;
    }

    const int bufferSize = 1024;
    char buffer[bufferSize];
    int copiedChars = 0;
    int wordCount = 0;
    bool inWord = false;

    while (!fin.eof()) {
        fin.read(buffer, bufferSize);
        streamsize bytesRead = fin.gcount();
        fout.write(buffer, bytesRead);
        copiedChars += bytesRead;

        for (int i = 0; i < bytesRead; ++i) {
            if (isWordChar(buffer[i])) {
                if (!inWord) {
                    inWord = true;
                    ++wordCount;
                }
            } else {
                inWord = false;
            }
        }
    }

    fin.close();
    fout.close();

    cout << "Copied characters: " << copiedChars << endl;
    cout << "Total words: " << wordCount << endl;

    return 0;
}
