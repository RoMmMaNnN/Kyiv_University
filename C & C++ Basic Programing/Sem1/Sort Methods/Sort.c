#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROWS 25
#define MAX_COLS 25

void continueProgram(char* choice);
void getUserChoice(int* option);
void inputRowsCols(int* n, int* m, int** arr);
void printMenu();
void printSortMethod(int option);
void doSort(int option, int n, int m, int* arr);
void createMatrix(int n, int m, int* arr);
void printArray(int n, int m, int* arr);
void printArrayIn1D(int n, int m, int* arr);
void copyArray(int n, int m, int* arr, int* copyArr);
void bubbleSortInRows(int n, int m, int* arr);
void bubbleSort(int n, int m, int* arr);
void selectionSortInRows(int n, int m, int* arr);
void selectionSort(int n, int m, int* arr);
void insertionSortInRows(int n, int m, int* arr);
void insertionSort(int n, int m, int* arr);
void quickSortInRows(int n, int m, int* arr);
void quickSort(int n, int m, int* arr);
void changeSortInRows(int n, int m, int* arr);
void changeSort(int n, int m, int* arr);
void shellSortInRows(int n, int m, int* arr);
void shellSort(int n, int m, int* arr);
void bubbleSortInRowsDescending(int n, int m, int* arr);
void bubbleSortDescending(int n, int m, int* arr);
void selectionSortInRowsDescending(int n, int m, int* arr);
void selectionSortDescending(int n, int m, int* arr);
void insertionSortInRowsDescending(int n, int m, int* arr);
void insertionSortDescending(int n, int m, int* arr);
void quickSortInRowsDescending(int n, int m, int* arr);
void quickSortDescending(int n, int m, int* arr);
void changeSortInRowsDescending(int n, int m, int* arr);
void changeSortDescending(int n, int m, int* arr);
void shellSortInRowsDescending(int n, int m, int* arr);
void shellSortDescending(int n, int m, int* arr);

