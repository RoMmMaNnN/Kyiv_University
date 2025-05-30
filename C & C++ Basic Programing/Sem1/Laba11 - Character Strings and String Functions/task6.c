#include <stdio.h>

size_t my_strlen(const char *str);

int main(void) {
    char input[100];
    printf("Enter a string: ");
    if (fgets(input, 100, stdin)) {
        size_t length = my_strlen(input);
        if (input[length - 1] == '\n') { 
            input[length - 1] = '\0'; 
            length--;
        }
        printf("The length of the string is: %zu\n", length);
    } else {
        printf("Error reading input.\n");
    }
    return 0;
}

size_t my_strlen(const char *str) {
    const char *ptr = str;
    while (*ptr) {
        ptr++;
    }
    return ptr - str;
}
