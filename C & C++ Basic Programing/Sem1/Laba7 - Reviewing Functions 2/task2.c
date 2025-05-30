#include <stdio.h>

#define MAX_SIZE 150

char message[MAX_SIZE], encryption[MAX_SIZE], key[MAX_SIZE];
int length = 0, key_length = 0;

void input();
void inputKey();
void encrypt();

int main() {
    printf("\nEnter your message for encryption: ");
    input();
    printf("\nEnter the keyword for encryption: ");
    inputKey();
    encrypt();
    printf("\nMessage is original: %s\n\nMessage is encryption: %s\n", message, encryption);
    return 0;
}

void input() {
    char ch;
    length = 0;
    while((ch = getchar()) != '\n' && length < MAX_SIZE - 1){
        message[length] = ch;
        length++;
    }
    message[length] = '\0';
}

void inputKey() {
    char ch;
    key_length = 0;
    while((ch = getchar()) != '\n' && key_length < MAX_SIZE - 1){
        key[key_length] = ch;
        key_length++;
    }
    key[key_length] = '\0';
}

void encrypt() {
    int j = 0;
    for (int i = 0; i < length; i++) {
        char c = message[i];
        if (c >= 'A' && c <= 'Z') {
            encryption[i] = (c - 'A' + (key[j % key_length] - 'A')) % 26 + 'A';
            j++;
        } else if (c >= 'a' && c <= 'z') {
            encryption[i] = (c - 'a' + (key[j % key_length] - 'a')) % 26 + 'a';
            j++;
        } else {
            encryption[i] = c;
        }
    }
    encryption[length] = '\0';
}
