#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Node
{
    // // // ABSTRACT DATA TYPE
    int data;
    struct Node *next;
};
void linkedlisttraversal(struct Node *ptr)
{
    /// // LINKED LIST TRAVERSAR
    while (ptr != 0)
    {
        printf("Element : %d\n", ptr->data);
        ptr = ptr->next;
    }
}

struct Node *insertionAtFirst(struct Node *head, int data)

{
    // //// // CASE ----------1
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->next = head;
    ptr->data = data;
}

struct Node *insertionAtIndex(struct Node *head, int data, int index)
{
    // / // CASE-----------2
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head;
    int i = 0;
    while (i != index - 1)
    {
        p = p->next;
        i++;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;

    return head;
}

struct Node *insertionAtEnd(struct Node *head, int data)

{
    // //// // CASE ----------3
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node *p = head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;
    return head;
}
struct Node *insertionAfterNode(struct Node *head, struct Node *prevnode, int data)
{
    // / // CASE-----------4
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
      
    ptr->next = prevnode->next;
    prevnode->next = ptr;
    return head;
}

int main()
{
    // // / / Defining pointers
    struct Node *head;
    struct Node *first;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;
    // Memory Allocation
    head = (struct Node *)malloc(sizeof(struct Node));
    first = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    head->data = 4;
    head->next = first;

    first->data = 5;
    first->next = second;

    second->data = 10;
    second->next = third;

    third->data = 333;
    third->next = fourth;

    fourth->data = 555;
    fourth->next = NULL;

    // traversal
    linkedlisttraversal(head);
    // head = insertionAtFirst(head, 46);
    printf("_________________\n");
    // head=insertionAtIndex(head,77,2);
    // head = insertionAtEnd(head, 77);
    head=insertionAfterNode(head,second,99999);
    linkedlisttraversal(head);

    free(head);
    free(first);
    free(second);
    free(third);
    free(fourth);
    return 0;
}