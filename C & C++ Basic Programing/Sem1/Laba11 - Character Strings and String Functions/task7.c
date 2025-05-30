#include <stdio.h>

void readChar1(char *arr, int num);
void readChar2(char *arr, int max_num);

int main(void) {
    char buffer[100];
    int num = 0;

    printf("Enter the number of characters to read: ");
    while (scanf("%d", &num) != 1 || num < 1 || num > 99) {
        printf("Invalid input. Please try again: ");
        while (getchar() != '\n');
    }
    getchar();

    printf("\nFirst variation: Reading %d characters.\n", num);
    readChar1(buffer, num);
    printf("Result:\n%s\n", buffer);

    while (getchar() != '\n');

    printf("\nSecond variation: Reading until a special character.\n");
    readChar2(buffer, num);
    printf("Result:\n%s\n", buffer);

    return 0;
}

void readChar1(char *arr, int num) {
    int i = 0;
    while (i < num) {
        char ch = getchar();
        if (ch == EOF) break;
        arr[i++] = ch;
    }
    arr[i] = '\0';
}

void readChar2(char *arr, int max_num) {
    int i = 0;
    while (i < max_num) {
        char ch = getchar();
        if (ch == EOF || ch == ' ' || ch == '\t' || ch == '\n') {
            break; 
        }
        arr[i++] = ch;
    }
    arr[i] = '\0';
}
