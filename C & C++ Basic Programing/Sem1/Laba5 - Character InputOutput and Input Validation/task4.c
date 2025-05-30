#include <stdio.h>
#include <ctype.h>

void checkType(char ch);

int main() {
    char ch;
    char cont;

    do {
        printf("\nEnter a symbol: ");
        scanf(" %c", &ch);
        checkType(ch);

        printf("\nDo you want to continue? (y/n): ");
        getchar();
        cont = getchar();
    } while (cont == 'y' || cont == 'Y');

    printf("\nBye bye!\n");
    return 0;
}

void checkType(char ch) {
    if (isalpha((unsigned char)ch)) {
        printf("\nThe symbol \"%c\" is a letter.\n", ch);
    } 
    else if (isspace((unsigned char)ch)) {
        printf("\nThe symbol \"%c\" is a space.\n", ch);
    } 
    else if (isdigit((unsigned char)ch)) {
        printf("\nThe symbol \"%c\" is a number.\n", ch);
    }
    else {
        printf("\nThe symbol \" %c\" isn't a letter or space or a number\n", ch);
    }
}
