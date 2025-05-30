#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NHASH 11

typedef struct Nameval {
    char *name;
    int value;
    struct Nameval *next;
} Nameval;

unsigned int hash(char *str, int multiplier);
Nameval *lookup(char *name, int create, int multiplier, Nameval *symtab[]);
void chain_lengths(Nameval *symtab[]);
void add_symtab_data(char *data[], int multiplier, Nameval *symtab[]);
Nameval *iterate_next(Nameval *symtab[], int *bucket, Nameval **current);

int main(void) {
    char *data[] = {
        "apple", "tomato", "cherry", "ananas", "banana",
        "nfsjgljwjtauoigjwfiweiuroiw",
        "https://www.rozetka.com",
        "http://bebebe.url",
        "apple", "apple", "tomato", "tomato",
        NULL
    };
    int multipliers[] = {31, 32, 33, 34, 35, 36, 37, 0};
    Nameval *symtab[NHASH] = {0};

    for (int i = 0; multipliers[i] != 0; i++) {
        int multiplier = multipliers[i];

        add_symtab_data(data, multiplier, symtab);

        printf("\nResults for MULTIPLIER = %d:\n", multiplier);
        chain_lengths(symtab);

        printf("Iterating over elements:\n");
        int bucket = -1;
        Nameval *current = NULL;
        Nameval *item;
        while ((item = iterate_next(symtab, &bucket, &current)) != NULL) {
            printf("%s -> %d\n", item->name, item->value);
        }
    }

    return 0;
}

unsigned int hash(char *str, int multiplier) {
    unsigned int h = 0;
    unsigned char *p;
    for (p = (unsigned char *)str; *p != '\0'; p++) {
        h = multiplier * h + *p;
    }
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

Nameval *iterate_next(Nameval *symtab[], int *bucket, Nameval **current) {
    if (*current && (*current)->next) {
        *current = (*current)->next;
        return *current;
    }

    while (++(*bucket) < NHASH) {
        if (symtab[*bucket]) {
            *current = symtab[*bucket];
            return *current;
        }
    }

    return NULL;
}
