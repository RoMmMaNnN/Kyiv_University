#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct Nameval {
    char *name;
    int value;
    struct Nameval *left;
    struct Nameval *right;
} Nameval;

Nameval* lookup(Nameval *treep, char *name);
Nameval* nrlookup(Nameval *treep, char *name);
Nameval* insert(Nameval *treep, Nameval *newp);
int isBalanced(Nameval *treep);
int height(Nameval *treep);
void generateData(Nameval **treep, int num);
void initializeRandomGenerator(void);
void printTreep(Nameval *treep);

int main(void) {
    Nameval *treep = NULL;
    
    initializeRandomGenerator();

    printf("Variant 1: Random order of insertion\n");
    generateData(&treep, 10);
    printTreep(treep);
    if (isBalanced(treep)) {
        printf("The tree is balanced.\n");
    } else {
        printf("The tree is not balanced.\n");
    }

    printf("\nVariant 2: Sorted order of insertion\n");
    treep = NULL;
    for (int i = 0; i < 10; i++) {
        Nameval *newv = (Nameval *)malloc(sizeof(Nameval));
        newv->name = (char *)malloc(10);
        snprintf(newv->name, 10, "Name%d", i);
        newv->value = i;
        treep = insert(treep, newv);
    }
    printTreep(treep);
    if (isBalanced(treep)) {
        printf("The tree is balanced.\n");
    } else {
        printf("The tree is not balanced.\n");
    }

    return 0;
}

void printTreep(Nameval *treep) {
    if (treep == NULL) return;

    printTreep(treep->left);
    printf("%s: %d\n", treep->name, treep->value);
    printTreep(treep->right);
}


Nameval* insert(Nameval *treep, Nameval *newp) {
    if (treep == NULL) return newp;

    int cmp = strcmp(newp->name, treep->name);
    if (cmp == 0) {
        printf("Insert: Duplicate entry %s ignored\n", newp->name);
    } else if (cmp < 0) {
        treep->left = insert(treep->left, newp);
    } else {
        treep->right = insert(treep->right, newp);
    }

    return treep;
}

Nameval* lookup(Nameval *treep, char *name) {
    if (treep == NULL) return NULL;

    int cmp = strcmp(name, treep->name);
    if (cmp == 0) return treep;
    else if (cmp < 0) return lookup(treep->left, name);
    return lookup(treep->right, name);
}

Nameval* nrlookup(Nameval *treep, char *name) {
    while (treep != NULL) {
        int cmp = strcmp(name, treep->name);
        if (cmp == 0) return treep;
        else if (cmp < 0) treep = treep->left;
        else treep = treep->right;
    }
    return NULL;
}

int isBalanced(Nameval *treep) {
    if (treep == NULL) return 1;

    int lh = height(treep->left);
    int rh = height(treep->right);

    if (abs(lh - rh) <= 1 && isBalanced(treep->left) && isBalanced(treep->right)) {
        return 1;
    }

    return 0;
}

int height(Nameval *treep) {
    if (treep == NULL) return 0;

    int lh = height(treep->left);
    int rh = height(treep->right);

    return (lh > rh ? lh : rh) + 1;
}

void generateData(Nameval **treep, int num) {
    for (int i = 0; i < num; i++) {
        Nameval *newv = (Nameval *)malloc(sizeof(Nameval));
        newv->name = (char *)malloc(10);
        snprintf(newv->name, 10, "Name%d", rand() % 1000);
        newv->value = rand() % 100;
        *treep = insert(*treep, newv);
    }
}

void initializeRandomGenerator(void) {
    srand(time(NULL));
}
