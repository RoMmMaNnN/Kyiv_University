#include <stdio.h>

int main() {
	int t = 2;
	printf("t = %d was before math operations\n", t);
	t += 5;
	printf("After +5 t = %d\n", t);
	t *= 10;
	printf("After *10 t = %d\n", t);
	t -= 6;
	printf("After -6 t = %d\n", t);
	t /= 8;
	printf("After /8 t = %d\n", t);
	t %= 3;
	printf("After /3 as a whole t = %d\n", t);
	return 0;
}