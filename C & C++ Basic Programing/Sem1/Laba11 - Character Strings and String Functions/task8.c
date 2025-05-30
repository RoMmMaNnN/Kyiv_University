#include <stdio.h>

#define MAX_LINE_LENGTH 100
#define MAX_WORDS 10

void processFirstWord(char lines[][MAX_LINE_LENGTH], int numLines, char result[][MAX_LINE_LENGTH]);
void processWordsWithLimit(char lines[][MAX_LINE_LENGTH], int numLines, int wordLimit, char result[][MAX_WORDS][MAX_LINE_LENGTH]);

int main() {
    char lines[3][MAX_LINE_LENGTH] = {
        "Hello there how are you",
        "This is a test",
        "Another example line"
    };

    char result[3][MAX_LINE_LENGTH];
    
    processFirstWord(lines, 3, result);
    for (int i = 0; i < 3; i++) {
        printf("First word of line %d: %s\n", i + 1, result[i]);
    }

    int wordLimit = 3;
    char resultWithLimit[3][MAX_WORDS][MAX_LINE_LENGTH];
    
    processWordsWithLimit(lines, 3, wordLimit, resultWithLimit);
    for (int i = 0; i < 3; i++) {
        printf("First %d words from line %d: ", wordLimit, i + 1);
        for (int j = 0; j < wordLimit; j++) {
            if (resultWithLimit[i][j][0] != '\0') {
                printf("%s ", resultWithLimit[i][j]);
            }
        }
        printf("\n");
    }

    return 0;
}

void processFirstWord(char lines[][MAX_LINE_LENGTH], int numLines, char result[][MAX_LINE_LENGTH]) {
    for (int i = 0; i < numLines; i++) {
        int j = 0;
        for (int k = 0; k < MAX_LINE_LENGTH && lines[i][k] != ' ' && lines[i][k] != '\0'; k++) {
            result[i][j++] = lines[i][k];
        }
        result[i][j] = '\0';
    }
}

void processWordsWithLimit(char lines[][MAX_LINE_LENGTH], int numLines, int wordLimit, char result[][MAX_WORDS][MAX_LINE_LENGTH]) {
    for (int i = 0; i < numLines; i++) {
        int wordCount = 0, j = 0;
        for (int k = 0; k < MAX_LINE_LENGTH && wordCount < wordLimit; k++) {
            if (lines[i][k] == ' ') {
                if (j > 0) {
                    result[i][wordCount][j] = '\0';
                    wordCount++;
                    j = 0;
                }
            } else {
                result[i][wordCount][j++] = lines[i][k];
            }
        }
        if (j > 0) {
            result[i][wordCount][j] = '\0';
        }
    }
}
