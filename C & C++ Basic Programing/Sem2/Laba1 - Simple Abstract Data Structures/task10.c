#include <stdio.h>
#include <stdlib.h>

typedef struct Nameval {
    char *name;
    int value;
    struct Nameval *next;
} Nameval;

Nameval *newitem(char *name, int value);
void print_list(Nameval *listp);
void reverse_list_iter(Nameval **listp);
Nameval* reverse_list_recurs(Nameval *listp);

int main(void) {
    Nameval *nvlist = NULL;

    nvlist = newitem("data1", 10);
    nvlist->next = newitem("data2", 45);
    nvlist->next->next = newitem("data3", 77);

    printf("Original list:\n");
    print_list(nvlist);
    reverse_list_iter(&nvlist);
    printf("\nList after iterative reverse:\n");
    print_list(nvlist);
    nvlist = reverse_list_recurs(nvlist);
    printf("\nList after recursive reverse:\n");
    print_list(nvlist);

    return 0;
}

Nameval *newitem(char *name, int value) {
    Nameval *newp = (Nameval *)malloc(sizeof(Nameval));
    if (newp == NULL) return NULL;
    newp->name = name;
    newp->value = value;
    newp->next = NULL;
    return newp;
}

void print_list(Nameval *listp) {
    while (listp != NULL) {
        printf("%s %d\n", listp->name, listp->value);
        listp = listp->next;
    }
}

void reverse_list_iter(Nameval **listp) {
    Nameval *prev = NULL, *current = *listp, *next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *listp = prev;
}

Nameval* reverse_list_recurs(Nameval *listp) {
    if (listp == NULL || listp->next == NULL) {
        return listp;
    }
    Nameval *rest = reverse_list_recurs(listp->next);
    listp->next->next = listp;
    listp->next = NULL;
    return rest;
}
