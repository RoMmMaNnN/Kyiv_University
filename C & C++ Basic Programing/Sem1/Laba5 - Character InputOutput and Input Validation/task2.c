#include <stdio.h>
#include <ctype.h>

void print_uppercase();
void print_lowercase();
void print_mixed();

int main() {
    int choice;
    char cont;

    do {
        printf("Choose output type: \n1. Uppercase letters \n2. Lowercase letters \n3. Mixed case (Aa Bb Cc ... Zz) \nEnter your choice (1, 2, or 3): \n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                print_uppercase();
                break;
            case 2:
                print_lowercase();
                break;
            case 3:
                print_mixed();
                break;
            default:
                printf("Invalid choice. Please enter 1, 2, or 3.\n");
                break;
        }

        printf("Do you want to continue? (y/n): ");
        getchar();
        cont = getchar();

    } while (cont == 'y' || cont == 'Y');

    printf("\nBye bye\n");
    return 0;
}

void print_uppercase() {
    for (char ch = 'A'; ch <= 'Z'; ch++) {
        putchar(ch);
        if (ch < 'Z') {
            putchar(' ');
        }
    }
    printf("!\n");
}

void print_lowercase() {
    for (char ch = 'a'; ch <= 'z'; ch++) {
        putchar(ch);
        if (ch < 'z') {
            putchar(' ');
        }
    }
    printf("!\n");
}

void print_mixed() {
    for (char ch = 'A'; ch <= 'Z'; ch++) {
        putchar(ch);
        putchar(tolower(ch));
        if (ch < 'Z') {
            putchar(' ');
        }
    }
    printf("!\n");
}