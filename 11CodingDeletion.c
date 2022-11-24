#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void display(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
}

int deletion(int arr[], int size, int capacity, int index)
{
    // ////// /////CODE FOR DELETION
    for (int i = index; i < size; i++)
    {
        arr[i] = arr[i + 1];
    }
    return 0;
}

int main()
{
    int capacity = 100;
    int size = 14;
    int arr[100] = {1, 2, 18, 3, 4, 5, 6, 7, 8, 6, 5, 42, 133, 2, 8};
    int index = 5;
    display(arr, size);
    printf("\n");
    deletion(arr, size, capacity, index);
    size -= 1;
    display(arr, size);
    printf("\n");

    return 0;
}