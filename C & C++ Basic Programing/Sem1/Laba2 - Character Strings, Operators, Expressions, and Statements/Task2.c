#include <stdio.h>
#include <string.h>

#define Q "his Halmet was funny without being vugar."

int main() {
    // a)
    printf("He sold the painting for $%.2f. \n", 2.345e2);
    // b)
    printf("%c%c%c \n", 'H', 'i', '!');
    // c)
    printf("%s\nhas %ld characters. \n", Q, strlen(Q));
    // d)
    float i2;
    i2 = 1201.1;
    printf("Is %.2e the same as %.2f \n", i2, i2);

    return 0;
}