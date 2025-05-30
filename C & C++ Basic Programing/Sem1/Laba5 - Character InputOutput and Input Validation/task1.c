#include <stdio.h>
#include <ctype.h>
#include <string.h>

void input(char *ch, int size);
int countSpaces(const char *ch);
int choiceV();
void prVers1(const char *ch, int count);
void prVers2(const char *ch);
int cont();

int main() {
    char ch[50];
    int count, version;
    int first_input = 1;

    do {
        if (!first_input) {
            while (getchar() != '\n' && getchar() != EOF);
        }
        input(ch, sizeof(ch));
        count = countSpaces(ch);
        version = choiceV();

        if (version == 1) {
            prVers1(ch, count);
        } else if (version == 2) {
            prVers2(ch);
        }

        first_input = 0;
    } while (cont());

    printf("\nBye bye\n");
    return 0;
}

void input(char *ch, int size) {
    printf("\nEnter random symbols: \n");
    fgets(ch, size, stdin);
}

int countSpaces(const char *ch) {
    int i, count = 0;
    for (i = 0; i < strlen(ch); i++) {
        if (isspace((unsigned char)ch[i])) {
            count++;
        }
    }
    return count;
}

int choiceV() {
    int version, attempts = 3;
    do {
        printf("\nEnter a number (1 or 2) for the version you choose: \n");
        scanf(" %d", &version);
        while (getchar() != '\n');

        if (version == 1 || version == 2) {
            return version;
        } else {
            printf("Invalid input. Try again...\n");
            attempts--;
        }
    } while (attempts > 0);
    
    printf("Too many invalid attempts. Exiting...\n");
    return -1;
}

void prVers1(const char *ch, int count) {
    for (int i = 0; i < strlen(ch); i++) {
        if (isspace((unsigned char)ch[i])) {
            putchar(' ');
            continue;
        }
        putchar(ch[i]);
        if (ch[i + 1] != '\0' && !isspace((unsigned char)ch[i + 1])) {
            putchar(' ');
        }
    }
    putchar('\n');
}

void prVers2(const char *ch) {
    for (int i = 0; i < strlen(ch); i++) {
        if (!isspace((unsigned char)ch[i])) {
            putchar(ch[i]);
            putchar(' ');
        }
        if (isspace((unsigned char)ch[i + 1])) {
            putchar('\n');
        }
    }
}

int cont() {
    char choice;
    printf("\nDo you want to continue? (y/n): ");
    scanf(" %c", &choice);
    return (choice == 'y' || choice == 'Y');
}
