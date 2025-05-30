#include <stdio.h>

void printArray(int n, int m, int arr[][]);
void sort_change(int (*ptr)[]);
void copyArray(int n, int m, int arr[][], copyArr[][]);
void quickSort(int n, int m, int arr[]);
void shellSort(int n, int m, int arr[]);
void insertionSortDescending(int n, int m, int arr[]);
void selectionSortDescending(int n, int m, int arr[]);

int main() {
    int data[4][10] = {
        {-22, 4, 5, 8, 0, 23, 1, -9, 2, 35},
        {-13, 5, 6, 9, 1, 0, 0, 0, 1, -13},
        {12, 10, 8, 6, 15, -3, -3, 0, -3, 1},
        {0, -45, 3, 12, 2, 0, -9, 7, 23, 21}
    };
    int copyData1[4][10], copyData2[4][10], copyData3[4][10], copyData4[4][10];

    printArray(4, 10, data);

    copyArray(4, 10, data, copyData1);
    quickSort(4, 10, data);
    printArray(4, 10, copyData1);

    copyArray(4, 10, data, copyData2);
    shellSort(4, 10, data);
    printArray(4, 10, copyData2);

    copyArray(4, 10, data, copyData3);
    insertionSortDescending(4, 10, copyData3);
    printArray(4, 10, copyData3);

    copyArray(4, 10, data, copyData4);
    selectionSortDescending(4, 10, copyData4);
    printArray(4, 10, copyData4);

    return 0;
}

void printArray(int n, int m, int arr[][]) {
    printf("Currency matrix: \n")
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%5d", arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void copyArray(int n, int m, int arr[][], int copyArr[][]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            dest[i][j] = src[i][j];
        }
    }
}

void sort_change(int (*ptr)[]) {

}

void quickSort(int n, int m, int arr[][]) {

}

void shellSort(int n, int m, int arr[][]) {

}

void insertionSortDescending(int n, int m, int arr[][]) {

}

void selectionSortDescending(int n, int m, int arr[][]) {

}
