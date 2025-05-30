#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Conversion {
    double meters;
    double feet;
    double inches;
    struct Conversion *next;
} Conversion;

Conversion *add_conversion(Conversion *head);
void read_conversion_data(double *meters);
void convert_and_print(double meters);
void print_conversions(Conversion *head);
void free_list(Conversion *head);
void clear_buffer();

int main() {
    Conversion *head = NULL;
    double meters;

    printf("Enter meters: ");
    scanf("%lf", &meters);
    clear_buffer();
        
    if (meters != 0) {
        head = add_conversion(head);
        convert_and_print(meters);
    }

    print_conversions(head);
    free_list(head);
    
    return 0;
}

void read_conversion_data(double *meters) {
    do {
        printf("Enter meters: ");
        if (scanf("%lf", meters) != 1 || *meters < 0) {
            printf("Invalid input. Please enter a valid number.\n");
            clear_buffer();
        } else {
            break;
        }
    } while (1);
}

void convert_and_print(double meters) {
    double feet = meters * 3.28084;
    double inches = feet * 12;

    printf("%.2f meters = %.2f feet = %.2f inches\n", meters, feet, inches);
}

Conversion *add_conversion(Conversion *head) {
    Conversion *new_conv = (Conversion *)malloc(sizeof(Conversion));
    if (!new_conv) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    new_conv->meters = 0;
    new_conv->feet = 0;
    new_conv->inches = 0;
    new_conv->next = head;
    return new_conv;
}

void print_conversions(Conversion *head) {
    printf("\nConversions completed:\n");
    while (head) {
        printf("Converted a value.\n");
        head = head->next;
    }
}

void free_list(Conversion *head) {
    while (head) {
        Conversion *temp = head;
        head = head->next;
        free(temp);
    }
}

void clear_buffer(){
    while (getchar() != '\n');
}
