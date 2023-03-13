#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

// Traversal code for linked list
void linkedlistTraversal(struct Node *ptr)
{
    int i = 1;
    while (ptr != 0)
    {

        printf("elemtent at node --%d-- is -----%d----\n", i, ptr->data);
        ptr = ptr->next;
        i++;
    }
}

// Function to check if stack is full
int isFull(struct Node *ptr)
{
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));

    if (n == NULL)
    {
        return 1;
    }
    return 0;
}
//  function for push
struct Node *push2(struct Node *ptr, int value)
{
    if (isFull(ptr))
    {
        printf("Stack overflow\n");
    }
    else
    {
        struct Node *n = (struct Node *)malloc(sizeof(struct Node));
        n->data = value;
        n->next = ptr;
        ptr = n;
        return ptr;
    }
}

// PEEK function
int peek(struct Node *ptr, int pos)
{
    struct Node *a = ptr;
    for (int i = 0; (i < pos - 1 && a != NULL); i++)
    {
        a = a->next;
    }
    if (a != NULL)
    {
        return a->data;
    }
    else
    {
        return -1;
    }
}
//function  for stack top
int stackTop(struct Node *ptr)
{
    return ptr->data;
}
//function for stack bottom
int stackBottom(struct Node *ptr)
{
    int a;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
        a = ptr->data;
    }
    return a;
}

int main()
{
    struct Node *head = NULL;
    head = push2(head, 28);
    head = push2(head, 18);
    head = push2(head, 15);
    head = push2(head, 7);
    linkedlistTraversal(head);
    printf("----------------\n");
    int a = peek(head, 2);
    printf("value at 2 index is%d\n", a);
    printf("stack top is %d\n", stackTop(head));
    printf("stack top is %d\n", stackBottom(head));
    return 0;
}