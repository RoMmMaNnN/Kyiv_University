#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <vector>

#define NPREF 2
#define NHASH 5
#define MAXGEN 10000

using namespace std;

struct Suffix {
    string word;
    Suffix* next;
};

struct State {
    string pref[NPREF];
    Suffix* suf;
    State* next;
};

State* statetab[NHASH];

int hashFunc(const string prefix[NPREF]);
State* lookup(string prefix[NPREF], bool create);
void addSuffix(State* sp, const string& suffix);
void add(string prefix[NPREF], const string& suffix);
void build(string prefix[NPREF], ifstream& file);
void generate(int nwords, string prefix[NPREF]);

int main() {
    int nwords = MAXGEN;
    string prefix[NPREF] = {"", ""}; // Початкові значення

    ifstream file("D:/Kyiv Polytechnic Institute/Cygwin ОП/Sem2/Laba4/text3.txt");
    if (file) {
        build(prefix, file);
        file.close();
    }

    generate(nwords, prefix);
    return 0;
}

int hashFunc(const string prefix[NPREF]) {
    unsigned int h = 0;
    for (int i = 0; i < NPREF; i++) {
        for (char c : prefix[i]) {
            h = 31 * h + c;
        }
    }
    return h % NHASH;
}

void generate(int nwords, string prefix[NPREF]) {
    for (int i = 0; i < nwords; i++) {
        State* sp = lookup(prefix, false);
        if (!sp || !sp->suf) break;

        Suffix* suf = sp->suf;
        int nmatch = 0;
        string w;
        for (; suf; suf = suf->next) {
            if (rand() % ++nmatch == 0) {
                w = suf->word;
            }
        }
        if (w.empty()) break; // Перевірка перед виводом

        cout << w << " ";

        for (int j = 0; j < NPREF - 1; j++) {
            prefix[j] = prefix[j + 1];
        }
        prefix[NPREF - 1] = w;
    }
    cout << endl;
}

State* lookup(string prefix[NPREF], bool create) {
    int h = hashFunc(prefix);
    State* sp;

    for (sp = statetab[h]; sp != nullptr; sp = sp->next) {
        int i;
        for (i = 0; i < NPREF; i++) {
            if (prefix[i] != sp->pref[i]) break;
        }
        if (i == NPREF) return sp;
    }

    if (create) {
        sp = new State;
        for (int i = 0; i < NPREF; i++) {
            sp->pref[i] = prefix[i];
        }
        sp->suf = nullptr;
        sp->next = statetab[h];
        statetab[h] = sp;
    }
    return sp;
}

void addSuffix(State* sp, const string& suffix) {
    Suffix* suf = new Suffix;
    suf->word = suffix;
    suf->next = sp->suf;
    sp->suf = suf;
}

void add(string prefix[NPREF], const string& suffix) {
    State* sp = lookup(prefix, true);
    addSuffix(sp, suffix);
    for (int i = 0; i < NPREF - 1; i++) {
        prefix[i] = prefix[i + 1];
    }
    prefix[NPREF - 1] = suffix;
}

void build(string prefix[NPREF], ifstream& file) {
    string word;
    while (file >> word) {
        add(prefix, word);
    }
}
