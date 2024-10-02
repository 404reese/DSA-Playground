#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 7

// Node structure
struct Node {
    int id;
    struct Node* next;
};

// Function to add a connection between two nodes
void addConnection(struct Node** nodes, int from, int to) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->id = to;
    newNode->next = nodes[from]->next;
    nodes[from]->next = newNode;
}

// Function to construct the adjacency matrix
void constructMatrix(struct Node** nodes, int A[][MAX_NODES]) {
    for (int i = 0; i < MAX_NODES; i++) {
        for (int j = 0; j < MAX_NODES; j++) {
            A[i][j] = 0;
        }
    }

    for (int i = 0; i < MAX_NODES; i++) {
        struct Node* current = nodes[i]->next;
        while (current != NULL) {
            A[i][current->id] = 1;
            current = current->next;
        }
    }
}

// Function to print the adjacency matrix
void printMatrix(int A[][MAX_NODES]) {
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < MAX_NODES; i++) {
        for (int j = 0; j < MAX_NODES; j++) {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
}

// DFS function using explicit stack
void DFS(int start, int A[][MAX_NODES], int visited[]) {
    struct Stack {
        int items[MAX_NODES];
        int top;
    };

    struct Stack stack;
    int initStack(struct Stack* s) {
        s->top = -1;
    }

    void push(struct Stack* s, int x) {
        if (s->top == MAX_NODES - 1) {
            printf("Stack Overflow\n");
            return;
        }
        s->items[++(s->top)] = x;
    }

    int pop(struct Stack* s) {
        if (s->top == -1) {
            printf("Stack Underflow\n");
            return -1;
        }
        return s->items[(s->top)--];
    }

    int isEmpty(struct Stack* s) {
        return s->top == -1;
    }

    initStack(&stack);

    push(&stack, start);

    while (!isEmpty(&stack)) {
        int current = pop(&stack);

        if (!visited[current]) {
            printf("%d ", current);
            visited[current] = 1;

            for (int i = 0; i < MAX_NODES; i++) {
                if (A[current][i] == 1 && !visited[i]) {
                    push(&stack, i);
                }
            }
        }
    }
}

int main() {
    struct Node* nodes[MAX_NODES];
    for (int i = 0; i < MAX_NODES; i++) {
        nodes[i] = (struct Node*)malloc(sizeof(struct Node));
        nodes[i]->id = i;
        nodes[i]->next = NULL;
    }

    printf("Enter node connections (from to):\n");
    int from, to;
    while (1) {
        scanf("%d %d", &from, &to);
        if (from == -1 && to == -1) break;
        addConnection(nodes, from, to);
    }

    int A[MAX_NODES][MAX_NODES];
    constructMatrix(nodes, A);

    printMatrix(A);

    int visited[MAX_NODES] = {0};

    printf("DFS traversal starting from node 0: ");
    DFS(0, A, visited);
    return 0;
}