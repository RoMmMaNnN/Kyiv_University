#include <iostream>
#include <string>
using namespace std;

class Book {
private:
    string title;
    string author;
    int copies;

public:
    void store(string t, string a, int c) {
        title = t;
        author = a;
        copies = c;
    }

    void show() {
        cout << "Book information:" << endl;
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Number of copies: " << copies << endl;
    }
};

int main() {
    Book book1;

    book1.store("Kobzar", "Shevchenko", 100);
    book1.show();

    return 0;
}
