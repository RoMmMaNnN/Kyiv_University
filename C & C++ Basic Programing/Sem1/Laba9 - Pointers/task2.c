#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_WORDS 10
#define MAX_LEN 15

void menu(char *option);
void removeNonLetters(char *str);
void inputWords(char words[MAX_WORDS][MAX_LEN], int *n);
void sortWords(char words[MAX_WORDS][MAX_LEN], int n);
void printWords(char words[MAX_WORDS][MAX_LEN], int n);
bool continueProgram();
int compareStrings(char *str1, char *str2);

int main() {
    char option;
    char str[150];
    int n;
    char words[MAX_WORDS][MAX_LEN];
    
    do {
        menu(&option);
        
        switch (option) {
            case '1':
                printf("Enter a string with letters and symbols: ");
                fgets(str, sizeof(str), stdin);
                if (str[strlen(str) - 1] == '\n') {
                    str[strlen(str) - 1] = '\0';
                }
                removeNonLetters(str);
                printf("String with letters only: %s\n", str);
                break;

            case '2':
                inputWords(words, &n);
                sortWords(words, n);
                printf("Sorted words in alphabetical order:\n");
                printWords(words, n);
                break;

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
        
    } while (continueProgram());

    return 0;
}

void menu(char *option) {
    printf("Choose an operation:\n");
    printf("1) Remove symbols from string\n");
    printf("2) Sort words alphabetically\n");
    printf("Enter your choice: ");
    scanf(" %c", option);
    getchar();
}

void removeNonLetters(char *str) {
    int j = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (isalpha((unsigned char)str[i])) {
            str[j++] = str[i];
        }
    }
    str[j] = '\0';
}

void inputWords(char words[MAX_WORDS][MAX_LEN], int *n) {
    printf("Enter the number of words (up to %d): ", MAX_WORDS);
    scanf("%d", n);
    getchar();
    
    for (int i = 0; i < *n; i++) {
        printf("Enter word %d: ", i + 1);
        fgets(words[i], MAX_LEN, stdin);
        words[i][strcspn(words[i], "\n")] = '\0';

        for (int j = 0; words[i][j] != '\0'; j++) {
            if (!isalpha((unsigned char)words[i][j])) {
                printf("Error: only letters allowed. Please enter again word %d.\n", i + 1);
                i--;
                break;
            }
        }
    }
}

void sortWords(char words[MAX_WORDS][MAX_LEN], int n) {
    char temp[MAX_LEN];
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (compareStrings(words[j], words[j + 1]) > 0) {
                for (int k = 0; words[j][k] != '\0'; k++) {
                    temp[k] = words[j][k];
                }
                temp[strlen(words[j])] = '\0';

                for (int k = 0; words[j + 1][k] != '\0'; k++) {
                    words[j][k] = words[j + 1][k];
                }
                words[j][strlen(words[j + 1])] = '\0';

                for (int k = 0; temp[k] != '\0'; k++) {
                    words[j + 1][k] = temp[k];
                }
                words[j + 1][strlen(temp)] = '\0';
            }
        }
    }
}

void printWords(char words[MAX_WORDS][MAX_LEN], int n) {
    for (int i = 0; i < n; i++) {
        printf("%s\n", words[i]);
    }
}

bool continueProgram() {
    char choice;
    printf("\nDo you want to continue? (+/-): ");
    while (scanf(" %c", &choice) != 1 && (choice != '+' && choice != '-')) {
        printf("Invalid input. Please enter '+' to continue or '-' to exit: ");
        while (getchar() != '\n');
    }
    while (getchar() != "\n");
    return choice == '+';
}

int compareStrings(char *str1, char *str2) {
    while (*str1 != '\0' && *str2 != '\0') {
        if (*str1 != *str2) {
            return *str1 - *str2;
        }
        str1++;
        str2++;
    }

    return *str1 - *str2;
}
