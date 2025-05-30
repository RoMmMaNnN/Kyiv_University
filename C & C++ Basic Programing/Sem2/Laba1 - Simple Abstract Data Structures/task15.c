#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Nameval {
    char *name;
    int value;
    struct Nameval *left;
    struct Nameval *right;
} Nameval;

Nameval *lookup(Nameval *treep, char *name) {
    if (treep == NULL)
        return NULL;
    
    int cmp = strcmp(name, treep->name);
    
    if (cmp == 0)
        return treep;
    else if (cmp < 0)
        return lookup(treep->left, name);
    else
        return lookup(treep->right, name);
}

Nameval *nrlookup(Nameval *treep, char *name) {
    while (treep != NULL) {
        int cmp = strcmp(name, treep->name);
        
        if (cmp == 0)
            return treep;
        else if (cmp < 0)
            treep = treep->left;
        else
            treep = treep->right;
    }
    return NULL;
}

Nameval *insert(Nameval *treep, Nameval *newp) {
    if (treep == NULL)
        return newp;
    
    int cmp = strcmp(newp->name, treep->name);
    if (cmp == 0)
        printf("insert: duplicate entry %s ignored\n", newp->name);
    else if (cmp < 0)
        treep->left = insert(treep->left, newp);
    else
        treep->right = insert(treep->right, newp);
    
    return treep;
}

void applyinorder(Nameval *treep, void (*fn)(Nameval *, void *), void *arg) {
    if (treep == NULL)
        return;
    
    applyinorder(treep->left, fn, arg);
    (*fn)(treep, arg);
    applyinorder(treep->right, fn, arg);
}

void applypostorder(Nameval *treep, void (*fn)(Nameval *, void *), void *arg) {
    if (treep == NULL)
        return;
    
    applypostorder(treep->left, fn, arg);
    applypostorder(treep->right, fn, arg);
    (*fn)(treep, arg);
}

void printnv(Nameval *p, void *arg) {
    char *fmt = (char *)arg;
    printf(fmt, p->name, p->value);
}

int main(void) {
    Nameval *treep = NULL;
    
    treep = insert(treep, &(Nameval) {.name = "Andy", .value = 12});
    treep = insert(treep, &(Nameval) {.name = "Billy", .value = 18});
    
    applyinorder(treep, printnv, "%s: %d\n");
    putchar('\n');

    Nameval *res = lookup(treep, "Billy");
    if (res != NULL)
        printf("Found: %s %d\n", res->name, res->value);
    else
        printf("Not found\n");
    
    res = nrlookup(treep, "Andy");
    if (res != NULL)
        printf("Found: %s %d\n", res->name, res->value);
    else
        printf("Not found\n");

    return 0;
}
