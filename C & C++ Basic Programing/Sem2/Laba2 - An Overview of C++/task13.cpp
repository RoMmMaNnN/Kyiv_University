#include <iostream>
#include <cstring>

using namespace std;

void rev_str(char* str);
void rev_str(char* str1, char* str2);

int main() {
    char s1[80], s2[80];

    cout << "Enter a string for s1: ";
    cin.getline(s1, 80);

    rev_str(s1);
    cout << "Reversed string in s1: " << s1 << endl;

    cout << "Enter another string for s1: ";
    cin.getline(s1, 80);
    rev_str(s1, s2);
    cout << "Original string in s1: " << s1 << endl;
    cout << "Reversed string in s2: " << s2 << endl;

    return 0;
}

void rev_str(char* str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        swap(str[i], str[len - i - 1]);
    }
}

void rev_str(char* str1, char* str2) {
    strcpy(str2, str1);
    rev_str(str2);
}
