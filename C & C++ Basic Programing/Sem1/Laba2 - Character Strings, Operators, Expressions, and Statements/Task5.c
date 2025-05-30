#include <stdio.h>

int main(void) {
    float n;
    int i = 1;
    printf("Watch out! Here come a bunch of fractions!\n");

    while (i < 30) {
        n = 1.0 / i;
        printf("%d: %f\n", i, n);
        i++;
    }
    printf("That's all, folks!\n");

    return 0;
}
