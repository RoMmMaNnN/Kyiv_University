#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cctype>
using namespace std;

const int WIDTH = 80;

bool openInput(ifstream& in, const string& filename) {
    in.open(filename);
    return in.is_open();
}

bool openOutput(ofstream& out, const string& filename) {
    out.open(filename);
    return out.is_open();
}

string switchCase(const string& text) {
    string result;
    for (char ch : text) {
        if (islower(ch)) result += toupper(ch);
        else if (isupper(ch)) result += tolower(ch);
        else result += ch;
    }
    return result;
}

void copyWithCaseSwitch(const string& inputFile, const string& outputFile) {
    ifstream in;
    if (!openInput(in, inputFile)) {
        cout << "Failed to open input file\n";
        return;
    }

    ofstream out;
    if (!openOutput(out, outputFile)) {
        cout << "Failed to open output file\n";
        in.close();
        return;
    }

    string content((istreambuf_iterator<char>(in)), istreambuf_iterator<char>());
    out << switchCase(content);

    in.close();
    out.close();
}

vector<string> splitByNewlines(const string& text) {
    vector<string> lines;
    string line;
    for (char ch : text) {
        if (ch == '\n') {
            lines.push_back(line);
            line.clear();
        } else if (ch != '\r') {
            line += ch;
        }
    }
    if (!line.empty()) lines.push_back(line);
    return lines;
}

void printCentered(const string& filename) {
    ifstream file;
    if (!openInput(file, filename)) {
        cout << "Cannot open result file\n";
        return;
    }

    string content((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
    file.close();

    vector<string> lines = splitByNewlines(content);

    for (const string& raw : lines) {
        string line = raw;
        if (line.length() > WIDTH) line = line.substr(0, WIDTH);

        int totalPadding = WIDTH - line.length();
        int left = totalPadding / 2;
        int right = totalPadding - left;

        cout << string(left, '_') << line << string(right, '_') << endl;
    }
}

int main() {
    string inputFile = "text.txt";
    string outputFile = "output.txt";

    copyWithCaseSwitch(inputFile, outputFile);
    printCentered(outputFile);

    return 0;
}
