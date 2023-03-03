#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct stack
{
   int *arr;
   int size;
   int top;
};

int isEmpty(struct stack *ptr)
{
   if (ptr->top == -1)
   {
      return 1;
   }
   else
   {
      return 0;
   }
}

int isFull(struct stack *ptr)
{
   if (ptr->top == ptr->size - 1)
   {
      return 1;
   }
   else
   {
      return 0;
   }
}
int pushElement(struct stack *ptr)
{
   int a;
   printf("Enter No. of element\n");
   scanf("%d", &a);
   for (int i = 0; i < a; i++)
   {
      scanf("%d", &ptr->arr[i]);
      ptr->top++;
   }
}

int elementTraversal(struct stack *ptr)
{
   if (ptr->top > 0)
      for (int i = 0; i <= ptr->top; i++)
      {
         printf("Element at index %d is %d\n",i,ptr->arr[i]);
      }
   else
   {
      return 0;
   }   
}

int main()
{
   // struct stack s;
   // s.size=80;
   // s.top=-1;
   // s.arr=(int *)malloc(s.size * sizeof(int ));

   struct stack *s = (struct stack *)malloc(sizeof(struct stack));
   s->size = 80;
   s->top = -1;

   s->arr = (int *)malloc(s->size * sizeof(int));

   // To push an element in stack
   // s->arr[0]=4;
   // s->top++;

   // To push an element using code 
   pushElement(s);
   

   // To check if stack is empty
   if (isEmpty(s))
   {
      printf("The stack is empty\n");
   }
   else
   {
      printf("The stack is not empty\n");
   }

   // To traversal an array
   elementTraversal(s);

   return 0;
}