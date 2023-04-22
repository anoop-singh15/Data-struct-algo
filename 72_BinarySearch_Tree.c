#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
        1> All nodes of left subtree are lesser
        2> All nodes of right subtree are greater
        3> Left and Right subtrees are also Binary Search Tree
        4> There are no duplicate nodes
        5> In order traversal of Binary Search Tree gives an ascending sorted array
*/

struct node
{
    struct node *left;
    int data;
    struct node *right;
};

struct node *createNode(int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

void inOrderTraversal(struct node *root)
{

    if (root != NULL)
    {
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
    }
}


// inorder related 
int isBST(struct node *root)
{
    static struct node *prev = NULL;
    if (root != NULL)
    {
        if (!isBST(root->left))
        {
            return 0;
        }
        if (prev != NULL && root->data <= prev->data)
        {
            return 0;
        }
        prev = root;
        return isBST(root->right);
    }

    else
    {
        return 1;
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
    printf("\nThis is a Binary search tree  %d\n", isBST(root));

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