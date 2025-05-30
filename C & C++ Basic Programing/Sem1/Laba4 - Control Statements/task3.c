#include <stdio.h>
#include <math.h>

int main() {
	int n, i;
	double a, sum;
	char cont; 
	do {
        printf("Enter a natural number: ");
        scanf(" %d", &n);
        for (i = 1; i <= n; i++) {
        a = pow(-1, i + 1) / (2 * i - 1);
        sum += a;
	    }
        printf("\na = %lf\n", sum);
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