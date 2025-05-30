#include <stdio.h> 
#include <stdbool.h>

#define MAX 15 

void menu(char *option);
void inputMatrix(int *n, int *m, double matrix[MAX][MAX]);
void transponMatrix(int n, int m, double matrix1[MAX][MAX], double Tmatrix[MAX][MAX]);
void sumMatrix(int n, int m, double matrix1[MAX][MAX], double matrix2[MAX][MAX], double Smatrix[MAX][MAX]);
void printMatrix(int n, int m, double matrix[MAX][MAX]);
bool continueProgram();

int main() {
    char option;
    int n, m;
    double matrix1[MAX][MAX], matrix2[MAX][MAX], Tmatrix[MAX][MAX], Smatrix[MAX][MAX];
    
    do {
        menu(&option);
        
        switch (option) {
            case '1':
                inputMatrix(&n, &m, matrix1);
                transponMatrix(n, m, matrix1, Tmatrix);
                printf("Transposed Matrix:\n");
                printMatrix(m, n, Tmatrix);
                break;

            case '2':
                printf("Enter the first matrix:\n");
                inputMatrix(&n, &m, matrix1);
                printf("Enter the second matrix:\n");
                inputMatrix(&n, &m, matrix2);
                sumMatrix(n, m, matrix1, matrix2, Smatrix);
                printf("Sum of matrices:\n");
                printMatrix(n, m, Smatrix);
                break;

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
        
    } while (continueProgram());

    return 0;
}

void menu(char *option) {
    printf("Choose an operation:\n");
    printf("1) Transpose\n");
    printf("2) Sum\n");
    printf("Enter your choice: ");
    scanf(" %c", option);
}

void inputMatrix(int *n, int *m, double matrix[MAX][MAX]) {
    do {
        printf("Enter the number of rows and columns (1 to %d): ", MAX);
        scanf("%d %d", n, m);

        if (*n <= 0 && *n > MAX && *m <= 0 && *m > MAX) {
            printf("Invalid dimensions. Please try again.\n");
        }
    } while (*n <= 0 && *n > MAX && *m <= 0 && *m > MAX);

    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < *n; i++) {
        for (int j = 0; j < *m; j++) {
            printf("Element [%d][%d]: ", i + 1, j + 1);
            scanf("%lf", &matrix[i][j]);
        }
    }
}

void transponMatrix(int n, int m, double matrix1[MAX][MAX], double Tmatrix[MAX][MAX]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            Tmatrix[j][i] = matrix1[i][j];
        }
    }
}

void sumMatrix(int n, int m, double matrix1[MAX][MAX], double matrix2[MAX][MAX], double Smatrix[MAX][MAX]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            Smatrix[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

void printMatrix(int n, int m, double matrix[MAX][MAX]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%8.2f ", matrix[i][j]);
        }
        printf("\n");
    }
}

bool continueProgram() {
    char choice;
    do {
        printf("\nDo you want to continue? (+/-): ");
        scanf(" %c", &choice);
        if (choice != '+' && choice != '-') {
            printf("Invalid input. Please try again.\n");
        }
    } while (choice != '+' && choice != '-');
    return (choice == '+');
}
