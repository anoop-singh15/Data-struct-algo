#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/*
        Time Complexity ---> O(logn)
        total comparision in binary search tree is height of tree
        height worst  case (n) and best case of height is (logn) 
*/


struct node
{
    struct node *left;
    int data;
    struct node *right;
};

struct node *createNode(int data)
{
    struct node *temp=(struct node *)malloc(sizeof(struct node));
    temp->data=data;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
} 

void   inOrderTraversal(struct node *root)
{
    if(root!=NULL)
    {
        inOrderTraversal(root->left);
        printf("%d ",root->data);
        inOrderTraversal(root->right);
    }
}

// SEARCHING IN BINARY SEARCH TREE
void  search(struct node *root,int key)
{
    if(root!=NULL)
    {
         if(key==root->data)
        {
            printf("\nFound:%d\n",root->data);
        }
       
        else if(key>root->data)
        {
            search(root->right,key);
        }
        else 
        {
           search(root->left,key);
        }
    }
    else
    {
        printf("\nNot found\n");
    }
}

struct node *search2(struct node *root,int key)
{
    if(root==NULL)
    {
        return NULL;
    }
    if(key==root->data)
    {
        return root;
    }
    else if(key>root->data)
    {
        return search2(root->right,key);
    }
    else
    {
        return search2(root->left,key);
    }
}


int main()
{
   struct node *root = createNode(9);
    struct node *child1 = createNode(4);
    struct node *child2 = createNode(2);
    struct node *child3 = createNode(7);
    struct node *child4 = createNode(5);
    struct node *child5 = createNode(8);
    struct node *child6 = createNode(11);
    struct node *child7 = createNode(15);
    struct node *child8 = createNode(14);

    // linking root nodes
    root->left = child1;
    child1->left = child2;
    child1->right = child3;

    child2->left = NULL;
    child2->right = NULL;

    child3->left = child4;
    child4->left = NULL;
    child4->right = NULL;

    child3->right = child5;
    child5->left = NULL;
    child5->right = NULL;

    root->right = child6;
    child6->left = NULL;
    child6->right = child7;

    child7->left = child8;
    child7->right = NULL;

    inOrderTraversal(root);
   

    //SEARCH 
    // search(root,8);


    //SEARCH-2
    struct node *searchBst=search2(root,8);
    if(searchBst!=NULL)
    {
        printf("\nFound:%d\n",searchBst->data);
    }
    else
    {
        printf("\nNot Found\n");
    }
    

    free(root);
    free(child1);
    free(child2);
    free(child3);
    free(child4);
    free(child5);
    free(child6);
    free(child7);
    free(child8);

   return 0;
}