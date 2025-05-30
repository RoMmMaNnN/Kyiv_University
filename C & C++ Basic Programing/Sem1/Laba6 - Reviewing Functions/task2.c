#include <stdio.h>

int maxNum(int n, int m);
char maxChar(char a, char b);
char maxSymbol(char x, char y);
void compareNumbers();
void compareLetters();
void compareSymbols();

int main() {
    int choice;

    while (1) {
        printf("\nMenu:\n");
        printf("1) Compare the numbers\n");
        printf("2) Compare the letters\n");
        printf("3) Compare the symbols\n");
        printf("4) Exit\n");
        printf("My choice: ");
        scanf(" %d", &choice);

        switch (choice) {
            case 1:
                compareNumbers();
                break;
            case 2:
                compareLetters();
                break;
            case 3:
                compareSymbols();
                break;
            case 4:
                printf("\nExiting the program... \nDone!\n");
                return 0;
            default:
                printf("Invalid input, please try again.\n");
        }
    }
    return 0;
}

int maxNum(int n, int m) {
    return (n > m) ? n : m;
}

char maxChar(char a, char b) {
    return (a > b) ? a : b;
}

char maxSymbol(char x, char y) {
    return (x > y) ? x : y;
}

void compareNumbers() {
    int n, m;
    printf("\nEnter two numbers: ");
    scanf("%d %d", &n, &m);
    printf("\nThe larger number is: %d\n", maxNum(n, m));
}

void compareLetters() {
    char a, b;
    printf("\nEnter two letters: ");
    scanf(" %c %c", &a, &b);
    printf("\nThe larger letter is: %c\n", maxChar(a, b));
}

void compareSymbols() {
    char x, y;
    printf("\nEnter two symbols: ");
    scanf(" %c %c", &x, &y);
    printf("\nThe larger symbol is: %c\n", maxSymbol(x, y));
}
