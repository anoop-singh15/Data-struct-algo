#include <stdio.h>
#include <string.h>
#include <stdlib.h>


/*Time complexity of
   isEmpty = O(1)
   isFull = O(1)
   Push = O(1)
   Pop = O(1)
   Peek = O(1)
   stackTop = O(1)
   stackBottom = O(1)
*/
struct stack
{
    int top;
    int size;
    int *arr;
};


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


int stackTop(struct stack *ptr)
{
    return ptr->arr[ptr->top];
}

int stackBottom(struct stack *ptr)
{
    return ptr->arr[0];
}

int main()
{
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->top = -1;
    s->size = 5;
    s->arr = (int *)malloc(s->size * sizeof(int));

    push(s, 1);
    push(s, 2);
    push(s, 3);
    push(s, 4);
    push(s, 5);

    printf("Element at top of stack is== %d\n", stackTop(s));
    printf("Element at bottom of stack is== %d\n", stackBottom(s));

    return 0;
}