#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct queue_array
{
    int *arr;
    int front_index;
    int back_index;
    int size;

} qa;

int isFull(qa *ptr)
{
    if (ptr->back_index == ptr->size - 1)
    {
        return 1;
    }
    return 0;
}

int isEmpty(qa *ptr)
{
    if (ptr->back_index == ptr->front_index)
    {
        return 1;
    }
    return 0;
}

int queueTop(qa *ptr)
{
    if (isFull(ptr))
    {
        return -1;
    }
    return ptr->arr[ptr->back_index];
}

int queueBottom(qa *ptr)
{
    if (isEmpty(ptr))
    {
        return -1;
    }
    return ptr->arr[ptr->front_index];
}

int Enqueue(qa *ptr, int value)
{
    if (isFull(ptr))
    {
        printf("Queue Full\n");
        return -1;
    }

    else
    {
        ptr->back_index++;
        ptr->arr[ptr->back_index] = value;
        int a = ptr->arr[ptr->back_index];
        printf("Element Inserted\n");
        return a;
    }
}

int Dequeue(qa *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Queue Empty\n");
        return 0;
    }
    else
    {
        ptr->front_index++;
        int a = ptr->arr[ptr->front_index];
        printf("Popped element %d\n", a);
        return a;
    }
}

void QueueTraversal(qa *ptr)
{
    for (int i = 0; i <= ptr->back_index; i++)
    {
        printf("Index %d Element %d\n", i, ptr->arr[i]);
    }
}

int main()
{
    qa *a = (qa *)malloc(sizeof(qa));
    a->size = 10;
    a->back_index = -1;
    a->front_index = -1;
    a->arr = (int *)malloc(a->size * sizeof(int));
    Enqueue(a, 1);
    Enqueue(a, 2);
    Enqueue(a, 3);
    printf("Top %d\n", queueTop(a));
    Enqueue(a, 4);
    Enqueue(a, 5);
    QueueTraversal(a);
    printf("Top %d\n", queueTop(a));
    Dequeue(a);
    Dequeue(a);
    printf("Bottom %d\n", queueBottom(a));
    Dequeue(a);
    Dequeue(a);
    printf("Bottom %d\n", queueBottom(a));
    Dequeue(a);
    Dequeue(a);
    Dequeue(a);
    Dequeue(a);
    Dequeue(a);

    free(a);

    return 0;
}