int main() {
    int n, m, option;
    int* data = NULL;
    char choice = '+';

    srand(time(NULL));

    do {
        inputRowsCols(n, m, data);
        createMatrix(*n, *m, *data);
        printMenu();
        getUserChoice(&option);
        printf("Original Matrix:\n");
        printArray(n, m, data);
        doSort(option, n, m, data);
        printSortMethod(option);
        printArray(n, m, data);
        free(data);
        continueProgram(&choice);
    } while (choice == '+');

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

void getUserChoice(int* option) {
    while (scanf("%d", option) != 1) {
        printf("Invalid input. Please try again.\n");
        while (getchar() != '\n');
    }
}

void inputRowsCols(int* n, int* m, int** arr) {
    printf("Please enter size Matrix:\n");
    while (scanf("%d %d", n, m) != 2 || *n <= 0 || *m <= 0) {
        printf("Invalid input. Please enter positive integers for Rows and Cols:\n");
        while (getchar() != '\n');
    }

    while (*n > MAX_ROWS || *m > MAX_COLS) {
        printf("This size matrix too bigger. Please enter smaller size for matrix:\n");
        while (getchar() != '\n');
    }

    *arr = malloc((*n) * (*m) * sizeof(int));
    if (*arr == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
}

void printMenu() {
    printf("Menu:\n");
    printf("1) Bubble Sort ONLY in rows\n");
    printf("2) Bubble Sort entire array\n");
    printf("3) Selection Sort ONLY in rows\n");
    printf("4) Selection Sort entire array\n");
    printf("5) Insertion Sort ONLY in rows\n");
    printf("6) Insertion Sort entire array\n");
    printf("7) Quick Sort ONLY in rows\n");
    printf("8) Quick Sort entire array\n");
    printf("9) Change Sort ONLY in rows\n");
    printf("10) Change Sort entire array\n");
    printf("11) Shell Sort ONLY in rows\n");
    printf("12) Shell Sort entire array\n");
    printf("13) Bubble Sort ONLY in rows (descending)\n");
    printf("14) Bubble Sort entire array (descending)\n");
    printf("15) Selection Sort ONLY in rows (descending)\n");
    printf("16) Selection Sort entire array (descending)\n");
    printf("17) Insertion Sort ONLY in rows (descending)\n");
    printf("18) Insertion Sort entire array (descending)\n");
    printf("19) Quick Sort ONLY in rows (descending)\n");
    printf("20) Quick Sort entire array (descending)\n");
    printf("21) Change Sort ONLY in rows (descending)\n");
    printf("22) Change Sort entire array (descending)\n");
    printf("23) Shell Sort ONLY in rows (descending)\n");
    printf("24) Shell Sort entire array (descending)\n");
    printf("\nPlease enter your choice: ");
}

void printSortMethod(int option) {
    printf("\n");
    switch (option) {
        case 1: printf("Bubble Sort ONLY in rows:\n"); break;
        case 2: printf("Bubble Sort entire array:\n"); break;
        case 3: printf("Selection Sort ONLY in rows:\n"); break;
        case 4: printf("Selection Sort entire array:\n"); break;
        case 5: printf("Insertion Sort ONLY in rows:\n"); break;
        case 6: printf("Insertion Sort entire array:\n"); break;
        case 7: printf("Quick Sort ONLY in rows:\n"); break;
        case 8: printf("Quick Sort entire array:\n"); break;
        case 9: printf("Change Sort ONLY in rows:\n"); break;
        case 10: printf("Change Sort entire array:\n"); break;
        case 11: printf("Shell Sort ONLY in rows:\n"); break;
        case 12: printf("Shell Sort entire array:\n"); break;
        case 13: printf("Bubble Sort ONLY in rows (descending):\n"); break;
        case 14: printf("Bubble Sort entire array (descending):\n"); break;
        case 15: printf("Selection Sort ONLY in rows (descending):\n"); break;
        case 16: printf("Selection Sort entire array (descending):\n"); break;
        case 17: printf("Insertion Sort ONLY in rows (descending):\n"); break;
        case 18: printf("Insertion Sort entire array (descending):\n"); break;
        case 19: printf("Quick Sort ONLY in rows (descending):\n"); break;
        case 20: printf("Quick Sort entire array (descending):\n"); break;
        case 21: printf("Change Sort ONLY in rows (descending):\n"); break;
        case 22: printf("Change Sort entire array (descending):\n"); break;
        case 23: printf("Shell Sort ONLY in rows (descending):\n"); break;
        case 24: printf("Shell Sort entire array (descending):\n"); break;
        default: printf("Invalid Sort Method:\n"); break;
    }
}

void doSort(int option, int n, int m, int* arr) {
    switch (option) {
        case 1: bubbleSortInRows(n, m, arr); break;
        case 2: bubbleSort(n, m, arr); break;
        case 3: selectionSortInRows(n, m, arr); break;
        case 4: selectionSort(n, m, arr); break;
        case 5: insertionSortInRows(n, m, arr); break;
        case 6: insertionSort(n, m, arr); break;
        case 7: quickSortInRows(n, m, arr); break;
        case 8: quickSort(n, m, arr); break;
        case 9: changeSortInRows(n, m, arr); break;
        case 10: changeSort(n, m, arr); break;
        case 11: shellSortInRows(n, m, arr); break;
        case 12: shellSort(n, m, arr); break;
        case 13: bubbleSortInRowsDescending(n, m, arr); break;
        case 14: bubbleSortDescending(n, m, arr); break;
        case 15: selectionSortInRowsDescending(n, m, arr); break;
        case 16: selectionSortDescending(n, m, arr); break;
        case 17: insertionSortInRowsDescending(n, m, arr); break;
        case 18: insertionSortDescending(n, m, arr); break;
        case 19: quickSortInRowsDescending(n, m, arr); break;
        case 20: quickSortDescending(n, m, arr); break;
        case 21: changeSortInRowsDescending(n, m, arr); break;
        case 22: changeSortDescending(n, m, arr); break;
        case 23: shellSortInRowsDescending(n, m, arr); break;
        case 24: shellSortDescending(n, m, arr); break;
        default: printf("Invalid choice!\n"); return;
    }
}

void createMatrix(int n, int m, int* arr) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            *(arr + i * m + j) = rand() % 100;
        }
    }
}

void printArray(int n, int m, int* arr) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%5d", *(arr + i * m + j));
        }
        printf("\n");
    }
    printf("\n");
}

void printArrayIn1D(int n, int m, int* arr) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%5d", *(arr + i * m + j));
        }
    }
    printf("\n");
}

void copyArray(int n, int m, int* arr, int* copyArr) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            *(copyArr + i * m + j) = *(arr + i * m + j);
        }
    }
}

void bubbleSortInRows(int n, int m, int* arr) {
    int temp;
    int count = 1;

    for (int i = 0; i < n; i++) {
        while (count != 0) {
            count = 0;
            for (int j = 0; j < m - 1; j++) {
                int* current = arr + i * m + j;
                int* next = arr + i * m + j + 1;

                if (*current > *next) {
                    temp = *current;
                    *current = *next;
                    *next = temp;
                    count++;
                }
            }
        }
    }
}

