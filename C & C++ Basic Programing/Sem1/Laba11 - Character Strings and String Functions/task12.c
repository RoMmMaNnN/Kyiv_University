#include <stdio.h>

void input(char *ctr);
void printReverse(char *str);

int main() {
    char str[100];
    
    printf("Enter a string: ");
    input(str);    
    printReverse(str);
    
    return 0;
}

void input(char *ch) {
    int i = 0;
    while ((ch[i++] = getchar()) != '\n' && i < 99);
    ch[i] = '\0';
}

void printReverse(char *str) {
    char *ptr = str;
    
    while (*ptr) ptr++;
    while (--ptr >= str) putchar(*ptr);
    putchar('\n');
}
