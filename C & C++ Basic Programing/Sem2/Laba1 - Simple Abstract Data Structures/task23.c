#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NHASH 11
#define MULTIPLIER 31

typedef struct Point {
    double x, y;
    struct Point *next;
} Point;

Point *symtab[NHASH];

unsigned int hash(double x, double y) {
    unsigned int h = 0;
    h = MULTIPLIER * h + (x * 1000);
    h = MULTIPLIER * h + (y * 1000);
    return h % NHASH;
}

Point *lookup(double x, double y, int create) {
    int h = hash(x, y);
    Point *point;

    for (point = symtab[h]; point != NULL; point = point->next) {
        if (fabs(point->x - x) < 0.0001 && fabs(point->y - y) < 0.0001) return point;
    }

    if (create) {
        point = (Point *)malloc(sizeof(Point));
        if (!point) {
            perror("Memory allocation failed");
            exit(EXIT_FAILURE);
        }
        point->x = x;
        point->y = y;
        point->next = symtab[h];
        symtab[h] = point;
    }
    return point;
}

int main() {
    Point *node = lookup(1.1, 2.2, 1);
    printf("Point: (%.2f, %.2f)\n", node->x, node->y);

    node = lookup(3.3, 4.4, 1);
    printf("Point: (%.2f, %.2f)\n", node->x, node->y);

    return 0;
}