void bubbleSort(int n, int m, int* arr) {
    int temp, count;
    int length = n * m;

    do {
        count = 0;
        for (int i = 0; i < length - 1; i++) {
            if (*(arr + i) > *(arr + i + 1)) {
                temp = *(arr + i);
                *(arr + i) = *(arr + i + 1);
                *(arr + i + 1) = temp;
                count++;
            }
        }
    } while (count != 0);
}


void selectionSortInRows(int n, int m, int* arr) {
    int temp, indexMin;

    for (int i = 0; i < n; i++) {
        for (int k = 0; k < m; k++) {
            indexMin = k;
            for (int l = k + 1; l < m; l++) {
                if (*(arr + i * m + l) < *(arr + i * m + indexMin)) {
                    indexMin = l;
                }
            }
            if (indexMin != k) {
                temp = *(arr + i * m + k);
                *(arr + i * m + k) = *(arr + i * m + indexMin);
                *(arr + i * m + indexMin) = temp;
            }
        }
    }
}

void selectionSort(int n, int m, int* arr) {
    int temp;
    int indexMin;
    int length = n * m;

    for (int i = 0; i < length - 1; i++) {
        indexMin = i;
        for (int j = i + 1; j < length; j++) {
            if (*(arr + j) < *(arr + indexMin)) {
                indexMin = j;
            }
        }
        if (indexMin != i) {
            temp = *(arr + i);
            *(arr + i) = *(arr + indexMin);
            *(arr + indexMin) = temp;
        }
    }
}

void insertionSortInRows(int n, int m, int* arr) {
    int temp, sorted;
    for (int k = 0; k < n; k++) {
        for (int i = 1; i < m; i++) {
            sorted = i - 1;
            while (sorted > -1 && *(arr + k * m + sorted) > *(arr + k * m + sorted + 1)) {
                temp = *(arr + k * m + sorted);
                *(arr + k * m + sorted) = *(arr + k * m + sorted + 1);
                *(arr + k * m + sorted + 1) = temp;
                sorted--;
            }
        }
    }
}

void insertionSort(int n, int m, int* arr) {
    int temp, sorted;
    int length = n * m;
    for (int i = 1; i < length; i++) {
        sorted = i - 1;
        while (sorted > -1 && *(arr + sorted) > *(arr + sorted + 1)) {
            temp = *(arr + sorted);
            *(arr + sorted) = *(arr + sorted + 1);
            *(arr + sorted + 1) = temp;
            sorted--;
        }
    }
}

void quickSortInRows(int n, int m, int* arr) {
    int temp;
    
    for (int i = 0; i < n; i++) {
        int left = 0;
        int right = m - 1;
        int* row = arr + i * m;

        while (left <= right) {
            while (row[left] < row[m / 2]) left++;
            while (row[right] > row[m / 2]) right--;

            if (left <= right) {
                temp = row[left];
                row[left] = row[right];
                row[right] = temp;
                left++;
                right--;
            }
        }
        if (right > 0) quickSortInRows(1, right + 1, row);
        if (left < m) quickSortInRows(1, m - left, row + left);
    }
}

void quickSort(int n, int m, int* arr) {
    int temp;
    int length = n * m;

    if (length <= 1) return;

    int pivot = *(arr + length / 2);
    int left = 0;
    int right = length - 1;

    while (left <= right) {
        while (*(arr + left) < pivot) left++;
        while (*(arr + right) > pivot) right--;
        if (left <= right) {
            temp = *(arr + left);
            *(arr + left) = *(arr + right);
            *(arr + right) = temp;
            left++;
            right--;
        }
    }
    if (right > 0) quickSort(1, right + 1, arr);
    if (left < length) quickSort(1, length - left, arr + left);
}

void changeSortInRows(int n, int m, int* arr) {
    int temp, indexMin, indexMax;

    for (int i = 0; i < n; i++) {
        for (int k = 0; k < m; k++) {
            indexMin = k;
            indexMax = k;
            for (int j = k + 1; j < m; j++) {
                if (*(arr + i * m + indexMin) > *(arr + i * m + j)) indexMin = j;
                if (*(arr + i * m + indexMax) < *(arr + i * m + j)) indexMax = j;
            }
            if (indexMin != k) {
                temp = *(arr + i * m + indexMin);
                *(arr + i * m + indexMin) = *(arr + i * m + k);
                *(arr + i * m + k) = temp;
            }
            if (indexMax == k) {
                indexMax = indexMin;
            }
            if (indexMax != k) {
                temp = *(arr + i * m + indexMax);
                *(arr + i * m + indexMax) = *(arr + i * m + k);
                *(arr + i * m + k) = temp;
            }
        }
    }
}


