#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED

typedef struct node {
    char *path;
    char *value;
    struct node *next;
} *link;

link insertEnd(link head, char *path, char *value);
link lookupValue(link head, char *value);

/*disponibilzei o insert begin */
link insertBegin(link head, char *path, char *value);
link lookupPath(link head, char *path);
void printList(link head);
link deleteFromLinkedList(link h, char *path);
void deleteList(struct node** head);

#endif