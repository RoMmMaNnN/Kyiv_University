#include <stdio.h>

#define MAX_SIZE 20

void inputIntArray(int *arr, int n);
void printIntArray(int *arr, int n);
void sumArrays(int *arr1, int *arr2, int *arr3, int n);

int main() {
    int n;

    printf("Enter the number of elements in the arrays (max %d): ", MAX_SIZE);
    while (scanf("%d", &n) != 1 && n <= 0 && n > MAX_SIZE) {
        printf("Invalid input! Enter a positive integer between 1 and %d: ", MAX_SIZE);
        while (getchar() != '\n');
    }

    int arr1[n], arr2[n], arr3[n];

    printf("Enter elements for the first array:\n");
    inputIntArray(arr1, n);

    printf("Enter elements for the second array:\n");
    inputIntArray(arr2, n);

    sumArrays(arr1, arr2, arr3, n);

    printf("\nFirst array: ");
    printIntArray(arr1, n);

    printf("Second array: ");
    printIntArray(arr2, n);

    printf("Third array (sum of corresponding elements): ");
    printIntArray(arr3, n);

    return 0;
}

void inputIntArray(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("Element %d: ", i + 1);
        while (scanf("%d", &arr[i]) != 1) {
            printf("Invalid input! Enter an integer: ");
            while (getchar() != '\n');
        }
    }
}

void printIntArray(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void sumArrays(int *arr1, int *arr2, int *arr3, int n) {
    for (int i = 0; i < n; i++) {
        arr3[i] = arr1[i] + arr2[i];
    }
}
