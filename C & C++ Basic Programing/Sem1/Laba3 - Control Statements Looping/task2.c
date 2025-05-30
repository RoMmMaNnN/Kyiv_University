#include <stdio.h>

int main() {
	int i;
	double value;
	for(value = 36, i = 1; value>=1; value/=2, i++) {
		printf("%d: %.4f\n", i, value);
	}
	return 0;
}