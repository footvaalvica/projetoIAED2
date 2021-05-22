#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedList.h"

/* função para dar free de todos os componentes de um node no delete */
void FREEnode(link t)
{
    free(t->path);
    free(t->value);
    free(t);
}

/* Função auxiliar responável por alocar memória para 
tudo o que é necessário para um novo nó */
link NEW(char *path, char *value)
{
    link x = (link)malloc(sizeof(struct node)); /*reservar memória para novo nó*/
    /*reservar memória para as novas strings*/
    x->path = (char *)malloc(sizeof(char) * (strlen(path) + 1));
    strcpy(x->path, path);
    x->value = (char *)malloc(sizeof(char) * (strlen(value) + 1));
    strcpy(x->value, value);
    x->next = NULL;
    return x;
}

link insertBegin(link head, char *path, char *value)
{
    link x = NEW(path, value);
    x->next = head;
    return x; /*retorna a nova "head"*/
}

link insertEnd(link head, char *path, char *value)
{
    link x;
    if (head == NULL)
        return NEW(path, value);
    for (x = head; x->next != NULL; x = x->next); /*loop para chegar ao fim da lista*/
    x->next = NEW(path, value); /*recorrer à função new*/
    return head;
}

link lookupValue(link head, char *value)
{
    link t;
    for (t = head; t != NULL; t = t->next) {
        if (strcmp(t->value, value) == 0)
            return t;
    }
    return NULL;
}

link lookupPath(link head, char *path)
{
    link t;
    for (t = head; t != NULL; t = t->next) {
        if (strcmp(t->path, path) == 0)
            return t;
    }
    return NULL;
}

void printList(link head)
{
    link t;
    for (t = head; t != NULL; t = t->next) {
        if (strcmp(t->value, "") != 0) {
            printf("/%s ", t->path);
            printf("%s\n", t->value);
        }
    }
}

void deleteFromLinkedList(struct node** head, char *path)
{   
    link t, prev, h = *head;

    for (t = h, prev = NULL; t != NULL;
         prev = t, t = t->next)
    {
        if (strcmp(t->path, path) == 0)
        {
            if (t == h)
                h = t->next;
            else
                prev->next = t->next;
            FREEnode(t);
            break;
        }
    }
}

void deleteList(struct node** head)
{
    /* deref head_ref to get the real head */
    struct node* current = *head;
    struct node* next;
 
    while (current != NULL)
    {
        next = current->next;
        FREEnode(current);
        current = next;
    }
   
    /* deref head_ref to affect the real head back
      in the caller. */
    *head = NULL;
}

