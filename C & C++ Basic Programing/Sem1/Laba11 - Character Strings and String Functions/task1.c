#include <stdio.h>

char *pr(char *str);

int main() {
    char* x;
    x = pr("Ho Ho Ho!");
    puts(x);

    return 0;
}

char *pr(char *str) {
    char *pc;
    pc = str;
    while (*pc) putchar(*pc++);

    do {
        putchar(*--pc);
    } while (pc > str);

    return (pc);
}
