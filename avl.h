/* An AVL tree node */
struct Node
{
    int height;
    char *key;
    void *value;
    struct Node *left;
    struct Node *right;
};

struct Node* insert(struct Node* node, char *key);
void preOrder(struct Node *root);