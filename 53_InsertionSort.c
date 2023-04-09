#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Time Complexity O(n^2)
// Not Recursive
// Stable
// Adaptive ---> Time complexity O(n)

void arrayTraversal(int *arr, int a)
{
    for (int i = 0; i < a; i++)
    {
        printf("%d ", arr[i]);
    }
}

int *insertionSort(int *arr, int a)
{
    for (int i = 1; i < a; i++)
    {
        printf("RunTime %d\n", i );
        int j = i - 1;
        while (j >= 0 && arr[j] > arr[i])
        {
            arr[j+1]=arr[j];
            j--;
            arrayTraversal(arr, a);
            printf("\n");
        }
        arr[j+1]=arr[i];
    }
    return arr;
}

int main()
{
    int a;
    printf("Enter Length of array\n");
    scanf("%d", &a);
    int *arr = (int *)malloc(a * sizeof(int));
    for (int i = 0; i < a; i++)
    {
        scanf("%d", &arr[i]);
    }

    arrayTraversal(insertionSort(arr, a), a);

    return 0;
}