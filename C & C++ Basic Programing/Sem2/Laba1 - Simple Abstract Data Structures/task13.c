#include <stdio.h>
#include <stdlib.h>

typedef struct TypeList {
    void* data;
    struct TypeList* next;
} TypeList;

TypeList* create_node(void* data);
void append(TypeList** head, void* data);
void print_list(TypeList* head, void (*print_func)(void*));
void free_list(TypeList* head);
int count_elements(TypeList* head);
int is_empty(TypeList* head);
void print_int(void* data);
void print_float(void* data);
void print_double(void* data);

int main() {
    TypeList* list = NULL;
    int a = 10, b = 20;
    append(&list, &a);
    append(&list, &b);

    printf("\nTesr: Print list of integers after added elements: \n");
    print_list(list, print_int);
    printf("\nExpected output: 10 -> 20 -> NULL\n");

    printf("\nTest: Number of elements in list: %d\n", count_elements(list));
    printf("Expected output: 2\n");

    free_list(list);
    printf("\nTest: After freeing the list, check if it's empty: \n");
    if (is_empty(list)) {
        printf("List is empty\n");
    } else {
        printf("List is not empty\n");
    }

    TypeList* emptyList = NULL;
    append(&emptyList, &a);
    append(&emptyList, &b);
    printf("\nTest: Print new list after added   elements: \n");
    print_list(emptyList, print_int);
    printf("\nExpected output: 10 -> 20 -> NULL\n");

    free_list(emptyList);
    return 0;
}

TypeList* create_node(void* data) {
    TypeList* new_node = (TypeList*)malloc(sizeof(TypeList));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void append(TypeList** head, void* data) {
    TypeList* new_node = create_node(data);
    if (*head == NULL) {
        *head = new_node;
    } else {
        TypeList* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

void print_list(TypeList* head, void (*print_func)(void*)) {
    TypeList* temp = head;
    while (temp != NULL) {
        print_func(temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void free_list(TypeList* head) {
    TypeList* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int count_elements(TypeList* head) {
    int count = 0;
    TypeList* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

int is_empty(TypeList* head) {
    return head == NULL;
}

void print_int(void* data) {
    printf("%d -> ", *((int*)data));
}

void print_float(void* data) {
    printf("%.2f -> ", *((float*)data));
}

void print_double(void* data) {
    printf("%.2f -> ", *((double*)data));
}
