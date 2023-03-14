#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct array
{
    int *arr;
    int size;
    int top;
};

int isfull(struct array *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isempty(struct array *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(struct array *ptr, int data)
{
    if (isfull(ptr))
    {
        printf("Stack overflow\n");
    }
    else
    {
        ptr->top++;
        int a = ptr->arr[ptr->top] = data;
        printf("pushed %d\n", a);
    }
}
int pop(struct array *ptr)
{
    if (isempty(ptr))
    {
        printf("Stack Udnerflow\n");
        return 0;
    }
    else
    {
        int b = ptr->top;
        ptr->top--;
        printf("popped element %d\n", b);
        return 1;
    }
}

int paranthesismatch(char *arr)
{

    struct array *a = (struct array *)malloc(sizeof(struct array));

    a->size = 20;
    a->top = -1;
    a->arr = (int *)malloc(a->size * sizeof(int));

    char b = '(';
    char c = ')';
    for (int i = 0; arr[i] != '\0'; i++)
    {

        if (arr[i] == b)
        {
            push(a, i);
        }
        else if (arr[i] == c)
        {
            if (isempty(a))
            {
                printf("Stack empty\n");
                return 0;
            }
            else
            {
                pop(a);
            }
        }
    }
    if (isempty(a))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void arrayTraversal(struct array *ptr)
{
    for (int i = 0; i <= ptr->top; i++)
    {
        printf("element at index %d is %d\n", i, ptr->arr[i]);
    }
}

int main()
{

    char *arr = "(())))))))(()()))))";

    if (paranthesismatch(arr))
    {
        printf("TRUE = Balanced\n");
    }
    else
    {
        printf("FALSE = Unbalanced\n");
    }

    return 0;
}