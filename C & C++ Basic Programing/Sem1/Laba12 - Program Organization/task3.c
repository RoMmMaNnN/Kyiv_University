#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define STACK_SIZE 100

int push(int value);
int pop(int *value);
int peek(int *value);
int isEmpty();
void evaluateRPN();

int stack[STACK_SIZE];
int top = -1;

int main() {
    printf("Enter an RPN expression:\n");
    evaluateRPN();
    return 0;
}

int push(int value) {
    if (top >= STACK_SIZE - 1) {
        printf("Stack overflow! Program terminated.\n");
        return 0;
    }
    stack[++top] = value;
    return 1;
}

int pop(int *value) {
    if (isEmpty()) {
        printf("Stack underflow! Invalid expression.\n");
        return 0;
    }
    *value = stack[top--];
    return 1;
}

int peek(int *value) {
    if (isEmpty()) {
        printf("Stack is empty! Cannot peek.\n");
        return 0;
    }
    *value = stack[top];
    return 1;
}

int isEmpty() {
    return top == -1;
}

void evaluateRPN() {
    char ch;
    int exit = 0;

    while (!exit) {
        ch = getchar();

        if (isspace(ch)) {
            continue;
        }

        if (isdigit(ch) || (ch == '-' && isdigit(getchar()))) {
            ungetc(ch, stdin);
            int number;
            scanf("%d", &number);
            if (!push(number)) {
                return;
            }
        } else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^') {
            int a, b;
            if (!pop(&b) || !pop(&a)) {
                return;
            }
            int result = 0;

            switch (ch) {
                case '+': result = a + b; break;
                case '-': result = a - b; break;
                case '*': result = a * b; break;
                case '/':
                    if (b == 0) {
                        printf("Division by zero! Program terminated.\n");
                        return;
                    }
                    result = a / b;
                    break;
                case '^': result = (int)pow(a, b); break;
                default: break;
            }

            if (!push(result)) {
                return;
            }
        }

        else if (ch == '=') {
            if (top == 0) {
                int result;
                if (peek(&result)) {
                    printf("Value: %d\n", result);
                }
            } else {
                printf("Invalid RPN expression! Remaining elements in stack.\n");
            }
            top = -1;
            printf("Enter another RPN expression (or exit by entering invalid character):\n");
        }
        else {
            printf("Invalid character entered. Exiting program.\n");
            exit = 1;
        }
    }

    if (isEmpty()) {
        printf("Stack is empty. Program exited.\n");
    } else {
        printf("Stack is not empty. Program exited.\n");
    }
}
