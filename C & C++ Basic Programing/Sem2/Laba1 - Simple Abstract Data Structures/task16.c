#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Nameval {
    char *name;
    int value;
    struct Nameval *left;
    struct Nameval *right;
} Nameval;

void applyinorder(Nameval *treep, void (*fn)(Nameval *, void *), void *arg);
void collectnames(Nameval *p, void *arg);
Nameval *insert(Nameval *treep, Nameval *newp);

int main(void) {
    Nameval *treep = NULL;

    treep = insert(treep, &(Nameval) {.name = "Andy", .value = 12});
    treep = insert(treep, &(Nameval) {.name = "Billy", .value = 18});
    treep = insert(treep, &(Nameval) {.name = "Tom", .value = 7});
    treep = insert(treep, &(Nameval) {.name = "Gek", .value = 33});

    char *arr[4];  // Масив для зберігання імен
    applyinorder(treep, collectnames, arr);

    printf("Sorted names: ");
    for (int i = 0; i < 4; i++) {
        printf("%s ", arr[i]);
    }
    printf("\n");

    return 0;
}

void applyinorder(Nameval *treep, void (*fn)(Nameval *, void *), void *arg) {
    if (treep == NULL)
        return;

    applyinorder(treep->left, fn, arg);
    (*fn)(treep, arg);
    applyinorder(treep->right, fn, arg);
}

void collectnames(Nameval *p, void *arg) {
    char **arr = (char **)arg;
    static int index = 0;
    arr[index++] = p->name;
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
