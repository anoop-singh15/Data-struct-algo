#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node
{
    struct node *left;
    int data;
    struct node *right;
};

// Program to create a node
struct node *createNode(int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

int main()
{
    /*
    // constructing root node
    struct node *root = (struct node *)malloc(sizeof(struct node));
    root->left = NULL;
    root->right = NULL;
    root->data = 45;


    // constructing child  node 1
    struct node *child1 = (struct node *)malloc(sizeof(struct node));
    root->left = NULL;
    root->right = NULL;
    child1->data = 4;


    // constructing child  node 2
    struct node *child2 = (struct node *)malloc(sizeof(struct node));
    root->left = NULL;
    root->right = NULL;
   child2->data =2;

    // linking root and child node 1 and 2
    root->left=child1;
    root->right=child2;
    */

    // constructing node with function
    struct node *root = createNode(1);
    struct node *child1 = createNode(2);
    struct node *child2 = createNode(3);

    // linking root and child node 1 and 2
    root->left = child1;
    root->right = child2;

    free(root);
    free(child1);
    free(child2);

    return 0;
}