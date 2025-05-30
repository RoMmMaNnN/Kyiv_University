#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Nameval {
    char *name;
    int value;
    struct Nameval *next;
} Nameval;

Nameval *newitem(char *name, int value);
void print_list(Nameval *listp);
Nameval *lookup(Nameval *listp, char *name);
void freeall(Nameval *listp);
Nameval *delitem(Nameval *listp, char *name);

int main() {
    Nameval *nvlist = NULL;

    nvlist = newitem("data1", 10);
    nvlist->next = newitem("data2", 45);
    nvlist->next->next = newitem("data3", 77);

    printf("Original list:\n");
    print_list(nvlist);

    char *search_name = "data3";
    Nameval *found = lookup(nvlist, search_name);
    if (found) {
        printf("\nFound: %s -> %d\n", found->name, found->value);
    } else printf("\n%s not found in list\n", search_name);

    printf("\nDeleting data3\n");
    nvlist = delitem(nvlist, "data3");
    print_list(nvlist);

    freeall(nvlist);

    return 0;
}

Nameval *newitem(char *name, int value) {
    Nameval *newp = (Nameval *)malloc(sizeof(Nameval));
    if (newp == NULL) return NULL;

    newp->name = malloc(strlen(name) + 1);
    if (newp->name == NULL) {
        free(newp);
        return NULL;
    }
    strcpy(newp->name, name);

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

Nameval *lookup(Nameval *listp, char *name) {
    for (; listp != NULL; listp = listp->next)
        if (strcmp(name, listp->name) == 0)
            return listp;
    return NULL;
}

void freeall(Nameval *listp) {
    Nameval *next;
    for (; listp != NULL; listp = next) {
        next = listp->next;
        free(listp->name);
        free(listp);
    }
}
    
Nameval *delitem(Nameval *listp, char *name) {
    Nameval *p, *prev = NULL;
    for (p = listp; p != NULL; p = p->next) {
        if (strcmp(name, p->name) == 0) {
            if (prev == NULL) { 
                listp = p->next;
            } else prev->next = p->next;
            
            free(p->name);
            free(p);
            return listp;
        }
        prev = p;
    }
    printf("delitem: %s not in list\n", name);
    return listp;
}
