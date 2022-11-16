#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    // // // 
    int count = 0;
    int n;
    printf("Enter no. of times you want to play loop\n");
    scanf("%d", &n);
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            printf("%d----%d\n", i, j);
            count++;
        }
    }
    printf("The number of times loop ran is---%d\n", count);
    return 0;
}