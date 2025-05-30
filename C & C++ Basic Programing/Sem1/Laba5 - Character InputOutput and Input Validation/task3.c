#include <stdio.h>
#include <ctype.h>

void convert_to_lowercase();
void convert_to_uppercase();

int main() {
    int choice;
    char cont;

    do {
        printf("Menu: \n1. Convert input to uppercase \n2. Convert input to lowercase \nEnter your choice (1 or 2): ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                convert_to_uppercase();
                break;
            case 2:
                convert_to_lowercase();
                break;
            default:
                printf("Invalid choice. Please enter 1 or 2.\n");
                break;
        }

        printf("Do you want to continue? (y/n): ");
        cont = getchar();
        getchar();

    } while (cont == 'y' || cont == 'Y');

    printf("Bye bye!\n");
    return 0;
}

void convert_to_uppercase() {
    char ch;
    printf("Enter letters (press Enter to finish): \n");
    while ((ch = getchar()) != '\n') {
        putchar(toupper(ch));
    }
    putchar('\n');
}

void convert_to_lowercase() {
    char ch;
    printf("Enter uppercase letters (press Enter to finish): \n");
    while ((ch = getchar()) != '\n') {
        putchar(tolower(ch));
    }
    putchar('\n');
}