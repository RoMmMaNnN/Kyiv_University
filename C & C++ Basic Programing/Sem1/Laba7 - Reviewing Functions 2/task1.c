#include <stdio.h>

#define MAX_SIZE 150

char message[MAX_SIZE], encryption[MAX_SIZE];
int length = 0;

void input();
void encrypt(int n);

int main() {
    int n;

    printf("\nEnter your message for encryption: ");
    input();
    printf("\nEnter the scrambling step for encryption: ");
    scanf("%d", &n);
    getchar();
    encrypt(n);
    printf("\nMessage is original: %s\n\nMessage is encryption: %s", message, encryption);

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

void encrypt(int n) {
    for (int i = 0; i < length; i++) {
        char c = message[i];
        if (c >= 'A' && c <= 'Z') {
            encryption[i] = (c - 'A' + n) % 26 + 'A';
        } else if (c >= 'a' && c <= 'z') {
            encryption[i] = (c - 'a' + n) % 26 + 'a';
        } else {
            encryption[i] = c;
        }
    }
    encryption[length] = '\0';
}
