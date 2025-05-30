#include <stdio.h>

typedef struct {
    int Hours;
    int Minutes;
    float seconds;
} Time;

void input_time(Time *time);
void output_time(Time *time);
void validate_time(Time *time, int *valid);

int main() {
    Time time;

    input_time(&time);
    output_time(&time);

    return 0;
}

void input_time(Time *time) {
    int valid = 0;
    while (!valid) {
        printf("Enter time (hours minutes seconds): \n");
        scanf("%d %d %f", &time->Hours, &time->Minutes, &time->seconds);

        validate_time(time, &valid);
        if (!valid) {
            printf("Invalid time entered. Please try again.\n");
        }
    }
}

void output_time(Time *time) {
    printf("Time: %02d:%02d:%05.2f\n", time->Hours, time->Minutes, time->seconds);
}

void validate_time(Time *time, int *valid) {
    if (time->Hours < 0 || time->Hours > 23 || 
        time->Minutes < 0 || time->Minutes > 59 || 
        time->seconds < 0.0 || time->seconds >= 60.0) {
        *valid = 0;
    } else {
        *valid = 1;
    }
}
