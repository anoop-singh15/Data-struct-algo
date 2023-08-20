#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

/*
-------------->MORRIS TRAVERSAL
               TIME COMP. =   O(N)
               SPACE COMPL. = O(1)

*/

struct TreeNode
{
    int val;
    struct TreeNode *right;
    struct TreeNode *left;
};

void preorder(struct TreeNode *ptr)
{
    if (ptr != NULL)
    {
        printf("%d ", ptr->val);
        preorder(ptr->left);
        preorder(ptr->right);
    }
}

// Morris traversal for INORDER TRAVERSAL
void morrisTraversalInorder(struct TreeNode *root)
{
    struct TreeNode *current = root;
    struct TreeNode *prev = NULL;
    while (current)
    {
        if (current->left == NULL)
        {
            printf("%d ", current->val);
            current = current->right;
        }
        else
        {
            prev = current->left;
            while (prev->right != NULL && prev->right != current)
            {
                prev = prev->right;
            }

            if (prev->right == NULL)
            {
                prev->right = current;
                current = current->left;
            }
            else
            {
                prev->right = NULL;
                // FOR INORDER
                printf("%d ", current->val);
                current = current->right;
            }
        }
    }
}
// Morris traversal for PREORDER
void morrisTraversalPreorder(struct TreeNode *root)
{
    struct TreeNode *current = root;
    struct TreeNode *prev = NULL;
    while (current)
    {
        if (current->left == NULL)
        {
            printf("%d ", current->val);
            current = current->right;
        }
        else
        {
            prev = current->left;
            while (prev->right != NULL && prev->right != current)
            {
                prev = prev->right;
            }

            if (prev->right == NULL)
            {
                // FOR PREORDER
                printf("%d ", current->val);
                prev->right = current;
                current = current->left;
            }
            else
            {
                prev->right = NULL;
                current = current->right;
            }
        }
    }
}

int main()
{

    struct TreeNode *root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    struct TreeNode *second = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    struct TreeNode *secondl = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    struct TreeNode *secondr = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    struct TreeNode *third = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    struct TreeNode *thirdl = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    struct TreeNode *thirdr = (struct TreeNode *)malloc(sizeof(struct TreeNode));

    root->val = 1;
    root->left = second;
    root->right = third;

    second->val = 2;
    second->left = secondl;
    second->right = secondr;

    secondl->val = 3;
    secondl->left = NULL;
    secondl->right = NULL;

    secondr->val = 4;
    secondr->left = NULL;
    secondr->right = NULL;

    third->val = 5;
    third->left = NULL;
    third->right = thirdr;

    // thirdl->val = -1;
    // thirdl->left = NULL;
    // thirdl = NULL;

    thirdr->val = 6;
    thirdr->left = NULL;
    thirdr->right = NULL;

    // Both head1 and head2 traversal
    preorder(root);

    // IN ORDER TRAVERSAL
    printf("\n");
    morrisTraversalInorder(root);
    // PRE ORDER TRAVERSAL
    printf("\n");
    morrisTraversalPreorder(root);
    // preorder(root);

    free(root);
    free(second);
    free(third);

    free(secondl);
    free(secondr);
    free(third);
    free(thirdl);
    free(thirdr);

    return 0;
}