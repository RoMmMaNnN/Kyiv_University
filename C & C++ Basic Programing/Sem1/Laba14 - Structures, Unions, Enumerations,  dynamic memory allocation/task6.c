#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[100];
    float score;
} Student;

void getNumber(int* n);
void newMemory(Student** students, int n);
void addStudents(Student* students, int n);
void getAverage(Student* students, int n, float* average);
void printAllStudents(Student* students, int n);
void printAboveAverage(Student* students, int n, float average);

int main() {
    int n;
    Student* students;
    float average;

    getNumber(&n);
    newMemory(&students, n);
    addStudents(students, n);
    getAverage(students, n, &average);
    printAllStudents(students, n);
    printAboveAverage(students, n, average);

    free(students);
    return 0;
}

void getNumber(int* n) {
    printf("Number of students: ");
    while (scanf("%d", n) != 1 || *n <= 0) {
        printf("Invalid! Try again: ");
        while (getchar() != '\n');
    }
}

void newMemory(Student** students, int n) {
    *students = (Student*)malloc(n * sizeof(Student));
    if (!*students) {
        printf("Memory error!\n");
        exit(1);
    }
}

void addStudents(Student* students, int n) {
    for (int i = 0; i < n; i++) {
        printf("\nStudent %d:\n", i + 1);
        printf("Name: ");
        scanf(" %[^\n]", students[i].name);
        printf("Grade: ");
        while (scanf("%f", &students[i].score) != 1 || students[i].score < 0) {
            printf("Invalid! Try again: ");
            while (getchar() != '\n');
        }
    }
}

void getAverage(Student* students, int n, float* average) {
    float sum = 0;
    for (int i = 0; i < n; i++) {
        sum += students[i].score;
    }
    *average = sum / n;
}

void printAllStudents(Student* students, int n) {
    printf("\nAll students:\n");
    for (int i = 0; i < n; i++) {
        printf("%d. %s - %.2f\n", i + 1, students[i].name, students[i].score);
    }
}

void printAboveAverage(Student* students, int n, float average) {
    printf("\nAverage grade: %.2f\n", average);
    printf("Students above average:\n");
    int found = 0;
    for (int i = 0; i < n; i++) {
        if (students[i].score > average) {
            printf("%s - %.2f\n", students[i].name, students[i].score);
            found = 1;
        }
    }
    if (!found) {
        printf("No students above average.\n");
    }
}
