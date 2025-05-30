#include <stdio.h>
int main() {
	float cels, farng;
	printf("Enter your temperature for convert from Celsius to Fahrenheit: ");
	scanf("%f", &cels);
	farng = cels * 9 / 5 + 32;
	printf("Result: %.2f \n", farng);
	return 0;
}