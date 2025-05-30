#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void continue_program(char* choice);
void initialize_number_generator(void);
int dice_roll();

int main() {
    int num_throws;
    char choice;

    do{
        printf("Enter the number of throws: ");
        scanf("%d", &num_throws);

        for (int i = 0; i < num_throws; i++) {
            int die1 = dice_roll();
            int die2 = dice_roll();
            printf("Throw %d: Die 1 = %d, Die 2 = %d\n", i + 1, die1, die2);
        }
        continue_program(&choice);
    } while (choice == '+');
    return 0;
}

void initialize_number_generator(void) {
    srand((unsigned) time(NULL));
}

int dice_roll() {
    return (rand() % 9) + 1;
}

void continue_program(char* choice) {
    printf("\nIf you want to continue, enter '+' or '-': ");
    while (scanf(" %c", choice) != 1 || (*choice != '+' && *choice != '-')) {
        printf("Invalid input. Please enter '+' or '-': ");
        while (getchar() != '\n');
    }
    while (getchar() != '\n');
}