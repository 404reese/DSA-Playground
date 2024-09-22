#include <stdio.h>
#include <stdlib.h>

typedef struct { 
    int front;
    int rear;
    int items[50]; 
} Queue;

Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

int isEmpty(Queue* q) {
    return (q->front == -1); 
}

int isFull(Queue* q) {
    return (q->rear == 49); // maxsize - 1
}

// Enqueue an element to the queue
void enqueue(Queue* q, int value) {
    if (isFull(q)) { 
        printf("Queue is full\n"); 
        return;
    }
    if (isEmpty(q)) {
        q->front = 0; 
    }
    q->rear++;
    q->items[q->rear] = value;
    printf("Enqueued: %d\n", value); 
}

void dequeue(Queue* q, int* value) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        *value = -1;
        return;
    }
    *value = q->items[q->front];
    q->front++;
    if (q->front > q->rear) { 
        q->front = q->rear = -1;
    }
    printf("Dequeued: %d\n", *value);
}

void displayQueue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue contents: ");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->items[i]); 
    }
    printf("\n");
}

int main() {
    Queue* q = createQueue();
    int value;

    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);

    displayQueue(q);

    dequeue(q, &value);
    displayQueue(q);

    enqueue(q, 40);
    displayQueue(q);

    free(q); // Good practice UwU
    return 0;
}
