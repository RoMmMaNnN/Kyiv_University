#include <stdio.h>
#include <stdbool.h>

bool continueProgram();
void input(double *r, double *a, double *b);
void solution(double r, double a, double b, double *CircleArea, double *l, double *AreaRectangle, double *P);
void printResult(double CircleArea, double l, double AreaRectangle, double P);

int main() {
    double r, a, b, CircleArea, l, AreaRectangle, P;

    do {
        input(&r, &a, &b);
        solution(r, a, b, &CircleArea, &l, &AreaRectangle, &P);
        printResult(CircleArea, l, AreaRectangle, P);
    } while (continueProgram());

    return 0;
}

bool continueProgram() {
    char choice;
    do {
        printf("\nDo you want to continue? (+/-): ");
        scanf(" %c", &choice);
        if (choice != '+' && choice != '-') {
            printf("Invalid input. Please try again.\n");
        }
    } while (choice != '+' && choice != '-');
    return (choice == '+');
}

void input(double *r, double *a, double *b) {
    do {
        printf("Enter the radius of the circle: ");
        scanf("%lf", r);
        if (*r <= 0) {
            printf("\nPlease enter a positive value.\n");
        }
    } while (*r <= 0);

    do {
        printf("\nEnter the length of the rectangle: ");
        scanf("%lf", a);
        printf("\nEnter the width of the rectangle: ");
        scanf("%lf", b);
        if (*a <= 0 && *b <= 0) {
            printf("\nPlease enter positive values for both length and width.\n");
        }
    } while (*a <= 0 && *b <= 0);
}

void solution(double r, double a, double b, double *CircleArea, double *l, double *AreaRectangle, double *P) {
    double PI = 3.14;
    *CircleArea = PI * r * r;
    *l = 2 * PI * r;
    *AreaRectangle = a * b;
    *P = 2 * (a + b);
}

void printResult(double CircleArea, double l, double AreaRectangle, double P) {
    printf("\nArea of the circle = %.2f square units\n", CircleArea);
    printf("\nCircumference of the circle = %.2f units\n", l);
    printf("\nArea of the rectangle = %.2f square units\n", AreaRectangle);
    printf("\nPerimeter of the rectangle = %.2f units\n", P);
}
