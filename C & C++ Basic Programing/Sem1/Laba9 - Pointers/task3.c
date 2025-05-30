#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define MAX_SIZE 25

void bubbleSort(int *arr, int n);
void shuffle(int *arr, int n);
void shellSort(int *arr, int n);
void hoarSort(int *arr, int low, int high);
void printArray(int *arr, int n);
bool continueProgram();

int main() {
    int arr[MAX_SIZE];
    int n;

    do {
        printf("Enter the number of elements (at least 10): ");
        scanf("%d", &n);
        if (n < 10 && n > MAX_SIZE) {
            printf("Invalid number of elements. Please enter a number between 10 and %d.\n", MAX_SIZE);
            continue;
        }

        printf("Enter the elements (separated by spaces): ");
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }

        bubbleSort(arr, n);
        printf("Array after Bubble Sort: ");
        printArray(arr, n);

        shuffle(arr, n);
        printf("Array after Shuffle: ");
        printArray(arr, n);

        shellSort(arr, n);
        printf("Array after Shell Sort: ");
        printArray(arr, n);

        shuffle(arr, n);
        shuffle(arr, n);
        printf("Array after Shuffle: ");
        printArray(arr, n);

        hoarSort(arr, 0, n - 1);
        printf("Array after Hoar Sort: ");
        printArray(arr, n);
    } while (continueProgram());

    return 0;
}

void bubbleSort(int *arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (*(arr + j) > *(arr + j + 1)) {
                int temp = *(arr + j);
                *(arr + j) = *(arr + j + 1);
                *(arr + j + 1) = temp;
            }
        }
    }
}

void shuffle(int *arr, int n) {
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        int randIndex = rand() % n;
        int temp = *(arr + i);
        *(arr + i) = *(arr + randIndex);
        *(arr + randIndex) = temp;
    }
}

void shellSort(int *arr, int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = *(arr + i);
            int j = i;
            while (j >= gap && *(arr + j - gap) > temp) {
                *(arr + j) = *(arr + j - gap);
                j -= gap;
            }
            *(arr + j) = temp;
        }
    }
}

void hoarSort(int *arr, int low, int high) {
    if (low < high) {
        int pivot = *(arr + low);
        int i = low - 1;
        int j = high + 1;

        while (1) {
            do {
                i++;
            } while (*(arr + i) < pivot);
            
            do {
                j--;
            } while (*(arr + j) > pivot);
            
            if (i >= j)
                break;

            int temp = *(arr + i);
            *(arr + i) = *(arr + j);
            *(arr + j) = temp;
        }

        hoarSort(arr, low, j);
        hoarSort(arr, j + 1, high);
    }
}

void printArray(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", *(arr + i));
    }
    printf("\n");
}

bool continueProgram() {
    char choice;
    do {
        printf("\nDo you want to continue with a new array? (+/-): ");
        scanf(" %c", &choice);
        if (choice != '+' && choice != '-') {
            printf("Invalid input. Please try again.\n");
        }
    } while (choice != '+' && choice != '-');
    return (choice == '+');
}
