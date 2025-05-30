#include <stdio.h>

char *strncpyCustom(char *s1, const char *s2, size_t n);
char *mystrncpy(char *s1, const char *s2, size_t n);

int main() {
    char source[100];
    char destination[100];
    size_t n;

    while (1) {
        printf("Enter the source string: ");
        fgets(source, sizeof(source), stdin);

        size_t i = 0;
        while (source[i] != '\0') {
            if (source[i] == '\n') {
                source[i] = '\0';
                break;
            }
            i++;
        }

        printf("Enter the number of characters to copy (n): ");
        scanf("%zu", &n);
        getchar();

        strncpyCustom(destination, source, n);
        destination[n] = '\0';
        printf("Using strncpy_custom: %s\n", destination);

        mystrncpy(destination, source, n);
        destination[n] = '\0';
        printf("Using mystrncpy: %s\n", destination);
    }

    return 0;
}

char *strncpyCustom(char *s1, const char *s2, size_t n) {
    size_t i;
    for (i = 0; i < n && s2[i] != '\0'; i++) {
        s1[i] = s2[i];
    }
    for (; i < n; i++) {
        s1[i] = '\0';
    }
    return s1;
}

char *mystrncpy(char *s1, const char *s2, size_t n) {
    if (s2 == NULL) {
        s1[0] = '\0';
        return s1;
    }

    size_t i;
    for (i = 0; i < n && s2[i] != '\0'; i++) {
        s1[i] = s2[i];
    }

    for (; i < n; i++) {
        s1[i] = '\0';
    }
    return s1;
}
