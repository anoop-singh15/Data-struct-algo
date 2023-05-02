#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
        SEARCH WITHOUT RECURSION----->Iterative Search
*/

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

struct node *iterativeSearch(struct node *root, int key)
{
    while (root != NULL)
    {

        if (root->data == key)
        {
            return root;
        }
        else if (key > root->data)
        {
            root = root->right;
        }
        else
        {
            root = root->left;
        }
    }
    return NULL;
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
    scanf("%d", &a);
    struct node *value = iterativeSearch(root, a);

    if (value != NULL)
    {
        printf("Found:%d\n", value->data);
    }
    else
    {
        printf("Not Found\n");
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