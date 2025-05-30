#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NHASH 11
#define MULTIPLIER 31

typedef struct Nameval Nameval;

struct Nameval {
    char *name;
    int value;
    Nameval *next;
};

Nameval *symtab[NHASH];

unsigned int hash(char *str) {
    unsigned int h = 0;
    unsigned char *p;
    for (p = (unsigned char *)str; *p != '\0'; p++)
        h = MULTIPLIER * h + *p;
    return h % NHASH;
}

Nameval *lookup(char *name, int create, int value) {
    int h = hash(name);
    Nameval *sym;
    
    for (sym = symtab[h]; sym != NULL; sym = sym->next) {
        if (strcmp(name, sym->name) == 0)
            return sym;
    }

    if (create) {
        sym = (Nameval *)malloc(sizeof(Nameval));
        if (!sym) {
            perror("Memory allocation failed");
            exit(EXIT_FAILURE);
        }
        sym->name = strdup(name);
        sym->value = value;
        sym->next = symtab[h];
        symtab[h] = sym;
    }

    return sym;
}

int main(void) {
    Nameval *node = lookup("Billy", 1, 12);
    printf("%s %d\n", node->name, node->value);

    return 0;
}