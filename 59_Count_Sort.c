#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* 
    Time Complexity = O(n+max)
            approx  = O(n)   
            at cost of Extra Space 

*/

void arrayTraversal(int *arr, int a)
{
    for (int i = 0; i < a; i++)
    {
        printf("%d ", arr[i]);
    }
}

int maxElement(int *arr, int size)
{
    int *arr1 = (int *)malloc(size * sizeof(int));

    int max;
    for (int i = 0; i < size; i++)
    {
        arr1[i] = arr[i];
        if (arr1[0] < arr1[i])
        {
            arr1[0] = arr1[i];
            max = arr1[0];
        }
    }
    return max;
}

int *countSort(int *arr, int size, int max)
{
    // int *temparr = (int *)malloc((max + 1) * sizeof(int));
    // for (int i = 0; i <= (max); i++)
    // {
    //     temparr[i] = 0;
    // }

    // if we use calloc temparr will get default values as 0 and we can avoid one
    // for loop
    int *temparr = (int *)calloc((max + 1) , sizeof(int));
    //---------------------------------------

    int i = 0;
    int j;
    while (i < size)
    {
        j = arr[i];
        // printf("%d %d\n", i, j);
        temparr[j] = temparr[j] + 1;
        i++;
    }

    int k = 0;
    int l = 0;
    while (l < size)
    {
        if (temparr[k] != 0)
        {
            arr[l] = k;
            temparr[k] = temparr[k] - 1;
            l++;
            continue;
        }

        k++;
    }

    return arr;
}

int main()
{
    int arr[] = {9, 1, 4, 14, 4, 15, 6};
    int size = 7;
    arrayTraversal(arr,size);
    printf("\n");
    arrayTraversal(countSort(arr, size, maxElement(arr, size)), size);

    return 0;
}