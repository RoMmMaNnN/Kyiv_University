#include <stdio.h>

#define MAX_SIZE 150

char message[MAX_SIZE], encryption[MAX_SIZE];
int length = 0;

void input();
void encrypt(int n);

int main() {
    int n;
    printf("\nEnter your message for encryption: ");
    input();
    printf("\nEnter the number of sides of the scytale: ");
    scanf("%d", &n);
    getchar();
    encrypt(n);
    printf("\nMessage is original: %s\n\nMessage is encryption: %s", message, encryption);
    return 0;
}

void input() {
    char ch;
    length = 0;
    while ((ch = getchar()) != '\n' && length < MAX_SIZE - 1) {
        message[length] = ch;
        length++;
    }
    message[length] = '\0';
}

void encrypt(int n) {
    int cols = n; 
    int rows = (length + cols - 1) / cols;
    char grid[rows][cols];
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int index = i * cols + j;
            if (index < length) {
                grid[i][j] = message[index];
            } else {
                grid[i][j] = ' ';
            }
        }
    }
    int pos = 0;
    for (int j = 0; j < cols; j++) {
        for (int i = 0; i < rows; i++) {
            if (grid[i][j] != ' ') {
                encryption[pos++] = grid[i][j];
            }
        }
    }
    encryption[pos] = '\0';
}
