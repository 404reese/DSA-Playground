 #include <stdio.h>
 #include <stdbool.h>
 #define maxsize 100 // use the array size gine in the question
 typedef struct
 {
    int items[maxsize];
    int top;
 } Stack;
 void initStack(Stack *s)
 {
    s->top = -1;
 }
 bool isEmpty(Stack *s)
 {
    if (s->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
 }
 bool Push(Stack *s, int item)
 {
    if (s->top == maxsize)
    {
        printf("Stack Overflow");
        return 0;
    }
    else
    {
        (s->top) = (s->top + 1);
        s->items[s->top] = item;
        return 1;
    }
 }
 int Pop(Stack *s)
 {
    if (isEmpty(s))
    {
        printf("Stack Underflow\n");
        return -1;
    }
    else
    {
	      int item = s->items[s->top];
        s->top = s->top - 1;
        return item;
    }
 }
 int Peek(Stack *s)
 {
    if (isEmpty(s))
    {
        printf("Stack is empty");
        return -1;
    }
    return s->items[s->top];
 }
 int main() {
    Stack myStack;
    initStack(&myStack);
    Push(&myStack, 10);
    Push(&myStack, 20);
    Push(&myStack, 30);
    printf("Top item: %d\n", Peek(&myStack));
    printf("Popped item: %d\n", Pop(&myStack));
    printf("Popped item: %d\n", Pop(&myStack));
    printf("Popped item: %d\n", Pop(&myStack));
    printf("Popped item: %d\n", Pop(&myStack));

    return 0;
 }
