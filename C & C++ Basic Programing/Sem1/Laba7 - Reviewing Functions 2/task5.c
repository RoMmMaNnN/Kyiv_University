#include <stdio.h>
#include <stdbool.h>

#define MAX_ROWS 10
#define MAX_COLS 10

void menu(int *choice);
void sizeMatrix(int *rows, int *cols);
void inputMatrix(int matrix[MAX_ROWS][MAX_COLS], int rows, int cols);
void bubbleSortRows(int matrix[MAX_ROWS][MAX_COLS], int rows, int cols);
void bubbleSortAll(int matrix[MAX_ROWS][MAX_COLS], int rows, int cols);
void outputMatrix(int matrix[MAX_ROWS][MAX_COLS], int rows, int cols);
bool continueProgram();
void program(int matrix[MAX_ROWS][MAX_COLS], int rows, int cols);

int main() {
    int matrix[MAX_ROWS][MAX_COLS];
    int rows, cols;

    do {
    	sizeMatrix(&rows, &cols);
        inputMatrix(matrix, rows, cols);
        program(matrix, rows, cols);
    } while (continueProgram());

    return 0;
}

void menu(int *choice) {
    printf("Choose a sort option:\n");
    printf("1) Sort rows\n");
    printf("2) Sort entire matrix\n");
    printf("3) Exit\n");
    printf("Your choice: ");
    scanf("%d", choice);
}

void sizeMatrix(int *rows, int *cols) {
    int result;
    do {
        printf("Enter number of rows and columns for the matrix: ");
        result = scanf("%d %d", rows, cols);
        while (getchar() != '\n');
        if (result != 2 && rows <= 0 && cols <= 0) {
            printf("Invalid input. Please enter positive integers.\n");
        }
    } while (result != 2 && rows <= 0 && cols <= 0);
}


void inputMatrix(int matrix[MAX_ROWS][MAX_COLS], int rows, int cols) {
    printf("Enter elements of the matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }
}

void bubbleSortRows(int matrix[MAX_ROWS][MAX_COLS], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols - 1; j++) {
            for (int k = 0; k < cols - j - 1; k++) {
                if (matrix[i][k] > matrix[i][k + 1]) {
                    int temp = matrix[i][k];
                    matrix[i][k] = matrix[i][k + 1];
                    matrix[i][k + 1] = temp;   
                outputMatrix(matrix, rows, cols);                 
                }
            }
        }
    }
}

void bubbleSortAll(int matrix[MAX_ROWS][MAX_COLS], int rows, int cols) {
    for (int i = 0; i < rows * cols - 1; i++) {
        for (int j = 0; j < rows * cols - i - 1; j++) {
            int row1 = j / cols;
            int col1 = j % cols;
            int row2 = (j + 1) / cols;
            int col2 = (j + 1) % cols;
            if (matrix[row1][col1] > matrix[row2][col2]) {
                int temp = matrix[row1][col1];
                matrix[row1][col1] = matrix[row2][col2];
                matrix[row2][col2] = temp;   
            outputMatrix(matrix, rows, cols);             
            }
        }
    }
}

void outputMatrix(int matrix[MAX_ROWS][MAX_COLS], int rows, int cols) {
    printf("Current matrix state:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
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

void program(int matrix[MAX_ROWS][MAX_COLS], int rows, int cols) {
    int choice;
    menu(&choice);
    switch (choice) {
        case 1:
            bubbleSortRows(matrix, rows, cols);
            outputMatrix(matrix, rows, cols);
            break;
        case 2:
            bubbleSortAll(matrix, rows, cols);
            outputMatrix(matrix, rows, cols);
            break;
        case 3:
            printf("\nExit...\nDone!\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
            program(matrix, rows, cols);
    }
}
