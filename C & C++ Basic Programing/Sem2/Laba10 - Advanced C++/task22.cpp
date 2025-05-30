#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>
#include <fcntl.h>
using namespace std;

class Stack {
    string filename;
public:
    Stack(const string& fname) : filename(fname) {}

    void push(char ch) {
        ofstream file(filename, ios::app);
        if (file.is_open()) {
            file.put(ch);
            file.close();
        }
    }

    void pop() {
        ifstream file(filename, ios::ate | ios::binary);
        if (file.is_open()) {
            streamoff length = file.tellg();
            file.close();
            if (length > 0) {
                int fd = open(filename.c_str(), O_RDWR);
                if (fd != -1) {
                    ftruncate(fd, static_cast<off_t>(length - 1));
                    close(fd);
                }
            }
        }
    }

    void display() {
        ifstream file(filename);
        if (file.is_open()) {
            char ch;
            while (file.get(ch)) {
                cout << ch;
            }
            file.close();
        }
    }
};

int main() {
    string filename = "stack.txt";
    Stack stack(filename);

    stack.push('A');
    stack.push('B');
    stack.push('C');

    cout << "Push operations:\n";
    stack.display();

    stack.pop();

    cout << "\nPop operation:\n";
    stack.display();

    return 0;
}
