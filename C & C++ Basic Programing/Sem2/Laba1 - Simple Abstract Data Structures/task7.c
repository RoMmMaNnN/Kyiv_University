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
void lenght(Nameval *listp);

int main(void) {
    Nameval *nvlist = NULL;

    nvlist = addfront(nvlist, newitem("data1", 10));
    nvlist = addfront(nvlist, newitem("data2", 45));
    nvlist = addend(nvlist, newitem("data3", 77));

    lenght(nvlist);

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

void lenght(Nameval *listp) {
    int count = 0;
    while (listp != NULL) {
        printf("%s %d\n", listp->name, listp->value);
        listp = listp->next;
        count++;
    }
    printf("Lenght list: %d\n", count);
}


