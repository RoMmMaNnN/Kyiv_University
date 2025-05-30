#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

#define MAX_PAIRS 2000

struct Triple {
    string first;
    string second;
    string next;
};

Triple triplets[MAX_PAIRS];
int tripletCount = 0;

void loadText(const char* filename) {
    ifstream file(filename);
    if (!file) {
        cout << "Error opening file!" << endl;
        return;
    }

    string prev1, prev2, curr;
    file >> prev1 >> prev2;
    while (file >> curr) {
        triplets[tripletCount] = {prev1, prev2, curr};
        tripletCount++;
        prev1 = prev2;
        prev2 = curr;
    }
    file.close();
}

void generateText(string start1, string start2, int length) {
    srand(time(0));
    cout << start1 << " " << start2 << " ";
    
    for (int i = 0; i < length; i++) {
        string nextWords[MAX_PAIRS];
        int count = 0;

        for (int j = 0; j < tripletCount; j++) {
            if (triplets[j].first == start1 && triplets[j].second == start2) {
                nextWords[count] = triplets[j].next;
                count++;
            }
        }

        if (count == 0) break;
        
        if (count == 1) {
            start1 = start2;
            start2 = nextWords[0];
        } else {
            start1 = start2;
            start2 = nextWords[rand() % count];
        }

        cout << start2 << " ";
    }
    cout << endl;
}

int main() {
    loadText("text1.txt");
    generateText("When", "Pasteur", 67);
    return 0;
}
