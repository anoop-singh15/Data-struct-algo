#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Time Complexity O(n^2)
// Not Recursive
// Not Stable
// Not Adaptive

void arrayTraversal(int *arr, int a)
{
    for (int i = 0; i < a; i++)
    {
        printf("%d ", arr[i]);
    }
}

int *selectionSort(int *arr, int a)
{
    int c = 0;
    for (int i = 0; i < a - 1; i++)
    {

        printf("RunTime %d\n", i + 1);
        for (int j = i + 1; j < a; j++)
        {
            if (arr[i] > arr[j])
            {
                int b = arr[i];
                arr[i] = arr[j];
                arr[j] = b;
                c = 1;
            }
        }
        // Avoid Minimum Swaps
        if (c == 0)
        {
            return arr;
        }
        // Condition ends
        arrayTraversal(arr, a);
        printf("\n");
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

    arrayTraversal(selectionSort(arr, a), a);

    return 0;
}