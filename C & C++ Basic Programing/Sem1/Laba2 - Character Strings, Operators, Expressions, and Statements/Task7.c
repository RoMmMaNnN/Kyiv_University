#include <stdio.h>

int main(void) {
    char c1, c2;
    int diff;
    float num;
    c1 = 'S';
    c2 = '0';
    diff = c1 - c2;
    num = (float)diff;
    printf("%c%c%c:%d %3.2f\n", c1, c2, c1, diff, num); 
    //виводить змінні с1 та с2 в порядку що виходить "SOS" 
    //і виводить різницю чисел номеру цих символі
    // потім перетворює цю різницю на тип даних чисел з плаваючою крапкою та виводить це значення
    return 0;
}
