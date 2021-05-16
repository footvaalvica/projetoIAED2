#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedList.h"

/* Função auxiliar responável por alocar memória para 
tudo o que é necessário para um novo nó */

linkedListLink NEW(char *buffer)
{
    /*reservar memória para novo nó */
    linkedListLink x = (linkedListLink)malloc(sizeof(struct linkedListNode)); 
    /*reservar memória para nova string*/
    x->text = (char *)malloc(sizeof(char) * (strlen(buffer) + 1));
    strcpy(x->text, buffer);
    x->next = NULL;
    return x;
}

linkedListLink insertBegin(linkedListLink head, char* text)
{
    linkedListLink x = NEW(text);
    x->next = head;
    return x;
}

linkedListLink insertEnd(linkedListLink head, char *text)
{
    linkedListLink x;
    if (head == NULL)
        return NEW(text);
    for (x = head; x->next != NULL; x = x->next) /*loop para chegar ao fim da lista*/
        ;
    x->next = NEW(text); /*recorrer à função new*/
    return head;
}

linkedListLink lookup(linkedListLink head, char *text)
{
    linkedListLink t;
    for (t = head; t != NULL; t = t->next)
        if (strcmp(t->text, text) == 0)
            return t;
    return NULL;
}

void printList(linkedListLink head)
{
    linkedListLink t;
    for (t = head; t != NULL; t = t->next)
        printf("%s\n", t->text);
}

linkedListLink deleteFromLinkedList(linkedListLink head, char *text)
{
    linkedListLink t, prev;
    for (t = head, prev = NULL; t != NULL;
         prev = t, t = t->next)
    {
        if (strcmp(t->text, text) == 0)
        {
            if (t == head)
                head = t->next;
            else
                prev->next = t->next;
            free(t->text);
            free(t);
            break;
        }
    }
    return head;
}

void FREEnode(linkedListLink t)
{
    free(t->text);
    free(t);
}