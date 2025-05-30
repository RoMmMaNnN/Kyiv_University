#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NHASH 11
#define MULTIPLIER 31
#define PART_TABLE 0.2
#define GROW 2

typedef struct Nameval Nameval;

struct Nameval {
    char *name;
    int value;
    Nameval *next;
};

Nameval *symtab[NHASH];
int current_size = 0;
int current_table_size = NHASH;

unsigned int hash(char *str) {
    unsigned int h = 0;
    unsigned char *p;
    for (p = (unsigned char *)str; *p != '\0'; p++)
        h = MULTIPLIER * h + *p;
    return h % current_table_size;
}

void grow_table() {
    int new_size = current_table_size * GROW;
    Nameval *new_symtab[new_size];

    for (int i = 0; i < new_size; i++) {
        new_symtab[i] = NULL;
    }

    for (int i = 0; i < current_table_size; i++) {
        Nameval *sym = symtab[i];
        while (sym != NULL) {
            int h = hash(sym->name) % new_size;
            Nameval *next = sym->next;
            sym->next = new_symtab[h];
            new_symtab[h] = sym;
            sym = next;
        }
    }

    for (int i = 0; i < new_size; i++) {
        symtab[i] = new_symtab[i];
    }

    current_table_size = new_size;
}

Nameval *lookup(char *name, int create, int value) {
    double part_table = (double)current_size / current_table_size;
    if (part_table > PART_TABLE) {
        grow_table();
    }
    printf("\nCurrent size = %d\n", current_table_size);
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
        current_size++;
    }
    return sym;
}

int main(void) {
    Nameval *node = lookup("Billy", 1, 12);
    printf("%s %d\n", node->name, node->value);

    node = lookup("Bil", 1, 11);
    printf("%s %d\n", node->name, node->value);

    node = lookup("bob", 1, 22);
    printf("%s %d\n", node->name, node->value);
    
    node = lookup("boby", 1, 0);
    printf("%s %d\n", node->name, node->value);

    return 0;
}
