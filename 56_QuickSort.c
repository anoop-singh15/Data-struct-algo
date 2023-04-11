#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* ANALYSIS OF QUICKSORT
    --->Worst case analysis-->Already Sorted Elements
                              Time complexity==(n-1)*kn-->O(n^2)
    --->Best case Analysis-->When array is divided from middle
                             time complexity==O(nlogn)
    --->Average Case --->O(nlogn)    

    Quick sort is not Stable
    Quick sort is an inplace algorithm
*/



void arraytraversal(int *arr, int a)
{
    for (int i = 0; i < a; i++)
    {
        printf("%d ", arr[i]);
    }
}

int partition(int *arr, int low, int high)
{
    int i = low + 1;
    int j = high;
    int pivot = arr[low];

    do
    {

        while (arr[i] <= pivot)
        {
            i++;
        }
        while (arr[j] > pivot)
        {
            j--;
        }
        if (i < j)
        {
            int b = arr[i];
            arr[i] = arr[j];
            arr[j] = b;
        }

    } while (i < j);
    int b = arr[j];
    arr[j] = arr[low];
    arr[low] = b;
    return j;
}

int *quickSort(int *arr, int low, int high)
{
    if (low < high)
    {
        int b = partition(arr, low, high);
        quickSort(arr, low, b - 1);
        quickSort(arr, b + 1, high);
    }

    return arr;
}

int main()
{
    int a;
    printf("Enter length \n");
    scanf("%d", &a);
    int *arr = (int *)malloc(a * sizeof(int));
    for (int i = 0; i < a; i++)
    {
        scanf("%d", &arr[i]);
    }
    arraytraversal(quickSort(arr, 0, a - 1), a);

    return 0;
}