#include <stdio.h>

void show1(const double arr1[], int n);
void show2(const double arr2[][3], int n);

int main(void) {
    printf("\nCalling show1() with a 1D array:\n");
    show1((const double[]){8, 3, 9, 2}, 4);

    printf("\nCalling show2() with a 2D array:\n");
    show2((const double[][3]){{8, 3, 9}, {5, 4, 1}}, 2);

    return 0;
}

void show1(const double arr1[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%.2f ", arr1[i]);
    }
    printf("\n");
}

void show2(const double arr2[][3], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%.2f ", arr2[i][j]);
        }
        printf("\n");
    }
}
