#include <iostream>
#include <fstream>
#include <unordered_map>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <string>

using namespace std;

#define MAX_PAIRS 2000
#define MAX_LENGHT_WORD 20

class MarkovChain {
private:
    unordered_map<string, const char*> wordMap;
    const char* uniqueWords[MAX_PAIRS];
    int wordCount;
    struct WordPair {
        const char* first;
        const char* second;
        WordPair(const char* f, const char* s) : first(f), second(s) {}
    };
    WordPair* pairs[MAX_PAIRS];
    int pairCount;

public:
    MarkovChain() : wordCount(0), pairCount(0) {}

    ~MarkovChain() {
        for (int i = 0; i < pairCount; i++) {
            delete[] pairs[i]->first;
            delete[] pairs[i]->second;
            delete pairs[i];
        }
        wordMap.clear();
        cout << "Memory cleared" << endl;
    }

    const char* getPointer(const char* word) {
        string wordStr(word);
        if (wordMap.find(wordStr) != wordMap.end()) {
            return wordMap[wordStr];
        }
        wordMap[wordStr] = word;
        return word;
    }

    void loadText(const char* filename) {
        char prev[MAX_LENGHT_WORD], cur[MAX_LENGHT_WORD];
        ifstream file(filename);
        if (!file) {
            cout << "Error opening file!" << endl;
            return;
        }

        file >> prev;
        while (file >> cur) {
            if (pairCount >= MAX_PAIRS) {
                cout << "Exceeded maximum number of pairs!" << endl;
                break;
            }
            pairs[pairCount] = new WordPair(strdup(prev), strdup(cur));
            pairCount++;
            strcpy(prev, cur);
        }
        file.close();

        cout << "Total pairs loaded: " << pairCount << endl;
        if (pairCount >= MAX_PAIRS) {
            cout << "Warning: Number of pairs exceeds maximum allowed." << endl;
        }
    }

    void generateText(const char* start, int length) {
        srand(time(0));
        cout << start << " ";
        const char* currentWord = start;

        bool foundPair = false;
        for (int i = 0; i < pairCount; i++) {
            if (strcmp(pairs[i]->first, currentWord) == 0) {
                foundPair = true;
                break;
            }
        }

        if (!foundPair) {
            cout << "\nNo pairs found for the starting word: " << start << endl;
            return;
        }

        for (int i = 0; i < length; i++) {
            const char* nextWords[MAX_PAIRS];
            int count = 0;

            for (int j = 0; j < pairCount; j++) {
                if (strcmp(pairs[j]->first, currentWord) == 0) {
                    nextWords[count++] = pairs[j]->second;
                }
            }

            if (count == 0) break;

            currentWord = nextWords[rand() % count];
            cout << currentWord << " ";
        }
        cout << endl;
    }

    void clearMemory() {
        for (int i = 0; i < pairCount; i++) {
            delete[] pairs[i]->first;
            delete[] pairs[i]->second;
            delete pairs[i];
        }
        wordMap.clear();
        pairCount = 0;
        wordCount = 0;
    }
};

int main() {
    MarkovChain markov1, markov2;

    markov1.loadText("text1.txt");
    markov1.generateText("When", 33);

    markov1.clearMemory();

    markov2.loadText("text2.txt");
    markov2.generateText("Hotel", 33);

    return 0;
}
