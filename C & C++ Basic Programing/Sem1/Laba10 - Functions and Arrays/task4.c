#include <stdio.h>

int main(void) {
    int digits[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    float rates[6] = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6};

    int mat[3][5] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15}
    };

    char *psa[20] = {
        "Hello", "World", "I", "Love", "You", "A", "B", "c", "d", "e",
        "Learn", "English", "!", "!", "!", "Because", "You", "must", "understand", "!"
    };

    char pstr[20] = "ThisIsACharArrayTest";

    printf("Array digits:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", digits[i]);
    }
    printf("\n");

    printf("Array rates:\n");
    for (int i = 0; i < 6; i++) {
        printf("%.1f ", rates[i]);
    }
    printf("\n");

    printf("Array mat:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }

    printf("Array psa:\n");
    for (int i = 0; i < 20; i++) {
        printf("%s ", psa[i]);
    }
    printf("\n");

    printf("String pstr: %s\n", pstr);

    return 0;
}
