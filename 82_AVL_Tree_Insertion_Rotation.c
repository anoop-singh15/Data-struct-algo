#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node
{
    struct node *left;
    struct node *right;
    int key;
    int height;
};

// max function conditional operator
int max(int a, int b)
{
    return ((a > b) ? a : b);
}

int getHeight(struct node *n)
{
    if (n == NULL)
    {
        return 0;
    }
    return n->height;
}

struct node *createNode(int value)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->key = value;
    temp->left = NULL;
    temp->right = NULL;
    temp->height = 1;

    return temp;
}

// Important function 1
int balanceFactor(struct node *n)
{
    if (n == NULL)
        return 0;
    return (getHeight(n->left) - getHeight(n->right));
}

// important function 2 for Right ROTATE
struct node *rightrotate(struct node *y)
{
    // Make structure pointer which will rotate ,and link them with root node
    struct node *x = y->left;
    struct node *t2 = x->right;

    // link after rotation
    x->right = y;
    y->left = t2;

    // change height of x and  y
    x->height = max(getHeight(x->right), getHeight(x->left)) + 1;
    y->height = max(getHeight(y->right), getHeight(y->left)) + 1;

    // changed root is now x
    return x;
}

// important function 3 for left ROTATE
struct node *leftrotate(struct node *x)
{
    // Make structure pointer which will rotate ,and link them with root node
    struct node *y = x->right;
    struct node *t2 = y->left;

    // Liink after rotation
    y->left = x;
    x->right = t2;

    // change height of x and  y
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    // changed root is now y
    return y;
}

// Node Insertion
struct node *insertion(struct node *n, int key)
{
    if (n == NULL)
    {
        return (createNode(key));
    }
    if (key < n->key)
    {
        n->left = insertion(n->left, key);
    }
    else if (key > n->key)
    {
        n->right = insertion(n->right, key);
    }

    n->height = 1 + max(getHeight(n->left), getHeight(n->right));
    int balancef = balanceFactor(n);

    // Left Left case
    if (balancef > 1 && key < n->left->key)
    {
        return rightrotate(n);
    }
    // Right Right case
    if (balancef < -1 && key > n->right->key)
    {
        return leftrotate(n);
    }
    // Left Right case
    if (balancef > 1 && key > n->left->key)
    {
        n->left = leftrotate(n->left);
        return rightrotate(n);
    }
    // Right left case
    if (balancef < -1 && key < n->right->key)
    {
        n->right = rightrotate(n->right);
        return leftrotate(n);
    }
    return n;
}

void preorderTraversal(struct node *n)
{

    if (n != NULL)
    {
        printf("%d ", n->key);

        preorderTraversal(n->left);
        preorderTraversal(n->right);
    }
}

int main()
{
    struct node *root = NULL;
    root = insertion(root, 1);
    root = insertion(root, 10);
    root = insertion(root, 2);
    root = insertion(root, 3);      
    root = insertion(root, 4);
    root = insertion(root, 5);


    preorderTraversal(root);

    return 0;
}