#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

void printArray(int arr[], int n);
void reverseArray(int arr[], int n);
void menu();
void input(int arr[], int n);
int checkChoice();
bool continueProgram();

int main() {
    int n;
    printf("Enter array size: ");
    while (scanf("%d", &n) != 1 && n <= 0) {
        printf("Invalid input! Enter a positive integer: ");
        while (getchar() != '\n');
    }

    int arr[n];
    do {
        menu();
        int choice = checkChoice();

        switch (choice) {
            case 1: 
                input(arr, n); 
                reverseArray(arr, n); 
                break;
            case 2: 
                for (int i = 0; i < n; i++) {
                    arr[i] = rand() % 100;
                }
                reverseArray(arr, n); 
                break;
            default: 
                printf("Invalid choice! Choose 1 or 2.\n"); 
                break;
        }

        printf("Array after processing:\n");
        printArray(arr, n);

    } while (continueProgram());

    return 0;
}

void reverseArray(int arr[], int n) {
    int temp;
    for (int i = 0; i < n / 2; i++) {
        temp = arr[i];
        arr[i] = arr[n - 1 - i];
        arr[n - 1 - i] = temp;
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void input(int arr[], int n) {
    printf("Enter %d array elements:\n", n);
    for (int i = 0; i < n; i++) {
        printf("%d) ", i + 1);
        while (scanf("%d", &arr[i]) != 1) {
            printf("Invalid input! Enter an integer for arr[%d]: ", i + 1);
            while (getchar() != '\n');
        }
    }
}

void menu() {
    printf("\nMenu:\n");
    printf("1. Enter array elements manually\n");
    printf("2. Generate random numbers\n");
}

int checkChoice() {
    int choice;
    printf("Your choice: ");
    while (scanf("%d", &choice) != 1 && (choice != 1 && choice != 2)) {
        printf("Invalid choice! Choose 1 or 2: ");
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
    