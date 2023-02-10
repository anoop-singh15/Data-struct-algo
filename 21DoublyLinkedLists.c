#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

/// /DOBULY LINKED LIST TRAVERSAL //FORWARD TRAVEL
void DoublyLinkedListTraversal(struct Node *head)
{
    while (head != NULL)
    {
        printf("element--%d\n", head->data);
        head = head->next;
    }
}

// FUNCTION FOR BOTH FORWARD AND REVERSE TRAVEL
void ForwardReverseTravel(struct Node *head)
{
    struct Node *ptr=head;
    do
    {
        printf("Element---%d\n", ptr->data);
        ptr = ptr->next;

    } while (ptr->next!=NULL);
  printf("Element---%d\n--------------\n", ptr->data);
  while(ptr!=NULL)
  {
    printf("Element---%d\n",ptr->data);
    ptr=ptr->prev;
  }
    
}

int main()
{
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    struct Node *second = (struct Node *)malloc(sizeof(struct Node));
    struct Node *third = (struct Node *)malloc(sizeof(struct Node));
    struct Node *fourth = (struct Node *)malloc(sizeof(struct Node));

    // head->data=1;
    scanf("%d", &head->data);
    head->prev = NULL;
    head->next = second;

    scanf("%d", &second->data);
    second->prev = head;
    second->next = third;

    scanf("%d", &third->data);
    third->prev = second;
    third->next = fourth;

    scanf("%d", &fourth->data);
    fourth->prev = third;
    fourth->next = NULL;

    printf("Forward traversal----\n");
    DoublyLinkedListTraversal(head);

    printf("Reverse Traversal----\n");
    // DoublyLinkedLsitTraversal(fourth)

    printf("BOTH FORWARD AND REVERSE TRAVEL\n");
    ForwardReverseTravel(head);

    free(head);
    free(second);
    free(third);
    free(fourth);
    return 0;
}