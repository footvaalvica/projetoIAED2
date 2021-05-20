/* C program to insert a node in AVL tree */
#include "avl.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
/* A utility function to get maximum of two integers */
int max(int a, int b);
 
/* A utility function to get the height of the tree */
int height(struct Node *N)
{
    if (N == NULL)
        return 0;
    return N->height;
}
 
/* A utility function to get maximum of two integers */
int max(int a, int b)
{
    return (a > b)? a : b;
}
 
/* Helper function that allocates a new node with the given key and
    NULL left and right pointers. */
struct Node* newNode(char *path)
{
    struct Node* node = (avlLink) malloc(sizeof(avlLink));
    node->path = (char *)malloc(sizeof(char) * (strlen(path) + 1));
    strcpy(node->path, path);
    node->left = NULL;
    node->right = NULL;
    node->height = 1;  /* new node is initially added at leaf */
    return(node);
}
 
/* A utility function to right rotate subtree rooted with y
See the diagram given above. */
struct Node *rightRotate(struct Node *y)
{
    struct Node *x = y->left;
    struct Node *T2 = x->right;
 
    /* Perform rotation */
    x->right = y;
    y->left = T2;
 
    /* Update heights */
    y->height = max(height(y->left), height(y->right))+1;
    x->height = max(height(x->left), height(x->right))+1;
 
    /* Return new root */
    return x;
}
 
/* A utility function to left rotate subtree rooted with x
See the diagram given above. */
struct Node *leftRotate(struct Node *x)
{
    struct Node *y = x->right;
    struct Node *T2 = y->left;

    /* Perform rotation */
    y->left = x;
    x->right = T2;
 
    /*  Update heights */
    x->height = max(height(x->left), height(x->right))+1;
    y->height = max(height(y->left), height(y->right))+1;
 
    /* Return new root */
    return y;
}
 
/* Get Balance factor of node N */
int getBalance(struct Node *N)
{
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}
 
/* Recursive function to insert a key in the subtree rooted
with node and returns the new root of the subtree. */
struct Node* insert(struct Node* node, char *path)
{   
    int balance;

    /* 1.  Perform the normal BST insertion */
    if (node == NULL)
        return(newNode(path));
 
    if (strcmp(path, node->path) < 0)
        node->left = insert(node->left, path);
    else if (strcmp(path, node->path) > 0)
        node->right = insert(node->right, path);
    else /* Equal keys are not allowed in BST */
        return node;
 
    /* 2. Update height of this ancestor node */
    node->height = 1 + max(height(node->left), height(node->right));
 
    /* 3. Get the balance factor of this ancestor
          node to check whether this node became
          unbalanced */
    balance = getBalance(node);
 
    /* If this node becomes unbalanced, then
    there are 4 cases */
 
    /* Left Left Case */
    if (balance > 1 && (strcmp(path, node->left->path) < 0))
        return rightRotate(node);

    /* Right Right Case */
    if (balance < -1 && (strcmp(path, node->right->path) > 0))
        return leftRotate(node);
 
    /* Left Right Case */
    if (balance > 1 && (strcmp(path, node->left->path) > 0))
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
 
    /* Right Left Case */
    if (balance < -1 && (strcmp(path, node->right->path) < 0))
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
 
    /* return the (unchanged) node pointer */
    return node;
} 
 
/* A utility function to print trcee in order */
void printAVL(struct Node *root, int pathLen, char *input)
{
    char *path;
    char *pathChopped;
    char *helper;
    int compareBytes;

    compareBytes = strlen(input);

    if(root != NULL)
    {
        printAVL(root->left, pathLen, input);

        path = (char *) malloc(sizeof(char) * (strlen(root->path) + 1));
        strcpy(path, root->path);
        
        pathChopped = path + pathLen + 1;

        if (strcmp(pathChopped, "") != 0) {
            if (strncmp(path, input, compareBytes) == 0) {
                helper = strchr(pathChopped, '/');
                if (helper == NULL) {
                    printf("%s\n", pathChopped);
                }
            }
        }
        
        free(path);

        printAVL(root->right, pathLen, input);
    }
}