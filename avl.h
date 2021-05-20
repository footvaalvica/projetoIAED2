#ifndef AVL_H_INCLUDED
#define AVL_H_INCLUDED

/* C program to insert a node in AVL tree */
 
/* An AVL tree node*/
typedef struct Node {
    char *path;
    struct Node *left;
    struct Node *right;
    int height;
} *avlLink;

avlLink insert(avlLink node, char *path);
void printAVL(struct Node *root, int pathLen, char *input);

#endif