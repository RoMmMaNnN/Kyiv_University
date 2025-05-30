#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
Nameval *copylist(Nameval *listp);
Nameval *mergelist(Nameval *list1, Nameval *list2);
void splitlist(Nameval *listp, Nameval **first, Nameval **second);
Nameval *insertbefore(Nameval *listp, char *target, Nameval *newp);
Nameval *insertafter(Nameval *listp, char *target, Nameval *newp);

int main(void) {
    Nameval *nvlist = NULL, *list2 = NULL, *first = NULL, *second = NULL;
    int n = 0;

    nvlist = addfront(nvlist, newitem("data1", 10));
    nvlist = addfront(nvlist, newitem("data2", 45));
    nvlist = addend(nvlist, newitem("data3", 77));
    printf("Original list:\n");
    coolfun(nvlist, print_list, &n);
    Nameval *copy = copylist(nvlist);
    printf("\nCopied list:\n");
    coolfun(copy, print_list, &n);
    list2 = addfront(list2, newitem("data4", 69));
    list2 = addfront(list2, newitem("data5", 55));
    Nameval *merged = mergelist(nvlist, list2);
    printf("\nMerged list:\n");
    coolfun(merged, print_list, &n);
    splitlist(merged, &first, &second);
    printf("\nFirst half of split list:\n");
    coolfun(first, print_list, &n);
    printf("\nSecond half of split list:\n");
    coolfun(second, print_list, &n);
    nvlist = insertbefore(nvlist, "data2", newitem("before_data2", 123));
    printf("\nList after inserting before data2:\n");
    coolfun(nvlist, print_list, &n);
    nvlist = insertafter(nvlist, "data3", newitem("after_data3", 123));
    printf("\nList after inserting after data3:\n");
    coolfun(nvlist, print_list, &n);

    return 0;
}

Nameval *newitem(char *name, int value) {
    Nameval *newp = (Nameval *)malloc(sizeof(Nameval));
    if (newp == NULL) return NULL;
    newp->name = strdup(name);
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
    int *count = (int *)arg;
    (*count) = 0;
    (*count)++;
}

void print_list(Nameval *p, void *arg) {
    printf("%s %d\n", p->name, p->value);
}

Nameval *copylist(Nameval *listp) {
    if (!listp) return NULL;
    Nameval *newlist = NULL, *tail = NULL;
    while (listp) {
        Nameval *newnode = newitem(listp->name, listp->value);
        if (!newlist) {
            newlist = newnode;
            tail = newnode;
        } else {
            tail->next = newnode;
            tail = newnode;
        }
        listp = listp->next;
    }
    return newlist;
}

Nameval *mergelist(Nameval *list1, Nameval *list2) {
    if (!list1) return list2;
    if (!list2) return list1;
    Nameval *p = list1;
    while (p->next) {
        p = p->next;
    }
    p->next = list2;
    return list1;
}

void splitlist(Nameval *listp, Nameval **first, Nameval **second) {
    if (!listp) {
        *first = *second = NULL;
        return;
    }
    Nameval *slow = listp, *fast = listp->next;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    *first = listp;
    *second = slow->next;
    slow->next = NULL;
}

Nameval *insertbefore(Nameval *listp, char *target, Nameval *newp) {
    if (!listp) return newp;
    if (strcmp(listp->name, target) == 0) {
        newp->next = listp;
        return newp;
    }
    Nameval *prev = NULL, *curr = listp;
    while (curr && strcmp(curr->name, target) != 0) {
        prev = curr;
        curr = curr->next;
    }
    if (curr) {
        prev->next = newp;
        newp->next = curr;
    }
    return listp;
}

Nameval *insertafter(Nameval *listp, char *target, Nameval *newp) {
    Nameval *p = listp;
    while (p && strcmp(p->name, target) != 0) {
        p = p->next;
    }
    if (p) {
        newp->next = p->next;
        p->next = newp;
    }
    return listp;
}
