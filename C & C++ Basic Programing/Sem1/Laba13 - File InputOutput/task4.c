#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    FILE *fp = NULL;
    float number, sum = 0.0;
    int count = 0;
    double *values = NULL;

    if (argc == 2) {
        fp = fopen(argv[1], "r");
        if (fp == NULL) {
            printf("Error opening %s\n", argv[1]);
            return EXIT_FAILURE;
        }
    } else if (argc == 1) {
        fp = stdin;
        printf("Enter double values (Ctrl+Z to finish):\n");
    } else {
        printf("Incorrect number of arguments\n");
        return EXIT_FAILURE;
    }

    while (fscanf(fp, "%f", &number) == 1) {
        double *temp = realloc(values, (count + 1) * sizeof(double));
        if (temp == NULL) {
            printf("Memory allocation failed!\n");
            free(values);
            if (fp != stdin) fclose(fp);
            return EXIT_FAILURE;
        }
        values = temp;
        values[count] = number;
        sum += number;
        count++;
    }

    if (fp != stdin && fclose(fp) != 0) {
        printf("Error closing file\n");
        free(values);
        return EXIT_FAILURE;
    }

    if (count > 0) {
        printf("Values from %s:\n\n", (argc == 2) ? argv[1] : "stdin");
        for (int i = 0; i < count; i++) {
            printf("%.2f\n", values[i]);
        }
        printf("\nSum: %.2f\n", sum);
        printf("Average: %.2f\n", sum / count);
    } else {
        printf("No values read.\n");
    }

    free(values);
    return 0;
}
