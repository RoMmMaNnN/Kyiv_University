#include <stdio.h>

int FindMaxInt(int arr[], int n);
int FindMaxIndexDouble(double arr[], int n);
void FindDifferenceDouble(double arr[], int n);

int main() {
    int n;
    
    printf("Enter length array(int) : ");
    scanf("%d", &n);
    
    int arrInt[n];
    printf("Enter %d elements of array:\n", n);
    for (int i = 0; i < n; i++) {
        printf("arrInt[%d] = ", i + 1);
        scanf("%d", &arrInt[i]);
    }

    int maxInt = FindMaxInt(arrInt, n);
    printf("Max value in array: %d\n", maxInt);

    printf("Enter length array(double) : ");
    scanf("%d", &n);
    
    double arrDouble[n];
    printf("Enter %d elements of array:\n", n);
    for (int i = 0; i < n; i++) {
        printf("arrDouble[%d] = ", i + 1);
        scanf("%lf", &arrDouble[i]);
    }

    int maxIndex = FindMaxIndexDouble(arrDouble, n);
    printf("Index of Max element: %d\n", maxIndex);

    FindDifferenceDouble(arrDouble, n);

    return 0;
}

int FindMaxInt(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int FindMaxIndexDouble(double arr[], int n) {
    int maxIndex = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] > arr[maxIndex]) {
            maxIndex = i;
        }
    }
    return maxIndex;
}

void FindDifferenceDouble(double arr[], int n) {
    double max = arr[0];
    double min = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    printf("Max - Min: %.2lf\n", max - min);
}
