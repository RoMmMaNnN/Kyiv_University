#include <stdio.h>
#include <stdlib.h>

typedef struct Nameval {
    char *name;
    int value;
    struct Nameval *next;
} Nameval;

Nameval *newitem(char *name, int value);
Nameval *addfront(Nameval *listp, Nameval *newp);
Nameval *addend(Nameval *listp, Nameval *newp);
void coolfun(Nameval *listp, void (*fn)(Nameval *, void *), void *arg);
void inccounter(Nameval *p, void *arg);
void print_list(Nameval *p, void *arg);

int main(void) {
    Nameval *nvlist = NULL;
    int n = 0;

    nvlist = addfront(nvlist, newitem("data1", 10));
    nvlist = addfront(nvlist, newitem("data2", 45));
    nvlist = addend(nvlist, newitem("data3", 77));    
    coolfun(nvlist, inccounter, &n);
    printf("Lenght list: %d\n", n);
    coolfun(nvlist, print_list, NULL);

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

Nameval *addfront(Nameval *listp, Nameval *newp) {
    newp->next = listp;
    return newp;
}

Nameval *addend(Nameval *listp, Nameval *newp) {
    if (listp == NULL) return newp;
    Nameval *p = listp;
    while (p->next != NULL) {
        p = p->next;
    }
    p->next = newp;
    return listp;
}

void coolfun(Nameval *listp, void (*fn)(Nameval *, void *), void *arg) {
    while (listp != NULL) {
        fn(listp, arg);
        listp = listp->next;
    }
}

void inccounter(Nameval *p, void *arg) {
    int *ip = (int *)arg;
    (*ip)++;
}

void print_list(Nameval *p, void *arg) {
    printf("%s %d\n", p->name, p->value);
}
