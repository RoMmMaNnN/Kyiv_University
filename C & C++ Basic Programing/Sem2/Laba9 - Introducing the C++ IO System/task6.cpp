#include <iostream>
#include <cstring>

using namespace std;

int width() {
    return 80;
}

void center(const char *s) {
    int len = strlen(s);
    int total_width = width();
    int spaces = (total_width - len) / 2;
    for (int i = 0; i < spaces; i++) {
        cout << " ";
    }
    cout << s << endl;
}

int main() {
    const char* str = "center";
    center(str);
    return 0;
}