void changeSort(int n, int m, int* arr) {
    int temp, indexMax, indexMin;
    int length = n * m;
    for (int k = 0; k < length; k++) {
        indexMax = k;
        indexMin = k;
        for (int j = k + 1; j < length; j++) {
            if (*(arr + indexMin) > *(arr + j)) indexMin = j;
            if (*(arr + indexMax) < *(arr + j)) indexMax = j;
        }
        if (indexMin != k) {
            temp = *(arr + indexMin);
            *(arr + indexMin) = *(arr + k);
            *(arr + k) = temp;
        }
        if (indexMax == k) {
            indexMax = indexMin;
        }
        if (indexMax != k) {
            temp = *(arr + indexMax);
            *(arr + indexMax) = *(arr + k);
            *(arr + k) = temp;
        }
    }
}

void shellSortInRows(int n, int m, int* arr) {
    int temp, gap;

    for (int i = 0; i < n; i++) {
        for (gap = m / 2; gap > 0; gap /= 2) {
            for (int l = gap; l < m; l++) {
                temp = *(arr + i * m + l);
                int j = l;
                while (j >= gap && *(arr + i * m + j - gap) > temp) {
                    *(arr + i * m + j) = *(arr + i * m + j - gap);
                    j -= gap;
                }
                *(arr + i * m + j) = temp;
            }
        }
    }
}

void shellSort(int n, int m, int* arr) {
    int temp, gap;
    int length = n * m;
    for (gap = length / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < length; i++) {
            temp = *(arr + i);
            int j = i;
            while (j >= gap && *(arr + j - gap) > temp) {
                *(arr + j) = *(arr + j - gap);
                j -= gap;
            }
            *(arr + j) = temp;
        }
    }
}

void bubbleSortInRowsDescending(int n, int m, int* arr) {
    int temp;
    int count = 1;

    for (int i = 0; i < n; i++) {
        while (count != 0) {
            count = 0;
            for (int j = 0; j < m - 1; j++) {
                int* current = arr + i * m + j;
                int* next = arr + i * m + j + 1;

                if (*current < *next) {
                    temp = *current;
                    *current = *next;
                    *next = temp;
                    count++;
                }
            }
        }
    }
}

void bubbleSortDescending(int n, int m, int* arr) {
    int temp, count;
    int length = n * m;

    do {
        count = 0;
        for (int i = 0; i < length - 1; i++) {
            if (*(arr + i) > *(arr + i + 1)) {
                temp = *(arr + i);
                *(arr + i) = *(arr + i + 1);
                *(arr + i + 1) = temp;
                count++;
            }
        }
    } while (count != 0);
}

void selectionSortInRowsDescending(int n, int m, int* arr) {
    int temp, indexMax;

    for (int i = 0; i < n; i++) {
        for (int k = m - 1; k > -1; k--) {
            indexMax = k;
            for (int l = k - 1; l > -1; l--) {
                if (*(arr + i * m + l) < *(arr + i * m + indexMax)) {
                    indexMax = l;
                }
            }
            if (indexMax != k) {
                temp = *(arr + i * m + k);
                *(arr + i * m + k) = *(arr + i * m + indexMax);
                *(arr + i * m + indexMax) = temp;
            }
        }
    }
}

void selectionSortDescending(int n, int m, int* arr) {
    int temp;
    int indexMax;
    int length = n * m;

    for (int i = 0; i < length - 1; i++) {
        indexMax = i;
        for (int j = i + 1; j < length; j++) {
            if (*(arr + j) > *(arr + indexMax)) {
                indexMax = j;
            }
        }
        if (indexMax != i) {
            temp = *(arr + i);
            *(arr + i) = *(arr + indexMax);
            *(arr + indexMax) = temp;
        }
    }
}

void insertionSortInRowsDescending(int n, int m, int* arr) {
    int temp, sorted;
    for (int k = 0; k < n; k++) {
        for (int i = 1; i < m; i++) {
            sorted = i - 1;
            while (sorted > -1 && *(arr + k * m + sorted) < *(arr + k * m + sorted + 1)) {
                temp = *(arr + k * m + sorted);
                *(arr + k * m + sorted) = *(arr + k * m + sorted + 1);
                *(arr + k * m + sorted + 1) = temp;
                sorted--;
            }
        }
    }
}

