#include <stdio.h>

#define B "booboo"
#define X 10

int main() {
    int age; 
    char name[15];
    printf("Please enter your first name: ");
    scanf("%s", name);
    printf("All right, %s, what's your age? \n", name);
    scanf("%d", &age);
    int xp = age + X;
    printf("That's a %s! You must be at least %d.\n", B, xp);
    return 0;
}
