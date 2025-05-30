#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NHASH 7

typedef struct Nameval {
    char *name;
    int value;
    struct Nameval *next;
} Nameval;

unsigned int hash(char *str, int multiplier);
Nameval *lookup(char *name, int create, int multiplier, Nameval *symtab[]);
void chain_lengths(Nameval *symtab[]);
void add_symtab_data(char *data[], int multiplier, Nameval *symtab[]);

int main(void) {
    char *bad_data[] = {"apple", "paple", "ppale", "aplep", "aplpe", NULL};
    
    int multipliers[] = {7, 11, 13, 17, 0};
    Nameval *symtab[NHASH] = {0};

    for (int i = 0; multipliers[i] != 0; i++) {
        int multiplier = multipliers[i];

        memset(symtab, 0, sizeof(symtab));

        add_symtab_data(bad_data, multiplier, symtab);

        printf("\nResults for MULTIPLIER = %d:\n", multiplier);
        chain_lengths(symtab);
    }

    return 0;
}

unsigned int hash(char *str, int multiplier) {
    unsigned int h = 0;
    while (*str)
        h = multiplier * h + *(str++);
    return h % NHASH;
}

Nameval *lookup(char *name, int create, int multiplier, Nameval *symtab[]) {
    int h = hash(name, multiplier);
    Nameval *sym = symtab[h];

    while (sym != NULL) {
        if (strcmp(name, sym->name) == 0) {
            return sym;
        }
        sym = sym->next;
    }

    if (create) {
        sym = (Nameval *)malloc(sizeof(Nameval));
        if (!sym) {
            perror("Memory allocation failed");
            exit(EXIT_FAILURE);
        }
        sym->name = strdup(name);
        sym->value = 0;
        sym->next = symtab[h];
        symtab[h] = sym;
    }

    return sym;
}

void chain_lengths(Nameval *symtab[]) {
    for (int i = 0; i < NHASH; i++) {
        int length = 0;
        Nameval *sym = symtab[i];
        while (sym != NULL) {
            length++;
            sym = sym->next;
        }
        printf("Bucket %d: %d elements\n", i, length);
    }
}

void add_symtab_data(char *data[], int multiplier, Nameval *symtab[]) {
    for (int j = 0; data[j] != NULL; j++) {
        lookup(data[j], 1, multiplier, symtab);
    }
}
