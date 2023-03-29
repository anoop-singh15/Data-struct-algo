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

int precedence(char ch)
{
    if(ch=='*' || ch=='/' )
    {
        return 3;
    }
    else  if(ch=='+' || ch=='-' )
    {
        return 2;
    }
    else
    {
        return 0;
    }
}

int isOperator(char ch)
{
    if(ch=='+' || ch=='-' || ch=='*' || ch=='/')
    {
        return 1;
    }
    return 0;
}


void *postfix(char *arr)
{
    struct array *a = (struct array *)malloc(sizeof(struct array));
    a->size = 20;
    a->top = -1;
    a->arraystack = (char *)malloc(a->size * sizeof(char));
    char *arr1 = (char *)malloc(strlen(arr) + 1 * sizeof(char));
    int d = 0;
    for (int i = 0; arr[i] != '\0'; i++)
    {
        if (!isOperator(arr[i]))
        {
            arr1[d++] = arr[i];
        }
        else
        {
            if (precedence(arr[i]) > precedence(stackTop(a)))
            {
                push(a, arr[i]);
            }
            else
            {
                while(!isEmpty(a))
                {
                     arr1[d++]=pop(a); 
                }
                push(a,arr[i]);
               
            }
        }
    }

    while(!isEmpty(a))
    {
        arr1[d++]=pop(a);
    }
    arr1[d]='\0';
    return arr1;
}

int main()
{
    char *arr = "x-y/z-k*d";
    printf("Postfix Notation is %s\n", postfix(arr));

    return 0;
}