#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Employee {
    char name[15];
    double hours;
    double rate;
    struct Employee *next;
} Employee;

Employee *add_employee(Employee *head);
void read_employee_data(char *name, double *hours, double *rate);
double calculate_salary(double hours, double rate);
void print_salaries(Employee *head);
void free_list(Employee *head);
void clear_bufer();

int main() {
    Employee *head = NULL;
    char choice;

    do {
        head = add_employee(head);
        printf("Do you want to add another employee? (y/n): ");
        scanf(" %c", &choice);
        clear_bufer();
    } while (choice == 'y' || choice == 'Y');

    print_salaries(head);
    free_list(head);
    return 0;
}

void read_employee_data(char *name, double *hours, double *rate) {
    printf("Enter employee name: ");
    if (fgets(name, 15, stdin) == NULL) {
        printf("Error reading name.\n");
        exit(EXIT_FAILURE);
    }
    
    size_t len = strlen(name);
    if (len > 0 && name[len - 1] == '\n') {
        name[len - 1] = '\0';
    }

    do {
        printf("Enter hours worked: ");
        if (scanf("%lf", hours) != 1 || *hours < 0) {
            printf("Invalid input. Please enter a valid number.\n");
            clear_bufer();
        } else {
            break;
        }
    } while (1);

    do {
        printf("Enter hourly rate: ");
        if (scanf("%lf", rate) != 1 || *rate < 0) {
            printf("Invalid input. Please enter a valid number.\n");
            clear_bufer();
        } else {
            break;
        }
    } while (1);
    clear_bufer();
}


Employee *add_employee(Employee *head) {
    Employee *new_emp = (Employee *)malloc(sizeof(Employee));
    if (!new_emp) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    read_employee_data(new_emp->name, &new_emp->hours, &new_emp->rate);
    new_emp->next = head;
    return new_emp;
}

double calculate_salary(double hours, double rate) {
    return hours * rate;
}

void print_salaries(Employee *head) {
    printf("\nEmployee Salaries:\n");
    while (head) {
        printf("%s worked %.2f hours at %.2f per hour. Total salary: %.2f\n",
               head->name, head->hours, head->rate, calculate_salary(head->hours, head->rate));
        head = head->next;
    }
}

void free_list(Employee *head) {
    while (head) {
        Employee *temp = head;
        head = head->next;
        free(temp);
    }
}

void clear_bufer(){
    while (getchar() != '\n');    
}