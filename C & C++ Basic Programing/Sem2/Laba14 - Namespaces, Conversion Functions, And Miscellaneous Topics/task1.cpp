#include <iostream>
#include <fstream>

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cout << "Usage: CONVERT <input> <output>\n";
        return 1;
    }

    std::ifstream fin(argv[1]);
    std::ofstream fout(argv[2]);

    if (!fout) {
        std::cout << "Cannot open output file.\n";
        return 1;
    }

    if (!fin) {
        std::cout << "Cannot open input file.\n";
        return 1;
    }

    fin.unsetf(std::ios::skipws);
    char ch;

    while (fin >> ch) {
        if (ch == ' ') ch = '|';
        fout << ch;
    }

    fin.close();
    fout.close();

    return 0;
}
