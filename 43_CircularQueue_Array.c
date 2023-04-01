#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct CircularQueue
{
    int *arr;
    int size;
    int front_index;
    int back_index;
} cq;

int isEmpty(cq *ptr)
{
    if (ptr->back_index == ptr->front_index)
    {
        return 1;
    }
    return 0;
}

int isFull(cq *ptr)
{
    if ((ptr->back_index + 1) % ptr->size == ptr->front_index)
    {
        return 1;
    }
    return 0;
}

int Enqueue(cq *ptr, int value)
{
    int a;
    if (isFull(ptr))
    {
        printf("Queue Overflow\n");
    }
    else
    {

        ptr->back_index = (ptr->back_index + 1) % ptr->size;
        ptr->arr[ptr->back_index] = value;
        a = ptr->arr[ptr->back_index];
        printf("Enqueued element : %d\n", a);
    }
    return a;
}

int Dequeue(cq *ptr)
{
    int ret = -1;
    if (isEmpty(ptr))
    {
        printf("Queue Empty\n");
    }
    else
    {
        ptr->front_index = (ptr->front_index + 1) % ptr->size;
        ret = ptr->arr[ptr->front_index];
    }
    return ret;
}

int main()
{
    cq *a = (cq *)malloc(sizeof(cq));
    a->size = 5;
    a->back_index = 0;
    a->front_index = 0;
    a->arr = (int *)malloc(a->size * sizeof(int));

    Enqueue(a, 1);
    Enqueue(a, 2);
    Enqueue(a, 3);
    Enqueue(a, 4);
    Enqueue(a, 5);
    Enqueue(a, 6);
    printf("Dequeuing element : %d\n", Dequeue(a));
    printf("Dequeuing element : %d\n", Dequeue(a));
    printf("Dequeuing element : %d\n", Dequeue(a));
    printf("Dequeuing element : %d\n", Dequeue(a));
    Enqueue(a, 5);
    Enqueue(a, 6);

    free(a);

    return 0;
}