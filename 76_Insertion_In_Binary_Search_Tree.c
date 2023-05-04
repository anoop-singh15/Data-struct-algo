#include <stdio.h>
#include <string.h>
#include <stdlib.h>



struct node
{
    struct node *left;
    int data;
    struct node *right;
};

void inOrderTraversal(struct node *root)
{
    if (root != NULL)
    {
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
    }
}

struct node *createNode(int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

void insert(struct node * root,int value)
{
    struct node* n=NULL;
    while(root!=NULL)
    {
        n=root;
        if(value==root->data)
        {
            printf("\nInsertion Not possible %d already exits in BST",value);
           return;
        }
        else if(value>root->data)
        {
            root=root->right;
            
        }
        else if(value<root->data)
        {
            root=root->left;
            
        }
        
    }
    struct node *new=createNode(value);
    if(value>n->data)
    {
        n->right=new;
    }
    else  if(value<n->data)
    {
        n->left=new;
    }

    
}



int main()
{
    int a;
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
    insert(root,8);
    printf("\nAfter Insertion\n");
    inOrderTraversal(root);

    
   

  

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