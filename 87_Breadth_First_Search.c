#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct queue
{
   int size;
   int *arr;
   int front;
   int rear;
};

int isFull(struct queue *ptr)
{
   if (ptr->rear == ptr->size - 1)
   {
      return 1;
   }
   return 0;
}

int isEmpty(struct queue *ptr)
{
   if (ptr->front == ptr->rear)
   {
      return 1;
   }
   return 0;
}

int queueTop(struct queue *ptr)
{
   if (isFull(ptr))
   {
      return -1;
   }
   return ptr->arr[ptr->front];
}

int queueBottom(struct queue *ptr)
{
   if (isEmpty(ptr))
   {
      return -1;
   }
   return ptr->arr[ptr->rear];
}

int Enqueue(struct queue *ptr, int data)
{
   if (isFull(ptr))
   {
      printf("Queue Overflow\n");
      return -1;
   }
   else
   {
      ptr->rear++;
      ptr->arr[ptr->rear] = data;
      // printf("Element Inseted\n");
      return ptr->arr[ptr->rear];
   }
}

int Dequeue(struct queue *ptr)
{
   if (isEmpty(ptr))
   {
      printf("Queue Overflow\n");
      return -1;
   }
   else
   {
      ptr->front++;
      int a = ptr->arr[ptr->front];
      // printf("Element deleted-->%d\n",a);
      return a;
   }
}

void queueTraversal(struct queue *ptr)
{
   if(ptr->front==-1)
   {
      for(int i=0;i<=ptr->rear;i++)
      {
         printf("index-->%d Element-->%d\n",i,ptr->arr[i]);
      }
   }
   else
   {
      for(int i=ptr->front;i<=ptr->rear;i++)
      {
         printf("index-->%d Element-->%d\n",i,ptr->arr[i]);
      }

   }
}



int main()
{
   //Queue Using Array Implementation
   struct queue q;
   q.size=100;
   q.front=-1;
   q.rear=-1;
   q.arr=(int *)malloc(q.size * sizeof(int));

   //BFS IMPLEMENTATION

   int node;
   int i=4;
   int visited[7]={0,0,0,0,0,0,0};

   int a[7][7]={
      {0,1,1,1,0,0,0},
      {1,0,1,0,0,0,0},
      {1,1,0,1,1,0,0},
      {1,0,1,0,1,0,0},
      {0,0,1,1,0,1,1},
      {0,0,0,0,1,0,0},
      {0,0,0,0,1,0,0},
   };

   printf("%d ",i);

   visited[i]=1;
   Enqueue(&q,i);

   while(!isEmpty(&q))
   {
      node=Dequeue(&q);
      for(int j=0;j<7;j++)
      {
         if(a[node][j]==1 && visited[j]==0)
         {
            printf("%d ",j);
            visited[j]=1;
            Enqueue(&q,j);
         }
      }
   }




   return 0;
}