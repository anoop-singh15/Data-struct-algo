#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};

/// TRAVERSAL CODE
void linkedlistTraversal(struct Node *head)
{
    while (head != 0)
    {
        printf("elements :%d\n", head->data);
        head = head->next;
    }
}

///   CASE 1 delete first element
struct Node *deletesecond(struct Node *head)
{
    struct Node *ptr = head;
    head = head->next;
    free(ptr);
    return head;
}

//// CASE 2 Deletion At index
struct Node *deleteatindex(struct Node *head, int index)
{
    /// NOT CONSIDERING DELETION OF ELEMENT AT FIRST INDEX
    struct Node *p = head;
    struct Node *q = head->next;
    for (int i = 1; i < index - 1; i++)
    {
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
    free(q);
    return head;
}

/// CASE 3 DELETE THE  LAST NODE
struct Node *deleteatlast(struct Node *head)
{
    struct Node *p = head;
    struct Node *q = head->next;
    while (q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    free(q);
    return head;
}

////CASE 4 DELETE NODE AT THE VALUE
struct Node *deleteatvalue(struct Node *head, int value)
{
    struct Node *p = head;
    struct Node *q = head->next;
    while (q->data != value && q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    if (q->data == value)
    {
        p->next = q->next;
        free(q);
        
    }
    return head;
}

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *last;

    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    last = (struct Node *)malloc(sizeof(struct Node));

    head->data = 34;
    head->next = second;

    second->data = 44;
    second->next = third;

    third->data = 12;
    third->next = last;

    last->data = 55;
    last->next = NULL;

    printf("Linked list before deletion \n");
    linkedlistTraversal(head);

    ////// CASE--1 delete a node at head or first element of Linked list
    // head=deletesecond(head);
    // head=deletesecond(head);
    // head=deletesecond(head);
    // head=deletesecond(head);

    //////CASE 2 DELETE A NODE AT AN INDEX
    // head=deleteatindex(head,4);

    //////CASE 3 DELETE LAST NODE
    // head=deleteatlast(head);

    ////CASE 4 DELETING THE ELEMENT WITH A GIVEN VALUE
    head = deleteatvalue(head, 1);

    printf("Linked list after deletion\n");
    linkedlistTraversal(head);

    free(head);
    free(second);
    free(third);
    free(last);

    return 0;
}