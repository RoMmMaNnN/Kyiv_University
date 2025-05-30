#include <stdio.h>

#define SIZE 20

void printArray(double *arr, int size);
double calculateSum(double *arr, int size);
double calculateAverage(double *arr, int size);

int main() {
    double a[SIZE] = {0.228952, 0.568418, 0.820277, 0.117099, 0.755212,
                      0.509299, 0.572073, 0.224526, 0.852861, 0.0612133,
                      0.175636, 0.568243, 0.0100543, 0.702012, 0.0345108,
                      0.146549, 0.189951, 0.144139, 0.261263, 0.474034};

    printArray(a, SIZE);

    printf("Кількість елементів масиву: %d\n", SIZE);

    double sum = calculateSum(a, SIZE);
    printf("Сума елементів масиву: %.6f\n", sum);

    double average = calculateAverage(a, SIZE);
    printf("Середнє значення елементів масиву: %.6f\n", average);

    return 0;
}

void printArray(double *arr, int size) {
    printf("Елементи масиву:\n");
    for (int i = 0; i < size; i++) {
        printf("%.6f ", arr[i]);
    }
    printf("\n");
}

double calculateSum(double *arr, int size) {
    double sum = 0.0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}

double calculateAverage(double *arr, int size) {
    double sum = calculateSum(arr, size);
    return sum / size;
}
