#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

/// CIRCULAR LINKED LIST TRAVERSAL
void circularLinkedListTraversal(struct Node *head)
{
    struct Node *ptr = head;

    // while(ptr->next!=head)
    // {
    //     printf("element----%d\n",ptr->data);
    //     ptr=ptr->next;
    // }
    // printf("element----%d\n",ptr->data);

    //// /////OPTIMUM WAY TO TRAVERSE
    do
    {
        printf("element-----%d\n", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
}

///CASE--INSERTION AT FIRST IN CLL
struct Node *insertionatfirst(struct Node * head,int data)
{
    struct Node *ptr=(struct Node *)malloc(sizeof(struct Node));
    ptr->data=data;
    struct Node *p=head->next;

    while(p->next!=head)
    {
        p=p->next;
    }// p at last node
    p->next=ptr;
    ptr->next=head;
    head=ptr;

    return head;

}

int main()
{
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    struct Node *second = (struct Node *)malloc(sizeof(struct Node));
    struct Node *third = (struct Node *)malloc(sizeof(struct Node));
    struct Node *fourth = (struct Node *)malloc(sizeof(struct Node));

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = fourth;

    fourth->data = 4;
    fourth->next = head;

    printf("Circular linked lists traversal\n");
    circularLinkedListTraversal(head);

    printf("Circular Linked list after insertion at first\n");
    head=insertionatfirst(head,10);
    circularLinkedListTraversal(head);



    free(head);
    free(second);
    free(third);
    free(fourth);

    return 0;
}