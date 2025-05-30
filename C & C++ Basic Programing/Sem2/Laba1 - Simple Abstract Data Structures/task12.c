#include <stdio.h>
#include <stdlib.h>

typedef struct Namevalue {
    void* data;
    enum { INT, FLOAT, DOUBLE } type;
    struct Namevalue* next;
} Namevalue;

Namevalue* create_Namevalue(void* data, int type);
void append(Namevalue** head, void* data, int type);
void print_list(Namevalue* head);
void free_list(Namevalue* head);

int main() {
    Namevalue* list = NULL;
    int a = 11;
    float b = 22.2;
    double c = 333;

    append(&list, &a, INT);
    append(&list, &b, FLOAT);
    append(&list, &c, DOUBLE);

    print_list(list);
    free_list(list);

    return 0;
}

Namevalue* create_Namevalue(void* data, int type) {
    Namevalue* new_Namevalue = (Namevalue*)malloc(sizeof(Namevalue));
    new_Namevalue->data = data;
    new_Namevalue->type = type;
    new_Namevalue->next = NULL;
    return new_Namevalue;
}

void append(Namevalue** head, void* data, int type) {
    Namevalue* new_Namevalue = create_Namevalue(data, type);
    if (*head == NULL) {
        *head = new_Namevalue;
    } else {
        Namevalue* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_Namevalue;
    }
}

void print_list(Namevalue* head) {
    Namevalue* temp = head;
    while (temp != NULL) {
        switch (temp->type) {
            case INT:
                printf("int: %d -> ", *((int*)temp->data));
                break;
            case FLOAT:
                printf("float: %.2f -> ", *((float*)temp->data));
                break;
            case DOUBLE:
                printf("double: %.f -> ", *((double*)temp->data));
                break;
        }
        temp = temp->next;
    }
    printf("NULL\n");
}

void free_list(Namevalue* head) {
    Namevalue* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}
