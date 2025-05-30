#include <stdio.h>

#define FORMAT "%s! C is cool!\n"

int main(void) {
    int num = 10; // створили та надали значення 10 змінній
    printf(FORMAT, FORMAT); // виведить: "%s! C is cool!" і з нового рядку"! C is cool!"
    printf("%d\n", ++num);  // додасть 1, тобто буде число 11 і потім виводить 11
    printf("%d\n", num++);  // виводить 11 і потім збільшує num на 1, тобто 12
    printf("%d\n", num--);  // виводить 11 і потім зменшує num на 1, тобто 11
    printf("%d\n", num);    // виводить 11
    return 0;
}
