#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int visited[7]={0,0,0,0,0,0,0};

int arr[7][7]={
     {0,1,1,1,0,0,0},
      {1,0,1,0,0,0,0},
      {1,1,0,1,1,0,0},
      {1,0,1,0,1,0,0},
      {0,0,1,1,0,1,1},
      {0,0,0,0,1,0,0},
      {0,0,0,0,1,0,0},
};


void dfs(int i)
{
    printf("%d ", i);
    visited[i] = 1;
    for (int j = 0; j < 7; j++)
    {
        if (arr[i][j] == 1 && visited[j] == 0)
        {
            dfs(j);
        }
    }
}

int main()
{
    dfs(4);

    return 0;
}