#include <stdio.h>

void printMatrix(int matrix[3][3]);
void rotateLeft(int matrix[3][3]);
void rotateRight(int matrix[3][3]);
void rotate180(int matrix[3][3]);
void rotateVertical(int matrix[3][3]);
void rotateHorizontal(int matrix[3][3]);

int main() {
    int matrix[3][3] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
    int choice;

    printMatrix(matrix);

    while (1) {
        printf("Menu:\n");
        printf("1) Rotate matrix left\n");
        printf("2) Rotate matrix right\n");
        printf("3) Rotate matrix 180 degrees\n");
        printf("4) Rotate matrix vertical\n");
        printf("5) Rotate matrix horizontal\n");
        printf("6) Exit\n");
        printf("My choice: ");
        scanf(" %d", &choice);

        switch (choice) {
            case 1:
                rotateLeft(matrix);
                break;
            case 2:
                rotateRight(matrix);
                break;
            case 3:
                rotate180(matrix);
                break;
            case 4:
                rotateVertical(matrix);
                break;
            case 5:
                rotateHorizontal(matrix);
                break;
            case 6:
                printf("\nExit the program... \nDone!\n");
                return 0;
            default:
                printf("Invalid syntax, try again, please...\n");

        }
    }

    return 0;
}

void printMatrix(int matrix[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("\t %d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void rotateLeft(int matrix[3][3]) {
    printf("Matrix before trasformation: \n");
    printMatrix(matrix);
    int temp[3][3];
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            temp[i][j] = matrix[j][2 - i];
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            matrix[i][j] = temp[i][j];
    printf("\nMatrix after trasformation:\n");
    printMatrix(matrix);
}

void rotateRight(int matrix[3][3]) {
    printf("Matrix before trasformation: \n");
    printMatrix(matrix);
    int temp[3][3];
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            temp[i][j] = matrix[2 - j][i];
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            matrix[i][j] = temp[i][j];
    printf("\nMatrix after trasformation:\n");
    printMatrix(matrix);
}

void rotate180(int matrix[3][3]) {
    printf("Matrix before trasformation: \n");
    printMatrix(matrix);
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            matrix[i][j] = matrix[2 - i][2 - j];
    printf("\nMatrix after trasformation:\n");
    printMatrix(matrix);
}

void rotateVertical(int matrix[3][3]) {
    printf("Matrix before trasformation: \n");
    printMatrix(matrix);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++) {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[i][2 - j];
            matrix[i][2 - j] = temp;
        }
    }
    printf("\nMatrix after trasformation:\n");
    printMatrix(matrix);
}

void rotateHorizontal(int matrix[3][3]) {
    printf("Matrix before trasformation: \n");
    printMatrix(matrix);
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[2 - i][j];
            matrix[2 - i][j] = temp;
        }
    }
    printf("\nMatrix after trasformation:\n");
    printMatrix(matrix);
}
