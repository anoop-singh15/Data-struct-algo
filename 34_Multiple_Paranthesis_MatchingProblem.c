#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct array
{
    int top;
    int size;
    char *arr;
};

int isEmpty(struct array *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    return 0;
}

int stackTop(struct array *ptr)
{
    return ptr->arr[ptr->top];
}

int isFull(struct array *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    return 0;
}

void push(struct array *ptr, char data)
{
    if (isFull(ptr))
    {
        printf("The STACK is full\n");
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = data;
        printf("Pushed element %c\n", data);
    }
}

void pop(struct array *ptr)
{
    if (isEmpty(ptr))
    {
        printf("STACK underflow\n");
    }
    else
    {
        char a = ptr->arr[ptr->top];
        ptr->top--;
        printf("Popped element %c\n", a);
    }
}

int match(struct array *ptr, char data)
{
    if (data == ')')
    {
        data = '(';
        if (ptr->arr[ptr->top] == data)
        {
            return 1;
        }
        return 0;
    }

    if (data == '}')
    {
        data = '{';
        if (ptr->arr[ptr->top] == data)
        {
            return 1;
        }
        return 0;
    }

    if (data == ']')
    {
        data = '[';
        if (ptr->arr[ptr->top] == data)
        {
            return 1;
        }
        return 0;
    }
}

int paranthesisMatch(char arr[])
{
    struct array *a = (struct array *)malloc(sizeof(struct array));
    a->size = 20;
    a->top = -1;
    a->arr = (char *)malloc(a->size * sizeof(char));
    for (int i = 0; arr[i] != '\0'; i++)
    {
        if (arr[i] == '(' || arr[i] == '{' || arr[i] == '[')
        {
            push(a, arr[i]);
        }
        else if (arr[i] == ')' || arr[i] == '}' || arr[i] == ']')
        {
            if (isEmpty(a))
            {
                return 0;
            }
            else
            {

                if (match(a, arr[i]))
                {
                    pop(a);
                }
                else
                    return 0;
            }
        }
    }
    if (isEmpty(a))
    {
        return 1;
    }
    return 0;
}
int main()
{
    char arr[20] = "((){[()]})";
    if (paranthesisMatch(arr))
    {
        printf("TRUE = Balanced\n");
    }
    else
    {
        printf("FALSE = Unbalanced \n");
    }

    return 0;
}