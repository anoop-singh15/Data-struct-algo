// Double Ended Queue
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// ADT for DEQUeue:
// EnQueueR
// EnQueueF
// DeQueueR
// DeQueueF
// IsFull ~
// IsEmpty ~

struct DEqueue
{
    int size;
    int front;
    int rear;
    int *arr;
};

int isEmptyR(struct DEqueue *ptr)
{
    if (ptr->rear == ptr->front)
    {
        return 1;
    }
    return 0;
}

int isEmptyF(struct DEqueue *ptr)
{
    if (ptr->front == ptr->rear)
    {
        return 1;
    }
    return 0;
}

int isFullF(struct DEqueue *ptr)
{
    if (ptr->front == -1)
    {
        return 1;
    }
    return 0;
}

int isFullR(struct DEqueue *ptr)
{
    if (ptr->rear == ptr->size - 1)
    {
        return 1;
    }
    return 0;
}

void EnqueueR(struct DEqueue *ptr, int value)
{
    if (isFullR(ptr))
    {
        printf("Queue Full NO Enqueue in backside\n");
    }

    else
    {
        ptr->rear++;
        ptr->arr[ptr->rear] = value;
        printf("Element at REAR index %d is %d\n", ptr->rear, value);
    }
}

void EnqueueF(struct DEqueue *ptr, int value)
{
    if (isFullF(ptr))
    {
        printf("Queue Full NO Enqueue in Frontside\n");
    }

    else
    {
        ptr->arr[ptr->front] = value;
        ptr->front--;
        printf("Element at FRONT index %d is %d\n", ptr->front + 1, value);
    }
}

int DequeueR(struct DEqueue *ptr)
{
    int a = -1;
    if (isEmptyR(ptr))
    {
        printf("Queue Empty cannot remove element from rear\n");
    }
    else
    {
        a = ptr->arr[ptr->rear];
        ptr->rear--;
    }
    return a;
}

int DequeueF(struct DEqueue *ptr)
{
    int a = -1;

    if (isEmptyF(ptr))
    {
        printf("Queue is empty at front cannot remove element \n");
    }

    else
    {
        ptr->front++;
        a = ptr->arr[ptr->front];
    }
    return a;
}

void QueueTraversal(struct DEqueue *ptr)
{
    if (ptr->front == -1)
    {
        for (int i = 0; i <= ptr->rear; i++)
        {
            printf("Element : %d\n", ptr->arr[i]);
        }
    }

    else
    {
        for (int i = ptr->front + 1; i <= ptr->rear; i++)
        {
            printf("Element : %d\n", ptr->arr[i]);
        }
    }
}

int main()
{
    struct DEqueue *a = (struct DEqueue *)malloc(sizeof(struct DEqueue));
    a->size = 10;
    a->front = a->rear = -1;
    a->arr = (int *)malloc(a->size * sizeof(int));

    EnqueueF(a, 2); // front queue
    EnqueueR(a, 2);
    EnqueueR(a, 3);
    EnqueueR(a, 4);
    EnqueueR(a, 5);
    EnqueueR(a, 6);
    EnqueueR(a, 7);
    EnqueueR(a, 8);
    EnqueueR(a, 9);
    EnqueueR(a, 10);//8
    printf("Dequeued Element at rear is : %d\n", DequeueR(a));
    printf("Dequeued Element at front is : %d\n", DequeueF(a));
    printf("Dequeued Element at front is : %d\n", DequeueF(a));
    printf("Dequeued Element at front is : %d\n", DequeueF(a));
    printf("Dequeued Element at front is : %d\n", DequeueF(a));
    printf("Dequeued Element at front is : %d\n", DequeueF(a));
    printf("Dequeued Element at front is : %d\n", DequeueF(a));
    EnqueueF(a, 99); // front queue
    EnqueueR(a, 11);//new 8
    printf("Dequeued Element at front is : %d\n", DequeueF(a));//6
    EnqueueR(a, 12);
    EnqueueR(a, 13);

    printf("\nQueue Traversal--------------\n");
    QueueTraversal(a);

    free(a);
    return 0;
}