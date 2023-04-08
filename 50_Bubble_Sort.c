#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Time complexity O(n^2)
// Stable Algorithm
// Not Recursive Algo
// No Adaptibility ByDefault But can be Made Adaptive O(n)

void arrayTraversal(int *arr, int a)
{

    for (int i = 0; i < a; i++)
    {
        printf("%d  ", arr[i]);
    }
}

int *bubbleSort(int *arr, int a)
{
    int c = 0, d = 1;
    while (a > 1)
    {
        printf("Working on Pass %d\n", d);
        for (int i = 0; i < a; i++)
        {

            if (arr[i] > arr[i + 1])
            {
                int b = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = b;
                c = 1;// To make Adaptive
            }
        }
        // To make Adaptive
        if (c == 0)
        {
            // Time Complexity O(n)
            return arr;
        }
        // Adaptive Condition Ends
        arrayTraversal(arr, a);
        printf("\n");
        a--;
        d++;
    }

    return arr;
}

int main()
{

    int a;
    printf("Enter Length of an array\n");
    scanf("%d", &a);
    int *arr = (int *)malloc(a * sizeof(int));
    for (int i = 0; i < a; i++)
    {
        scanf("%d", &arr[i]);
    }
    arr = bubbleSort(arr, a);
    arrayTraversal(arr, a);

    return 0;
}