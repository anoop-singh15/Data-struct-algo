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

// Function to check if stack is empty or not
int isEmpty(struct Node *ptr)
{
    if (ptr == NULL)
    {
        return 1;
    }
    return 0;
}

int peek(struct Node *ptr)
{
}

// Function for push operation
int push(struct Node *ptr, int value)
{
    if (isFull(ptr))
    {
        printf("The stack is full Cannot push an element\n");
    }
    else
    {

        struct Node *a = (struct Node *)malloc(sizeof(struct Node));
        a->data = ptr->data;
        a->next = ptr->next;
        ptr->data = value;
        ptr->next = a;
    }
}

// 2nd function for push
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

// Function to pop top element (head)
struct Node *pop(struct Node *ptr)
{
    struct Node *a = (struct Node *)malloc(sizeof(struct Node));
    a = ptr->next;
    free(ptr);
    return a;
}

// 2nd Function for Pop
int pop2(struct Node **ptr)
{
    if (isEmpty(*ptr))
    {
        printf("Stack underflow \n");
    }
    else
    {
        struct Node * n=*ptr;
        *ptr=(*ptr)->next;
        int x=n->data;
        free(n);
        return x;
        
    }
}

int main()
{
    struct Node *head2 = NULL;
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    struct Node *second = (struct Node *)malloc(sizeof(struct Node));
    struct Node *third = (struct Node *)malloc(sizeof(struct Node));
    struct Node *fourth = (struct Node *)malloc(sizeof(struct Node));

    head->data = 9;
    head->next = second;

    second->data = 22;
    second->next = third;

    third->data = 4;
    third->next = fourth;

    fourth->data = 3;
    fourth->next = NULL;

    linkedlistTraversal(head);

    // isEmpty Function
    printf("\nThe stack is empty 0-false 1-true \n%d\n", isEmpty(head2));

    // PUSH OPERATION
    printf("\nStack after push operation--------------------\n");
    push(head, 1);
    linkedlistTraversal(head);
    printf("\nStack after push operation--------------------\n");
    push(head, 2);
    linkedlistTraversal(head);

    printf("\nStack after push2 operation--------#################------------\n");
    // Push 2
    head2 = push2(head2, 2222);
    head2 = push2(head2, 12);
    linkedlistTraversal(head2);

    // POP OPERATION
    printf("\nStack Before pop operation--------------------------\n");
    linkedlistTraversal(head);
    head = pop(head);

    printf("\nStack After pop operation--------------------------\n");
    linkedlistTraversal(head);

    head = pop(head);
    printf("\nStack After pop operation--------------------------\n");
    linkedlistTraversal(head);

    // POP 2 Operation
    printf("\nStack After pop2 operation------###################--------------\n");
    int a=pop2(&head2);
    printf("Popped 2 element is %d\n",a);
    linkedlistTraversal(head2);

    free(head);
    free(head2);
    free(second);
    free(third);
    free(fourth);

    return 0;
}