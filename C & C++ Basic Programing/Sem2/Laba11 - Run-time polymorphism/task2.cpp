#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool copyFileWithTabReplacement(const string& inputFileName, const string& outputFileName) {
    ifstream inputFile(inputFileName);
    ofstream outputFile(outputFileName);

    if (!inputFile || !outputFile) {
        cerr << "Не вдалося відкрити файли." << endl;
        return false;
    }

    string line;
    while (getline(inputFile, line)) {
        for (char ch : line) {
            if (ch == '\t') {
                outputFile << "    "; // 4 пробіли
            } else {
                outputFile << ch;
            }
        }
        outputFile << '\n';
    }

    return true;
}

void displayInputFileWithReplacement(const string& inputFileName) {
    ifstream inputFile(inputFileName);

    if (!inputFile) {
        cerr << "Не вдалося відкрити файл для читання." << endl;
        return;
    }

    string line;
    while (getline(inputFile, line)) {
        int tabCount = 0;
        for (char ch : line) {
            if (ch == '\t') {
                tabCount += 4;
            } else {
                if (tabCount > 0) {
                    cout << tabCount;
                    tabCount = 0;
                }
                if (ch == ' ') {
                    cout << 1;
                } else {
                    cout << ch;
                }
            }
        }
        if (tabCount > 0) {
            cout << tabCount;
        }
        cout << endl;
    }
}

int main() {
    const string inputFileName = "input.txt";
    const string outputFileName = "output.txt";

    if (copyFileWithTabReplacement(inputFileName, outputFileName)) {
        displayInputFileWithReplacement(inputFileName);
    }

    return 0;
}
