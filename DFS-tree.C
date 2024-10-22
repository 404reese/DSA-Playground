#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 7

int visited[MAX_NODES] = {0};
int A[MAX_NODES][MAX_NODES] = {
    {0, 1, 1, 1, 0, 0, 0},
    {1, 0, 1, 0, 0, 0, 0},
    {1, 1, 0, 1, 1, 0, 0},
    {1, 0, 1, 0, 1, 0, 0},
    {0, 0, 1, 1, 0, 1, 1},
    {0, 0, 0, 0, 1, 0, 0},
    {0, 0, 0, 0, 1, 0, 0}
};

// Stack structure
struct Stack {
    int items[MAX_NODES];
    int top;
};

// Stack operations
void initStack(struct Stack* s) {
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

// DFS function using explicit stack
void DFS(int start) {
    struct Stack stack;
    initStack(&stack);

    push(&stack, start);

    while (!isEmpty(&stack)) {
        int current = pop(&stack);

        if (!visited[current]) {
            printf("%d ", current);
            visited[current] = 1;

            for (int i = MAX_NODES - 1; i >= 0; i--) {
                if (A[current][i] == 1 && !visited[i]) {
                    push(&stack, i);
                }
            }
        }
    }
}

int main() {
    printf("DFS traversal starting from node 0: ");
    DFS(0);
    return 0;
}
