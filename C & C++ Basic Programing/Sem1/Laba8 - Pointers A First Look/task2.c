#include <stdio.h>

void input(double *a, double *b);
void swap(double *a, double *b);
void printResult(double a, double b);

int main() {
    double a, b;
    input(&a, &b);
    printResult(a, b);
    swap(&a, &b);
    printResult(a, b);

    return 0;
}

void input(double *a, double *b) {
    int result;

    do {
        printf("Enter a value for a: ");
        result = scanf("%lf", a);
        while (getchar() != '\n');
        if (result != 1) {
            printf("Input error. Please try again.\n");
        }
    } while (result != 1);

    do {
        printf("Enter a value for b: ");
        result = scanf("%lf", b);
        while (getchar() != '\n');
        if (result != 1) {
            printf("Input error. Please try again.\n");
        }
    } while (result != 1);
}

void swap(double *a, double *b) {
    double temp = *a;
    *a = *b;
    *b = temp;
}

void printResult(double a, double b) {
    printf("\nValues: a = %.2f, b = %.2f\n", a, b);
}
