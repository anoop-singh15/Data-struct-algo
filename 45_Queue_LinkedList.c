#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Queue_LinkedList
{
    int data;
    struct Queue_LinkedList *next;

} qll;

qll *front = NULL;
qll *rear = NULL;

int isFull(qll *rear)
{
    if (rear == NULL)
    {
        return 1;
    }
    return 0;
}

int isEmpty(qll *front)
{
    if (front == NULL)
    {
        return 1;
    }
    return 0;
}

void Enqueue(int value)
{
    qll *n = (qll *)malloc(sizeof(qll));
    if (isFull(n))
    {
        printf("Queue Full\n");
    }

    else
    {
        n->data = value;
        n->next = NULL;

        if (front == NULL)
        {
            rear = front = n;
        }
        else
        {
            rear->next = n;
            rear = n;
        }
    }
}

int Dequeue()
{
    int b;
    if (isEmpty(front))
    {
        printf("Queue Empty\n");
    }
    else
    {
        qll *a = front;
        b = a->data;
        front = front->next;
        free(a);
    }
    return b;
}

void QueueLinkTraversal(qll *ptr)
{

    printf("Printing elements of linked list\n");

    while (ptr != NULL)
    {
        printf("Element in Queue: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

int main()
{

    Enqueue(5);
    Enqueue(6);
    Enqueue(2);
    printf("Dequeuing Element %d\n",Dequeue());
    QueueLinkTraversal(front);
    Enqueue(8);
    Enqueue(6);
    Enqueue(7);
    Enqueue(10);
    Enqueue(74);
    Enqueue(44);
    printf("Dequeuing Element %d\n",Dequeue());
    QueueLinkTraversal(front);


    return 0;
}