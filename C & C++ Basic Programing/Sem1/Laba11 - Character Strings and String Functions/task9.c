#include <stdio.h>

int is_within(char ch, const char *str);

int main() {
    char input_string[100];
    char target_char;

    printf("Enter a string: ");
    fgets(input_string, sizeof(input_string), stdin);

    printf("Enter a character to search for: ");
    scanf(" %c", &target_char);

    if (is_within(target_char, input_string)) {
        printf("The character '%c' is present in the string.\n", target_char);
    } else {
        printf("The character '%c' is not present in the string.\n", target_char);
    }

    return 0;
}

int is_within(char ch, const char *str) {
    while (*str) {
        if (*str == ch) {
            return 1;
        }
        str++;
    }
    return 0;
}
