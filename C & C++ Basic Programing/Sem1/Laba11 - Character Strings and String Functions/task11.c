#include <stdio.h>
#include <string.h>

char* stringIn(const char* str1, const char* str2);
void continueProgram(char* choice);

int main() {
    char str1[100], str2[100], choice;

    do {
        printf("Enter the first string: ");
        fgets(str1, sizeof(str1), stdin);
        str1[strcspn(str1, "\n")] = '\0';

        printf("Enter the second string: ");
        fgets(str2, sizeof(str2), stdin);
        str2[strcspn(str2, "\n")] = '\0';

        if (stringIn(str1, str2)) {
            printf("'%s' is found in '%s'\n", str2, str1);
        } else {
            printf("'%s' is not found in '%s'\n", str2, str1);
        }
        continueProgram(&choice);
    } while (choice == '+');
    return 0;
}

char* stringIn(const char* str1, const char* str2) {
    while (*str1) {
        const char* s1 = str1;
        const char* s2_temp = str2;

        while (*s2_temp && *s1 == *s2_temp) {
            s1++;
            s2_temp++;
        }

        if (*s2_temp == '\0') {
            return (char*) str1;
        }

        str1++;
    }

    return NULL;
}

void continueProgram(char* choice) {
    printf("\nIf you want to continue, enter '+' or '-': ");
    while (scanf(" %c", choice) != 1 || (*choice != '+' && *choice != '-')) {
        printf("Invalid input. Please enter '+' or '-': ");
        while (getchar() != '\n');
    }
    while (getchar() != '\n');
}
