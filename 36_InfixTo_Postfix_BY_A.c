#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct array
{
    int size;
    char *arraystack;
    int top;
};

int isEmpty(struct array *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    return 0;
}

void stackTraversal(struct array *ptr)
{
    for (int i = 0; i <= ptr->top; i++)
    {
        printf("Arraystack %c\n", ptr->arraystack[i]);
    }
}

int isFull(struct array *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    return 0;
}

int stackTop(struct array *ptr)
{
    return ptr->arraystack[ptr->top];
}

char pop(struct array *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack underflow\n");
    }

    else
    {
        char a = ptr->arraystack[ptr->top];
        ptr->top--;
        printf("popped element %c\n", a);
        return a;
    }
}

void push(struct array *ptr, char value)
{
    if (isFull(ptr))
    {
        printf("Stack overflow\n");
    }
    else
    {
        ptr->top++;
        ptr->arraystack[ptr->top] = value;
        printf("index %d element %c\n", ptr->top, value);
    }
}

void postfix(char *arr)
{
    struct array *a = (struct array *)malloc(sizeof(struct array));
    a->size = 20;
    a->top = -1;
    a->arraystack = (char *)malloc(a->size * sizeof(char));
    int d = 0;
    char arr1[d];
    char *ptr = arr1;
    for (int i = 0; arr[i] != '\0'; i++)
    {
        printf("index-------%d-------CHARACTER-----%c----\n", i, arr[i]);
        if (arr[i] == '-' || arr[i] == '+')
        {
            if (isEmpty(a) || stackTop(a) == '+' || stackTop(a) == '-')
            {
                push(a, arr[i]);
            }
            else
            {
                while (!isEmpty(a))
                {
                    arr1[d++] = pop(a);
                }
                push(a, arr[i]);
            }
        }
        else if (arr[i] == '*' || arr[i] == '/')
        {
            if (isEmpty(a) || stackTop(a) == '+' || stackTop(a) == '-' || stackTop(a) == '*' || stackTop(a) == '/')
            {
                push(a, arr[i]);
            }
            else
            {
                while (!isEmpty(a))
                {
                    arr1[d++] = pop(a);
                }
                push(a, arr[i]);
            }
        }
        else
        {
            arr1[d++] = arr[i];
        }
    }

    while (!isEmpty(a))
    {
        arr1[d++] = pop(a);
    }

    stackTraversal(a);

    printf("\nPOSTFIX NOTATION IS= ");
    for (int i = 0; i < d; i++)
    {
        printf("%c", arr1[i]);
    }
    printf("\n\n");
}

int main()
{

    // char *arr = "x-y/z-k*d";
    // char *arr = "x-y*z";
    char *arr = "a-b*d+c";

    postfix(arr);

    return 0;
}