#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUMBER 100

void initialize_number_generator(void);
int choose_new_secret_number(void);
void read_guesses(int* num, int secret_num);
void continueProgram(char* choice);

int main(void) {
    char choice;
    int secret_number;
    int num_guesses = 0;

    initialize_number_generator();

    do {
        secret_number = choose_new_secret_number();
        printf("A new number has been chosen.\n");
        read_guesses(&num_guesses, secret_number);
        continueProgram(&choice);
    } while (choice == '+');
    
    return 0;
}

void continueProgram(char* choice) {
    printf("\nIf you want to continue, enter '+' or '-': ");
    while (scanf(" %c", choice) != 1 || (*choice != '+' && *choice != '-')) {
        printf("Invalid input. Please enter '+' or '-': ");
        while (getchar() != '\n');
    }
    while (getchar() != '\n');
}

void initialize_number_generator(void) {
    srand((unsigned) time(NULL));
}

int choose_new_secret_number(void) {
    return rand() % MAX_NUMBER + 1;
}

void read_guesses(int* num, int secret_num) {
    int guess;
    while (1) {
        printf("Enter guess: ");
        scanf("%d", &guess);

        (*num)++;
        
        if (guess == secret_num) {
            printf("You won in %d guesses!\n\n", *num);
            return;
        } else if (guess < secret_num) {
            printf("Too low; try again.\n");
        } else {
            printf("Too high; try again.\n");
        }
    }
}
