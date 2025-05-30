#include <stdio.h>

typedef struct {
    float Real;
    float Im;
} Complex;

void complex_add(Complex *z1, Complex *z2, Complex *result);
void complex_average(Complex *z1, Complex *z2, Complex *avg);

int main() {
    Complex z1, z2, avg;

    printf("Enter Re and Im parts of z1 separated by space: ");
    scanf("%f %f", &z1.Real, &z1.Im);

    printf("Enter Re and Im parts of z2 separated by space: ");
    scanf("%f %f", &z2.Real, &z2.Im);

    complex_average(&z1, &z2, &avg);

    printf("\nValue: %.2f + %.2fi, %.2f + %.2fi\n", z1.Real, z1.Im, z2.Real,z2.Im);
    printf("\nAverage: %.2f + %.2fi\n", avg.Real, avg.Im);

    return 0;
}

void complex_add(Complex *z1, Complex *z2, Complex *result) {
    result->Real = z1->Real + z2->Real;
    result->Im = z1->Im + z2->Im;
}

void complex_average(Complex *z1, Complex *z2, Complex *avg) {
    complex_add(z1, z2, avg);
    avg->Real /= 2.0;
    avg->Im /= 2.0;
}
