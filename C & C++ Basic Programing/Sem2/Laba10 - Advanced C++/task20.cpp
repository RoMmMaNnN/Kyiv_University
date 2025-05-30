#include <iostream>
#include <fstream>
#include <map>
#include <cctype>
#include <set>

using namespace std;

bool isVowel(char c) {
    static const set<char> vowels = {
        'a', 'e', 'i', 'o', 'u',
        'A', 'E', 'I', 'O', 'U'
    };
    return vowels.count(c);
}

bool isConsonant(char c) {
    return isalpha(c) && !isVowel(c);
}

void analyzeLetters(const string& filename) {
    ifstream in(filename);
    if (!in) {
        cerr << "Failed to open file.\n";
        return;
    }

    map<char, int> vowelCount;
    map<char, int> consonantCount;

    char ch;
    while (in.get(ch)) {
        if (isalpha(static_cast<unsigned char>(ch))) {
            if (isVowel(ch)) {
                ++vowelCount[ch];
            } else if (isConsonant(ch)) {
                ++consonantCount[ch];
            }
        }
    }

    for (char c = 'A'; c <= 'Z'; ++c) {
        if (vowelCount.count(c))
            cout << c << ":" << vowelCount[c] << " ";
    }
    for (char c = 'a'; c <= 'z'; ++c) {
        if (vowelCount.count(c))
            cout << c << ":" << vowelCount[c] << " ";
    }
    for (char c = -128; c < 127; ++c) {
        if (vowelCount.count(c))
            cout << c << ":" << vowelCount[c] << " ";
    }
    cout << "\n";

    for (char c = 'A'; c <= 'Z'; ++c) {
        if (consonantCount.count(c))
            cout << c << ":" << consonantCount[c] << " ";
    }
    for (char c = 'a'; c <= 'z'; ++c) {
        if (consonantCount.count(c))
            cout << c << ":" << consonantCount[c] << " ";
    }
    for (char c = -128; c < 127; ++c) {
        if (consonantCount.count(c))
            cout << c << ":" << consonantCount[c] << " ";
    }
    cout << "\n";
}

int main() {
    string filename = "text.txt";
    analyzeLetters(filename);
    return 0;
}
