#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define MAX_SIZE 20

void printIntArray(int *arr, int n);
void printFloatArray(float *arr, int n);
void printFloatMatrix(float (*arr)[MAX_SIZE], int rows, int cols);
int findMaxInt(int *arr, int n);
float findMaxFloatMatrix(float (*arr)[MAX_SIZE], int rows, int cols);
float findFloatDifference(float *arr, int n);
void menu();
void inputIntArray(int *arr, int n);
void inputFloatArray(float *arr, int n);
void inputFloatMatrix(float (*arr)[MAX_SIZE], int rows, int cols);
int checkChoice();
bool continueProgram();

int main() {
    int n;
    printf("Enter the number of elements in the arrays (max %d): ", MAX_SIZE);
    while (scanf("%d", &n) != 1 && n <= 0 && n > MAX_SIZE) {
        printf("Invalid input! Enter a positive integer between 1 and %d: ", MAX_SIZE);
        while (getchar() != '\n');
    }

    int intArr[n];
    float floatArr[n];
    float floatMatrix[n][n];

    do {
        menu();
        int choice = checkChoice();

        switch (choice) {
            case 1:
                inputIntArray(intArr, n);
                printf("Max in integer array: %d\n", findMaxInt(intArr, n));
                break;
            case 2:
                inputFloatMatrix(floatMatrix, n, n);
                printf("Max in float matrix: %.2f\n", findMaxFloatMatrix(floatMatrix, n, n));
                break;
            case 3:
                inputFloatArray(floatArr, n);
                printf("Difference between max and min in float array: %.2f\n", findFloatDifference(floatArr, n));
                break;
            default:
                printf("Invalid choice! Choose 1, 2, or 3.\n");
                break;
        }

    } while (continueProgram());

    return 0;
}

void printIntArray(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void printFloatArray(float *arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%.2f ", arr[i]);
    }
    printf("\n");
}

void printFloatMatrix(float (*arr)[MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%.2f ", arr[i][j]);
        }
        printf("\n");
    }
}

int findMaxInt(int *arr, int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

float findMaxFloatMatrix(float (*arr)[MAX_SIZE], int rows, int cols) {
    float max = arr[0][0];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (arr[i][j] > max) {
                max = arr[i][j];
            }
        }
    }
    return max;
}

float findFloatDifference(float *arr, int n) {
    float max = arr[0];
    float min = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    printf("Max value: %.2f, Min value: %.2f\n", max, min);
    return max - min;
}

void menu() {
    printf("\nMenu:\n");
    printf("1. Find max in integer array\n");
    printf("2. Find max in float matrix\n");
    printf("3. Find difference between max and min in float array\n");
}

void inputIntArray(int *arr, int n) {
    printf("Enter %d integer values:\n", n);
    for (int i = 0; i < n; i++) {
        printf("%d) ", i + 1);
        while (scanf("%d", &arr[i]) != 1) {
            printf("Invalid input! Enter an integer: ");
            while (getchar() != '\n');
        }
    }
}

void inputFloatArray(float *arr, int n) {
    printf("Enter %d float values:\n", n);
    for (int i = 0; i < n; i++) {
        printf("%d) ", i + 1);
        while (scanf("%f", &arr[i]) != 1) {
            printf("Invalid input! Enter a float: ");
            while (getchar() != '\n');
        }
    }
}

void inputFloatMatrix(float (*arr)[MAX_SIZE], int rows, int cols) {
    printf("Enter %d x %d float matrix values:\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Enter value for [%d][%d]: ", i + 1, j + 1);
            while (scanf("%f", &arr[i][j]) != 1) {
                printf("Invalid input! Enter a float: ");
                while (getchar() != '\n');
            }
        }
    }
}

int checkChoice() {
    int choice;
    printf("Your choice: ");
    while (scanf("%d", &choice) != 1 && (choice < 1 && choice > 3)) {
        printf("Invalid choice! Choose 1, 2, or 3: ");
        while (getchar() != '\n');
    }
    return choice;
}

bool continueProgram() {
    char choice;
    printf("\nContinue? (+/-): ");
    while (scanf(" %c", &choice) != 1 && (choice != '+' && choice != '-')) {
        printf("Invalid input! Enter '+' to continue or '-' to exit: ");
        while (getchar() != '\n');
    }
    return choice == '+';
}
