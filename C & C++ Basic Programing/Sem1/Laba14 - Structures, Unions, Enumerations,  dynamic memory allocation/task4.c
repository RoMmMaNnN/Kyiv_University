#include <stdio.h>
#include <stdbool.h>

typedef struct {
    int month;
    int year;
} Date;

bool isDateInRange(Date first, Date second, Date input);

int main() {
    Date first = {7, 2000};
    Date second = {7, 2024};
    Date input;

    printf("Enter the month and year of the date (format: month year): ");
    scanf("%d %d", &input.month, &input.year);

    printf(isDateInRange(first, second, input) ? "The date is in the range\n" : "Your date is not in the specified range\n");
    return 0;
}

bool isDateInRange(Date first, Date second, Date input) {
    return (input.year >= first.year && input.year <= second.year);
}
