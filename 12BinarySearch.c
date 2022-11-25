#include <stdio.h>
/* BINARY search IS FOR SORTED ARRAY
ARRAY IS COLLECTON OF SAME TYPE OF DATA STORED  AT CONTINOUS MEMORY LOCATION  */

int binary(int arr[], int size, int element)
{
    int low, mid, high;
    low = 0;
    high = size - 1;
    // START SEARCHING
    // Until low and high converges
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (arr[mid] == element)
        {
            return mid;
        }
        if (arr[mid] < element)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    // END SEARCHING
    return -1;
}
int main()
{
    int arr1[] = {1, 2, 5, 8,9,10, 14, 34, 45,56,78,80, 88,100,200,300,444,555,666};
    int size = sizeof(arr1) / sizeof(int);
    int element = 444;
    printf("Element %d is at location %d \n", element, binary(arr1, size, element));
    return 0;
}