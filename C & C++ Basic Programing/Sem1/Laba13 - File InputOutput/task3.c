#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp1, *fp2;
    char ch;

    fp1 = fopen("terky.txt", "r");
    fp2 = fopen("jerky.txt", "w");

    if (fp1 == NULL || fp2 == NULL) {
        printf("Error opening file\n");
        exit(EXIT_FAILURE);
    }

    while ((ch = getc(fp1)) != EOF) {
        fprintf(fp2, "%c\n", ch);
        putc(ch, fp2);
    }

    fclose(fp1);
    fclose(fp2);

    return 0;
}
