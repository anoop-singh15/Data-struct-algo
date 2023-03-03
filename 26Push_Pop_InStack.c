#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *arr;
};

int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    return 0;
}

int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    return 0;
}

void push(struct stack *ptr, int val)
{
    if (isFull(ptr))
    {
        printf("stack overflow\n");
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}

void pop(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("stack is empty\n");
    }
    else
    {
        int a = ptr->arr[ptr->top];
        ptr->top--;
        printf("Element %d\n", a);
    }
}
int main()
{
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 8;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));

    // To check if array is empty or full Before
    if (isEmpty(s))
    {
        printf("stack is empty\n");
    }
    else
    {
        printf("the stack is not empty\n");
    }

    push(s, 10);
    push(s, 10);
    push(s, 10);
    push(s, 10);
    push(s, 10);
    push(s, 10);
    push(s, 20);

    pop(s); /// Last in first out LIFO

    // To check if array is empty or full After push /pull
    if (isEmpty(s))
    {
        printf("stack is empty\n");
    }
    else
    {
        printf("the stack is not empty\n");
    }
    return 0;
}