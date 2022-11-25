#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int linearsearch(int arr[], int size, int element)
{
    // // // linear Search---No sorted array needed
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == element)
        {
            return i;
        }
    }
    return -1;
}



int main()
{

    int element = 3112;

    int arr[100] = {1, 42, 3, 4, 5 , 6, 42, 112, 3112,22, 15, 3};
    int size = sizeof(arr) / sizeof(int);
    printf("index at which element is present is %d \n", linearsearch(arr, size, element));

    return 0;
}