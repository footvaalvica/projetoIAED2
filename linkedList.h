#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED

typedef struct node {
    char *path;
    char *value;
    struct node *next;
} *link;

link insertEnd(link head, char *path, char *value);
link lookupValue(link head, char *value);
link lookupPath(link head, char *path);
void printList(link head);
void deleteFromLinkedList(struct node** head, char *path);
void deleteList(struct node** head);

#endif