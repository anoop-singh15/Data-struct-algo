#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
void linkedlisttraversal(struct Node *ptr)
{
    while (ptr != 0)
    {
        printf("Element : %d\n", ptr->data);
        ptr = ptr->next;
    }
}
int main()
{

    /// CREATION OF LINKED LIST

    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    // Allocate memory in heap
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    // link head(first) and second element
    head->data = 55;
    head->next = second;

    // Link second and third element
    second->data = 123;
    second->next = third;

    // Link third and fourth element
    third->data = 66;
    third->next = fourth;

    // Link fourth to null end element terminate list
    fourth->data = 123445;
    fourth->next = NULL;
    /// END

    // TRAVERSAL STARTS
    linkedlisttraversal(head);
    // TRAVERSAL ENDS

    free(head);
    free(second);
    free(third);
    free(fourth);

    return 0;
}