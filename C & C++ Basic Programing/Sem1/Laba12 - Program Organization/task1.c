#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_NUM 10

const char *segments[10] = {
    " _ | ||_|", // 0
    "     |  |", // 1
    " _  _||_ ", // 2
    " _  _| _|", // 3
    "   |_|  |", // 4
    " _ |_  _|", // 5
    " _ |_ |_|", // 6
    " _   |  |", // 7
    " _ |_||_|", // 8
    " _ |_| _|", // 9
};

void input(char* arr);
void sevenSegmentDisplay(char* arr);

int main() {
    char inputNum[MAX_NUM + 1];

    printf("Enter a maximum of 10 numbers for the seven-segment display:\n");
    input(inputNum);
    sevenSegmentDisplay(inputNum);

    return 0;
}

void input(char* arr) {
    int i = 0;
    char ch;

    while (i < MAX_NUM && (ch = getchar()) != '\n') {
        if (isdigit(ch)) {
            arr[i++] = ch;
        }
    }
    arr[i] = '\0';
}

void sevenSegmentDisplay(char* arr) {
    char line1[MAX_NUM * 3 + 1] = "";
    char line2[MAX_NUM * 3 + 1] = "";
    char line3[MAX_NUM * 3 + 1] = "";

    for (int i = 0; arr[i] != '\0'; i++) {
        int num = arr[i] - '0';
        strncat(line1, segments[num], 3);
        strncat(line2, segments[num] + 3, 3);
        strncat(line3, segments[num] + 6, 3);
    }

    printf("%s\n%s\n%s\n", line1, line2, line3);
}