void insertionSortDescending(int n, int m, int* arr) {
    int temp, sorted;
    int length = n * m;
    for (int i = 1; i < length; i++) {
        sorted = i - 1;
        while (sorted > -1 && *(arr + sorted) < *(arr + sorted + 1)) {
            temp = *(arr + sorted);
            *(arr + sorted) = *(arr + sorted + 1);
            *(arr + sorted + 1) = temp;
            sorted--;
        }
    }
}

void quickSortInRowsDescending(int n, int m, int* arr) {
    int temp;
    
    for (int i = 0; i < n; i++) {
        int left = 0;
        int right = m - 1;
        int* row = arr + i * m;

        while (left <= right) {
            while (row[left] > row[m / 2]) left++;
            while (row[right] < row[m / 2]) right--;

            if (left <= right) {
                temp = row[left];
                row[left] = row[right];
                row[right] = temp;
                left++;
                right--;
            }
        }
        if (right > 0) quickSortInRowsDescending(1, right + 1, row);
        if (left < m) quickSortInRowsDescending(1, m - left, row + left);
    }
}

void quickSortDescending(int n, int m, int* arr) {
    int temp;
    int length = n * m;

    if (length <= 1) return;

    int pivot = *(arr + length / 2);
    int left = 0;
    int right = length - 1;

    while (left <= right) {
        while (*(arr + left) > pivot) left++;
        while (*(arr + right) < pivot) right--;
        if (left <= right) {
            temp = *(arr + left);
            *(arr + left) = *(arr + right);
            *(arr + right) = temp;
            left++;
            right--;
        }
    }
    if (right > 0) quickSortDescending(1, right + 1, arr);
    if (left < length) quickSortDescending(1, length - left, arr + left);
}

void changeSortInRowsDescending(int n, int m, int* arr) {
    int temp, indexMin, indexMax;

    for (int i = 0; i < n; i++) {
        for (int k = 0; k < m; k++) {
            indexMin = k;
            indexMax = k;
            for (int j = k + 1; j < m; j++) {
                if (*(arr + i * m + indexMin) < *(arr + i * m + j)) {
                    indexMin = j;
                }
            }
            for (int j = k + 1; j < m; j++) {
                if (*(arr + i * m + indexMax) > *(arr + i * m + j)) {
                    indexMax = j;
                }
            }
            if (indexMin != k) {
                temp = *(arr + i * m + indexMin);
                *(arr + i * m + indexMin) = *(arr + i * m + k);
                *(arr + i * m + k) = temp;
            }
            if (indexMax != k) {
                temp = *(arr + i * m + indexMax);
                *(arr + i * m + indexMax) = *(arr + i * m + k);
                *(arr + i * m + k) = temp;
            }
        }
    }
}

void changeSortDescending(int n, int m, int* arr) {
    int temp, indexMax, indexMin;
    int length = n * m;
    for (int k = 0; k < length; k++) {
        indexMax = k;
        indexMin = k;
        for (int j = k + 1; j < length; j++) {
            if (*(arr + indexMin) < *(arr + j)) indexMin = j;
            if (*(arr + indexMax) > *(arr + j)) indexMax = j;
        }
        if (indexMin != k) {
            temp = *(arr + indexMin);
            *(arr + indexMin) = *(arr + k);
            *(arr + k) = temp;
        }
        if (indexMax == k) {
            indexMax = indexMin;
        }
        if (indexMax != k) {
            temp = *(arr + indexMax);
            *(arr + indexMax) = *(arr + k);
            *(arr + k) = temp;
        }
    }
}

void shellSortInRowsDescending(int n, int m, int* arr) {
    int temp, gap;

    for (int i = 0; i < n; i++) {
        for (gap = m / 2; gap > 0; gap /= 2) {
            for (int l = gap; l < m; l++) {
                temp = *(arr + i * m + l);
                int j = l;
                while (j >= gap && *(arr + i * m + j - gap) < temp) {
                    *(arr + i * m + j) = *(arr + i * m + j - gap);
                    j -= gap;
                }
                *(arr + i * m + j) = temp;
            }
        }
    }
}

void shellSortDescending(int n, int m, int* arr) {
    int temp, gap;
    int length = n * m;

    for (gap = length / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < length; i++) {
            temp = *(arr + i);
            int j = i;
            while (j >= gap && *(arr + j - gap) < temp) {
                *(arr + j) = *(arr + j - gap);
                j -= gap;
            }
            *(arr + j) = temp;
        }
    }
}
