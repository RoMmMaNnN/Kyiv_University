#include <stdio.h>

#define BOOK "Kobzar"

int main() {
	
	float cost = 9.49;
	float percent = 80.00;
	printf("This copy of %s sells for $%.2f\n", BOOK, cost);
	printf("That is %.2f%% of list\n", percent);

	return 0;
}
