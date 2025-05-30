#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 256

int main(int argc, char *argv[]) {
    char ch = argv[1][0];
    char *fileName = argv[2];
    char line[MAX];

    if (argc != 3) {
        printf("Uncorrect argv\n");
        return EXIT_FAILURE;
    }

    FILE *file = fopen(fileName, "r");
    if (file == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }
    
    while (fgets(line, MAX, file)) {
        if (strchr(line, ch)) {
            printf("%s", line);
        }
    }
    fclose(file);

    return EXIT_SUCCESS;
}
