#include <iostream>
#include <cstring>

using namespace std;

struct Nameval {
    char *name;
    int value;
    Nameval *next;
};

Nameval* newitem(const char *name, int value) {
    Nameval* newp = new Nameval;
    newp->name = new char[strlen(name) + 1];
    strcpy(newp->name, name);
    newp->value = value;
    newp->next = nullptr;
    return newp;
}

Nameval* addfront(Nameval *listp, Nameval *newp) {
    newp->next = listp;
    return newp;
}

Nameval* addend(Nameval *listp, Nameval *newp) {
    if (listp == nullptr) return newp;
    Nameval *p = listp;
    while (p->next != nullptr) {
        p = p->next;
    }
    p->next = newp;
    return listp;
}

Nameval* deleteitem(Nameval *listp, const char *name) {
    if (listp == nullptr) return nullptr;
    if (strcmp(listp->name, name) == 0) {
        Nameval *temp = listp;
        listp = listp->next;
        delete[] temp->name;
        delete temp;
        return listp;
    }
    Nameval *p = listp;
    while (p->next != nullptr && strcmp(p->next->name, name) != 0) {
        p = p->next;
    }
    if (p->next != nullptr) {
        Nameval *temp = p->next;
        p->next = p->next->next;
        delete[] temp->name;
        delete temp;
    }
    return listp;
}

Nameval* copyitem(Nameval *listp, const char *name) {
    Nameval *p = listp;
    while (p != nullptr) {
        if (strcmp(p->name, name) == 0) {
            return newitem(p->name, p->value);
        }
        p = p->next;
    }
    return nullptr;
}

Nameval* merge(Nameval *list1, Nameval *list2) {
    if (list1 == nullptr) return list2;
    Nameval *p = list1;
    while (p->next != nullptr) {
        p = p->next;
    }
    p->next = list2;
    return list1;
}

void split(Nameval *listp, Nameval *&first_half, Nameval *&second_half) {
    if (listp == nullptr) {
        first_half = second_half = nullptr;
        return;
    }

    Nameval *slow = listp;
    Nameval *fast = listp;

    while (fast != nullptr && fast->next != nullptr) {
        fast = fast->next->next;
        slow = slow->next;
    }

    first_half = listp;
    second_half = slow->next;
    slow->next = nullptr;
}

Nameval* insertbefore(Nameval *listp, const char *before, Nameval *newp) {
    if (listp == nullptr) return newp;
    if (strcmp(listp->name, before) == 0) {
        newp->next = listp;
        return newp;
    }

    Nameval *p = listp;
    while (p->next != nullptr && strcmp(p->next->name, before) != 0) {
        p = p->next;
    }

    if (p->next != nullptr) {
        newp->next = p->next;
        p->next = newp;
    }

    return listp;
}

Nameval* insertafter(Nameval *listp, const char *after, Nameval *newp) {
    if (listp == nullptr) return newp;

    Nameval *p = listp;
    while (p != nullptr && strcmp(p->name, after) != 0) {
        p = p->next;
    }

    if (p != nullptr) {
        newp->next = p->next;
        p->next = newp;
    }

    return listp;
}

void printlist(Nameval *listp) {
    while (listp != nullptr) {
        cout << listp->name << ": " << listp->value << endl;
        listp = listp->next;
    }
}

int main() {
    Nameval *first_half, *second_half;
    Nameval *list = nullptr;

    list = addend(list, newitem("data1", 1));
    list = addfront(list, newitem("data2", 2));
    list = addend(list, newitem("data3", 3));
    
    cout << "Initial list:" << endl;
    printlist(list);

    list = deleteitem(list, "data2");

    cout << "\nAfter deletion:" << endl;
    printlist(list);

    Nameval *copied_item = copyitem(list, "data1");
    cout << "\nCopied item:" << endl;
    cout << copied_item->name << ": " << copied_item->value << endl;

    Nameval *second_list = nullptr;
    second_list = addfront(second_list, newitem("data4", 4));
    second_list = addend(second_list, newitem("data5", 5));

    list = merge(list, second_list);
    
    cout << "\nAfter merging:" << endl;
    printlist(list);

    split(list, first_half, second_half);

    cout << "\nFirst half:" << endl;
    printlist(first_half);
    
    cout << "\nSecond half:" << endl;
    printlist(second_half);

    list = insertbefore(list, "data4", newitem("data66", 66));
    cout << "\nAfter inserting before 'data4':" << endl;
    printlist(list);

    list = insertafter(list, "data4", newitem("data77", 77));
    cout << "\nAfter inserting after 'data4':" << endl;
    printlist(list);

    return 0;
}
