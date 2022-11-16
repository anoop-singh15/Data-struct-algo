#include <stdio.h>
#include <stdlib.h>

typedef struct myArray
{
    int total_size;
    int used_size;
    int *ptr;
} ma;

void createArray(ma *a, int tSize, int uSize)
{
    // (*a).total_size=tSize;
    // (*a).used_size=uSize;
    // (*a).ptr=(int*)malloc(tSize * sizeof(int));

    a->total_size = tSize;
    a->used_size = uSize;
    a->ptr = (int *)malloc(tSize * sizeof(int));
}
void setVal(ma *a)
{
    int n;
    for (int i = 0; i < a->used_size; i++)
    {
        printf("Enter element %d:\n", i);
        scanf("%d", &n);
        (a->ptr)[i] = n;
    }
}
void show(ma *a)
{
    for (int i = 0; i < a->used_size; i++)
    {
        printf("%d\n", (a->ptr)[i]);
    }
}
int main()
{
    ma marks;
    printf("Creating Array  now\n");
    createArray(&marks, 10, 2);
    printf("INPUT VALUES\n");

    setVal(&marks);
    printf("Showing values now;\n");
    show(&marks);
    free(marks.ptr);
    return 0;
}