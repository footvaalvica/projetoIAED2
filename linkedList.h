#ifndef LINKED_LIST_H_INCLUDED
#define LINKED_LIST_H_INCLUDED

struct linkedListNode{
    char *text;
    struct linkedListNode *next;
};

typedef struct linkedListNode *linkedListLink;

/* Função auxiliar responável por alocar memória para 
tudo o que é necessário para um novo nó */
linkedListLink insertBegin(linkedListLink head, char* text);
linkedListLink insertEnd(linkedListLink head, char *text);
linkedListLink lookup(linkedListLink head, char *text);
void printList(linkedListLink head);
linkedListLink deleteFromLinkedList(linkedListLink head, char *text);

#endif