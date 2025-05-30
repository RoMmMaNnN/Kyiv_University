#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    char *name;
    int value;
    struct Node *next;
} Node;

typedef struct CircularQueue {
    Node *rear;
} CircularQueue;

CircularQueue* initQueue();
void enqueue(CircularQueue *queue, char *name, int value);
void dequeue(CircularQueue *queue);
void displayQueue(CircularQueue *queue);

int main() {
    CircularQueue *queue = initQueue();
    
    enqueue(queue, "data1", 1);
    enqueue(queue, "data2", 2);
    enqueue(queue, "data3", 3);
    enqueue(queue, "data4", 4);
    
    displayQueue(queue);
    
    dequeue(queue);
    displayQueue(queue);
    
    dequeue(queue);
    displayQueue(queue);
    
    dequeue(queue);
    displayQueue(queue);
    
    dequeue(queue);
    displayQueue(queue);
    
    return 0;
}

CircularQueue* initQueue() {
    CircularQueue *queue = (CircularQueue*)malloc(sizeof(CircularQueue));
    queue->rear = NULL;
    return queue;
}

void enqueue(CircularQueue *queue, char *name, int value) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        return;
    }
    newNode->name = name;
    newNode->value = value;
    
    if (queue->rear == NULL) {
        newNode->next = newNode;
        queue->rear = newNode;
    } else {
        newNode->next = queue->rear->next;
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

void dequeue(CircularQueue *queue) {
    if (queue->rear == NULL) {
        printf("Queue is empty!\n");
        return;
    }
    Node *front = queue->rear->next;
    if (front == queue->rear) {
        queue->rear = NULL;
    } else {
        queue->rear->next = front->next;
    }
    printf("Dequeued: %s %d\n", front->name, front->value);
    free(front);
}

void displayQueue(CircularQueue *queue) {
    if (queue->rear == NULL) {
        printf("Queue is empty!\n");
        return;
    }
    Node *temp = queue->rear->next;
    do {
        printf("%s %d -> ", temp->name, temp->value);
        temp = temp->next;
    } while (temp != queue->rear->next);
    printf("(circular)\n");
}
