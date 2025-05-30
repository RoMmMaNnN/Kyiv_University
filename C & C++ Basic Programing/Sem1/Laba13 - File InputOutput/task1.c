#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

void continueProgram(char* choice);
void getCoefficients(double* a, double* b, double* c);
FILE* openFile(int* first_run);
void solveAndSave(FILE* file, double a, double b, double c);

int main() {
    char choice = '+';
    int first_run = 1;
    double a, b, c;

    FILE* result_file = openFile(&first_run);

    while (choice == '+') {
        getCoefficients(&a, &b, &c);
        printf("Equation: %.2fx^2 + %.2fx + %.2f = 0\n", a, b, c);
        fprintf(result_file, "Equation: %.2fx^2 + %.2fx + %.2f = 0\n", a, b, c);
        solveAndSave(result_file, a, b, c);
        continueProgram(&choice);
    }
    fclose(result_file);
    printf("Bye bye\n");

    return 0;
}

void continueProgram(char* choice) {
    printf("\nIf you want to continue, enter '+' or '-': ");
    while (scanf(" %c", choice) != 1 || (*choice != '+' && *choice != '-')) {
        printf("Invalid input. Please enter '+' or '-': ");
        while (getchar() != '\n');
    }
    while (getchar() != '\n');
}

void getCoefficients(double* a, double* b, double* c) {
    printf("Enter coefficients a, b, c separated by space: ");
    while (scanf("%lf %lf %lf", a, b, c) != 3) {
        printf("Invalid input! Please enter valid numbers for a, b, and c: ");
        while (getchar() != '\n');
    }
}

FILE* openFile(int* first_run) {
    FILE* file;
    if (*first_run) {
        file = fopen("results1.txt", "w");
        *first_run = 0;
    } else {
        file = fopen("results1.txt", "a");
    }

    if (!file) {
        perror("Error opening file");
        exit(1);
    }
    return file;
}

void solveAndSave(FILE* file, double a, double b, double c) {
    double discriminant = b * b - 4 * a * c;

    if (discriminant < 0) {
        printf("No real roots for the equation.\n");
        fprintf(file, "No real roots for the equation.\n");
    } else if (discriminant == 0) {
        double x = -b / (2 * a);

        printf("x = %.6f\n", x);
        fprintf(file, "x = %.6f\n", x);
    } else {
        double x1 = (-b - sqrt(discriminant)) / (2 * a);
        double x2 = (-b + sqrt(discriminant)) / (2 * a);

        printf("x1 = %.6f; x2 = %.6f\n", x1, x2);
        fprintf(file, "x1 = %.6f; x2 = %.6f\n", x1, x2);
    }
}
