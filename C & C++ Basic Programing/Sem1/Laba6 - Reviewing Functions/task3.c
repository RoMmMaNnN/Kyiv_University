#include <stdio.h>
#include <math.h>

void printTable1();
void printTable2();
int factorial(int n);
double MyCos(double x);

int main() {
    printTable1();
    printTable2();
    printf("\n\nя думаю що якщо збільшити число і з десяти то обчислення будуть більш точними");
    return 0;
}

int factorial(int n) {
    int result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

double MyCos(double x) {
    double sum = 0.0;
    for (int i = 0; i < 10; i++) {
        double term = pow(-1, i) * pow(x, 2 * i) / factorial(2 * i);
        sum += term;
    }
    return sum;
}

void printTable1() {
    printf("┌─────────┬───────────────┬───────────────┐\n");
    printf("│    x    │   Mycos(x)    │    Cos(x)     │\n");
    printf("├─────────┼───────────────┼───────────────┤\n");

    for (double x = 0.0; x <= 1.0; x += 0.1) {
        double Mycos = MyCos(x);
        double Cos = cos(x);

        printf("│ %7.1f │ %13.3f │ %13.3f │\n", x, Mycos, Cos);
    }

    printf("└─────────┴───────────────┴───────────────┘\n");
}

void printTable2() {
    printf("┌─────────┬─────────────────┬─────────────────┐\n");
    printf("│    x    │   Mycos(x)      │    Cos(x)       │\n");
    printf("├─────────┼─────────────────┼─────────────────┤\n");

    for (double x = 0.0; x <= 1.0; x += 0.1) {
        double Mycos = MyCos(x);
        double Cos = cos(x);

        printf("│ %7.1f │ %15.12f │ %15.12f │\n", x, Mycos, Cos);
    }

    printf("└─────────┴─────────────────┴─────────────────┘\n");
}