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

// PreOrder Traversal
void preOrderTraversal(struct node *root)
{
    // Terminating Condition
    if (root != NULL)
    {
        printf("%d ", root->data);
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}

// Post Order Traversal
void postOrderTraversal(struct node *root)
{
    // Terminating Condition
    if (root != NULL)
    {

        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        printf("%d ", root->data);
    }
}

int main()
{
    // constructing node with function
    struct node *root = createNode(4);
    struct node *child1 = createNode(2);
    struct node *child2 = createNode(3);
    struct node *child3 = createNode(1);
    struct node *child4 = createNode(6);
    struct node *child5 = createNode(8);
    struct node *child6 = createNode(9);

    // linking root and child node 1 and 2
    root->left = child1;
    root->right = child2;

    child1->left = child3;
    child3->left = NULL;
    child3->right = NULL;

    child1->right = child4;
    child4->left = NULL;
    child4->right = NULL;

    child2->left = child5;
    child5->left = NULL;
    child5->right = NULL;

    child2->right = child6;
    child6->left = NULL;
    child6->right = NULL;

    // PREORDER Traversal function call
    printf("\nPREORDER Traversal\n");
    preOrderTraversal(root);

    // POSTORDER Traversal function call
    printf("\n\n\nPOSTORDER Traversal\n");
    postOrderTraversal(root);
   


    free(root);
    free(child1);
    free(child2);
    free(child3);
    free(child4);
    free(child5);
    free(child6);

    return 0;
}