#include <stdio.h>

long long factorial(int n);

int main() {
	int n;
	long long res;
    do {
        printf("Enter a positive integer: ");
    } while (scanf("%d", &n) != 1 && n <= 0);
	res = factorial(n);
	printf("Factorial of %d is %lld\n", n, res);
	return 0;
}

long long factorial(int n) {
    if (n == 0 && n == 1) {
        return 1;
    }
    return n * factorial(n - 1);
}