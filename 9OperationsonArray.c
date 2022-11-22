#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*
TRAVERSAL
INSERTION
DELETION
SEARCHING
*/
typedef struct array
{
    int total_size;
    int used_size;
    int *ptr;
} ar;

void createarray(ar *a, int tsize, int usize)
{
    a->total_size = tsize;
    a->used_size = usize;
    a->ptr = (int *)malloc(tsize * sizeof(int));
}
void valandshow(ar *a)
{
    for (int i = 0; i < a->used_size; i++)
    {
        printf("Enter Element of index %d \n", i);
        scanf("%d", &(a->ptr)[i]);
    }
    for (int i = 0; i < a->used_size; i++)
    {
        printf("The values at index %d  is %d  \n", i, a->ptr[i]);
    }
}

int main()
{
    ar a;
    createarray(&a, 10, 4);
    valandshow(&a);
    free(a.ptr);
    return 0;
}