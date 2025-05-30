#include <stdio.h>

char *my_gets(char *st, int n) {
    char *ret_val = fgets(st, n, stdin);
    if (ret_val) {
        char *ptr = st;
        while (*ptr && *ptr != '\n') {
            ptr++;
        }
        if (*ptr == '\n') {
            *ptr = '\0';
        } else {
            while (getchar() != '\n' && getchar() != EOF) {
                continue;
            }
        }
    }
    return ret_val;
}

int main(void) {
    char input[50];
    printf("Enter a string: ");
    if (my_gets(input, 50)) {
        printf("You entered: %s\n", input);
    } else {
        printf("Error reading input.\n");
    }
    return 0;
}
