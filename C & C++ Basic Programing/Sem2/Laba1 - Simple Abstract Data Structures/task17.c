#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Nameval {
    char *name;
    int value;
    struct Nameval *left;
    struct Nameval *right;
} Nameval;

Nameval *insert(Nameval *treep, char *name, int value);
void applyinorder(Nameval *treep, void (*fn)(Nameval *, void *), void *arg);
void collectnames(Nameval *p, void *arg);
Nameval *search(Nameval *treep, char *name);
Nameval *delete(Nameval *treep, char *name);
Nameval *findmin(Nameval *treep);
void free_tree(Nameval *treep);
void test_insert();
void test_search();
void test_delete();

int main(void) {
    test_insert();
    test_search();
    test_delete();
    return 0;
}

Nameval *insert(Nameval *treep, char *name, int value) {
    if (treep == NULL) {
        Nameval *newp = malloc(sizeof(Nameval));
        if (!newp) {
            perror("Memory allocation failed");
            exit(EXIT_FAILURE);
        }
        newp->name = strdup(name);
        newp->value = value;
        newp->left = newp->right = NULL;
        return newp;
    }

    int cmp = strcmp(name, treep->name);
    if (cmp < 0)
        treep->left = insert(treep->left, name, value);
    else if (cmp > 0)
        treep->right = insert(treep->right, name, value);
    return treep;
}

Nameval *search(Nameval *treep, char *name) {
    if (treep == NULL || strcmp(treep->name, name) == 0)
        return treep;
    return strcmp(name, treep->name) < 0 ? search(treep->left, name) : search(treep->right, name);
}

Nameval *delete(Nameval *treep, char *name) {
    if (treep == NULL) return NULL;

    int cmp = strcmp(name, treep->name);
    if (cmp < 0) {
        treep->left = delete(treep->left, name);
    } else if (cmp > 0) {
        treep->right = delete(treep->right, name);
    } else {
        printf("Deleting node: %s\n", name);
        if (treep->left == NULL) {
            Nameval *temp = treep->right;
            free(treep->name);
            free(treep);
            return temp;
        }
        if (treep->right == NULL) {
            Nameval *temp = treep->left;
            free(treep->name);
            free(treep);
            return temp;
        }

        Nameval *minRight = findmin(treep->right);
        char *tempName = strdup(minRight->name);
        free(treep->name);
        treep->name = tempName;
        treep->value = minRight->value;
        treep->right = delete(treep->right, minRight->name);
    }

    return treep;
}

Nameval *findmin(Nameval *treep) {
    while (treep->left != NULL) treep = treep->left;
    return treep;
}

void free_tree(Nameval *treep) {
    if (treep == NULL) return;
    free_tree(treep->left);
    free_tree(treep->right);
    free(treep->name);
    free(treep);
}

void test_insert() {
    printf("Test insert: ");
    Nameval *treep = NULL;
    treep = insert(treep, "Billy", 18);
    treep = insert(treep, "Andy", 12);
    treep = insert(treep, "Tom", 7);
    treep = insert(treep, "Gek", 33);
    
    printf(treep && strcmp(treep->name, "Billy") == 0 ? "PASSED\n" : "FAILED\n");
    free_tree(treep);
}

void test_search() {
    printf("Test search: ");
    Nameval *treep = NULL;
    treep = insert(treep, "Billy", 18);
    treep = insert(treep, "Andy", 12);
    treep = insert(treep, "Tom", 7);
    treep = insert(treep, "Gek", 33);
    
    Nameval *result = search(treep, "Andy");
    printf(result && strcmp(result->name, "Andy") == 0 ? "PASSED\n" : "FAILED\n");
    free_tree(treep);
}

void test_delete() {
    printf("Test delete: ");
    Nameval *treep = NULL;
    treep = insert(treep, "Billy", 18);
    treep = insert(treep, "Andy", 12);
    treep = insert(treep, "Tom", 7);
    treep = insert(treep, "Gek", 33);

    treep = delete(treep, "Tom");
    Nameval *result = search(treep, "Tom");

    printf(result == NULL ? "PASSED\n" : "FAILED\n");
    free_tree(treep);
}
