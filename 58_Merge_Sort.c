#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Time Complexity O(n log n)

void arrayTraversal(int *arr, int a)
{
    for (int i = 0; i < a; i++)
    {
        printf("%d ", arr[i]);
    }
}

// basic logic of merging 2 sorted array
int *mergeSorted(int *arr1, int *arr2, int a1, int a2)
{
    int *arr3 = (int *)malloc((a1 + a2) * sizeof(int));
    int i = 0, j = 0, k = 0;

    while (k < (a1 + a2) && i < a1 && j < a2)
    {

        if (arr1[i] <= arr2[j])
        {
            arr3[k] = arr1[i];
            i++;
            k++;
        }
        else if (arr1[i] > arr2[j])
        {
            arr3[k] = arr2[j];
            j++;
            k++;
        }
    }
    // logic for remaining elements
    while (j != a2)
    {
        arr3[k] = arr1[j];
        j++;
        k++;
    }

    while (i != a1)
    {
        arr3[k] = arr1[i];
        i++;
        k++;
    }
    return arr3;
}


// merging by sorting 
void merge(int *arr, int low, int mid, int high)
{
    int *arr1 = (int *)malloc((high + 1) * sizeof(int));
    int k , i , j;
    k=low;
    j=mid+1;
    i=low;
    while (i <=mid && j <=high)
    {
        if (arr[i] < arr[j])
        {
            arr1[k] = arr[i];
            k++;
            i++;
        }
        else
        {
            arr1[k]=arr[j];
            j++;
            k++;

        }
    }
    while(i<=mid)
    {
        arr1[k]=arr[i];
        i++;
        k++;
    }
     while(j<=high)
    {
        arr1[k]=arr[j];
        j++;
        k++;
    }
    for(int x=low;x<=high;x++)
    {
        arr[x]=arr1[x];
    }
}

// Divide array recursively
void mergeSort(int *arr, int low, int high)
{
    int mid ;
    if (low < high)
    {
        mid= (low + high) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

int main()
{
    /*Basic 2 sorted array*/

    // int a1 = 5, a2 = 4, a3 = a1 + a2;
    int arr[] = {9,1,4,14,4,15,6};
    int size = 7;
   
    // int arr2[] = {1, 6, 9, 11};
    arrayTraversal(arr,size); 
    mergeSort(arr,0,6);
    printf("\n");
    arrayTraversal(arr,size);

    return 0;
}