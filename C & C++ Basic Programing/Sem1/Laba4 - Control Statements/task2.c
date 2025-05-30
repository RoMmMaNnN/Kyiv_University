#include <stdio.h>
#include <math.h>

int main() {
    double a, b, c, x, x1, x2;
    char cont;    
    do {
        printf("Enter a value for 'a', next 'b', next 'c': ");
        scanf("%lf %lf %lf", &a, &b, &c);
        if (a != 0) {
            double d = b * b - 4 * a * c;
            if (d >= 0) {
                x1 = (sqrt(d) - b) / (2 * a);
                x2 = (-sqrt(d) - b) / (2 * a);
                printf("\nX1 = %lf\nX2 = %lf\n", x1, x2);
            } else {
                printf("\nNo real roots exist.\n");
            }
        } else {
            if (b != 0) {
                x = -c / b;
                printf("\nX = %lf\n", x);
            } else {
                printf("\nValues are invalid\n");
            }
        }       
        printf("\nDo you want to continue? If YES enter '+', if NO enter '-': ");
        scanf(" %c", &cont);
        while (cont != '+' && cont != '-') {
            printf("Invalid input! Try again:");
            scanf(" %c", &cont);
        }
    } while (cont == '+');
    printf("\nBye Bye\n");
    return 0;
}
