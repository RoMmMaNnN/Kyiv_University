#include <stdio.h>

#define ROWS 14
#define COLS 14

void createArray(int arr[ROWS][COLS]);
void printArray(int arr[ROWS][COLS]);

int main(void) {
    int data[ROWS][COLS];

    createArray(data);
    printArray(data);

    int *p1 = &data[7][7];
    int *a = &data[5][1];
    int **p2 = &a;
    int (*p3)[COLS] = data;
    
    printf("Address and value of data[7][7]: %p\t%d\n", p1, *p1);
    printf("Address and value of data[5][1]: %p\t%d\n", p2, **p2);
    printf("Address and value of data[5][6]: %p\t%d\n", p3, p3[5][6]);

    **p2 = 777;
    printArray(data);

    return 0;
}

void createArray(int arr[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            arr[i][j] = i * COLS + j;
        }
    }
}

void printArray(int arr[ROWS][COLS]) {
    printf("\nArray: \n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%5d", arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
