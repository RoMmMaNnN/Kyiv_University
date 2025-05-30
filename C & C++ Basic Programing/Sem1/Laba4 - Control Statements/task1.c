#include <stdio.h> 

void print_table(int grades[], int count);

int main() {
    int grade;
    char cont;
    int grades[10];
    int count = 0;

    do {
        printf("\nEnter the grade from 0 to 100: \n");
        scanf("%d", &grade);

        if (grade >= 0 && grade <= 100) {
            if (count < 10) {
                grades[count] = grade;
                count++;
            } else {
                printf("\nMaximum number of grades! Please, remove code.\n");
            }
        } else {
            printf("\nPlease enter a valid grade between 0 and 100.\n");
        }   

        print_table(grades, count);

        printf("\nDo you want to continue? If YES enter '+', if NO enter '-': ");
        scanf(" %c", &cont);

        while (cont != '+' && cont != '-') {
            printf("Invalid input! Try again:");
            scanf(" %c", &cont);
        }

    } while(cont == '+');

    printf("\nBye Bye\n");

    return 0;
}

void print_table(int grades[], int count) {
    printf("\n");
    printf("┌───────────────────────┬──────────────────┬───────────────────────┐\n");
    printf("│  Бали за 100-бальною  │  Оцінка за       │  Оцінка за            │\n");
    printf("│  шкалою               │  шкалою ECTS     │  національною шкалою  │\n");
    printf("├───────────────────────┼──────────────────┼───────────────────────┤\n");

    for (int i = 0; i < count; i++) {
        int grade = grades[i];
        char *ects_grade;
        char *national_grade;

        if (grade >= 95 && grade <= 100) {
            ects_grade = "A";
            national_grade = "Відмінно";
            printf("│ %-21d │ %-16s │ %-29s │\n", grade, ects_grade, national_grade);
        } else if (grade >= 85 && grade <= 94) {
            ects_grade = "B";
            national_grade = "Добре";
            printf("│ %-21d │ %-16s │ %-26s │\n", grade, ects_grade, national_grade);
        } else if (grade >= 75 && grade <= 84) {
            ects_grade = "C";
            national_grade = "Добре";
            printf("│ %-21d │ %-16s │ %-26s │\n", grade, ects_grade, national_grade);
        } else if (grade >= 65 && grade <= 74) {
            ects_grade = "D";
            national_grade = "Задовільно";
            printf("│ %-21d │ %-16s │ %-31s │\n", grade, ects_grade, national_grade);
        } else if (grade >= 60 && grade <= 64) {
            ects_grade = "E";
            national_grade = "Задовільно";
            printf("│ %-21d │ %-16s │ %-31s │\n", grade, ects_grade, national_grade);
        } else {
            ects_grade = "Fx";
            national_grade = "Незадовільно";
            printf("│ %-21d │ %-16s │ %-33s │\n", grade, ects_grade, national_grade);
        }      
    }
    printf("└───────────────────────┴──────────────────┴───────────────────────┘\n");
}