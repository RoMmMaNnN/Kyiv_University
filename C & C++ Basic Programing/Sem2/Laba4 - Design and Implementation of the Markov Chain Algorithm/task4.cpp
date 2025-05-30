#include <iostream>
#include <vector>
#include <map>
#include <deque>
#include <string>
#include <fstream>
#include <cstdlib>

using namespace std;

typedef deque<string> Prefix;
map<Prefix, vector<string>> statetab;

#define NPREF 2
#define NHASH 5
#define MAXGEN 1000
char NONWORD[] = "\n";

void add(Prefix &prefix, const string& s) {
    if (prefix.size() == NPREF) {
        statetab[prefix].push_back(s);
        prefix.pop_front();
    }
    prefix.push_back(s);
}

void build(Prefix &prefix, istream &in) {
    string buf;
    while (in >> buf) {
        add(prefix, buf);
    }
}

void generate(int nwords) {
    Prefix prefix;
    for (int i = 0; i < NPREF; i++)
        add(prefix, NONWORD);
    
    for (int i = 0; i < nwords; i++) {
        vector<string>& suf = statetab[prefix];
        if (suf.empty()) {
            cout << "No more words to generate.\n";
            break;
        }
        const string& w = suf[rand() % suf.size()];
        if (w == NONWORD)
            break;
        cout << w << " ";
        prefix.pop_front();
        prefix.push_back(w);
    }
}

int main() {
    int nwords = MAXGEN;
    Prefix prefix;
    for (int i = 0; i < NPREF; i++)
        add(prefix, NONWORD);
    
    ifstream file("text4.txt");
    if (!file) {
        cerr << "Error opening file!" << endl;
        return 1;
    }
    
    build(prefix, file);
    add(prefix, NONWORD);
    generate(nwords);

    return 0;
}
