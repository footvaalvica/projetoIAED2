#include "ST.h"
#include "linkedList.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct STnode {
    char *item; 
    avlLink l, r; 
    int height;
};

int height(avlLink h){
    if (h == NULL) return 0;
    return h->height;
}

avlLink max(avlLink h) {
    if (h == NULL || h->r == NULL) return h;
    else return max(h->r);
}

void update_height(avlLink h)
{
    int height_left = height(h->l); 
    int height_right = height(h->r);
    h->height = height_left > 
    height_right ? height_left + 1 : 
    height_right + 1;
}

avlLink new(char* item, avlLink l, avlLink r)
{
    avlLink x = (avlLink)malloc(sizeof(struct STnode));

    /* malloc of the string */
    x->item = (char *)malloc(sizeof(char) * (strlen(item) + 1));
    strcpy(x->item, item);

    x->l = l;
    x->r = r;
    x->height = 1;
    return x;
}

avlLink rotL(avlLink h) 
{
    avlLink x = h->r;
    h->r = x->l;
    x->l = h;
    update_height(h);
    update_height(x);
    return x;
}

avlLink rotR(avlLink h) 
{
    avlLink x = h->l;
    h->l = x->r;
    x->r = h;
    update_height(h);
    update_height(x);
    return x; 
}

avlLink rotLR(avlLink h) /*rotação dupla esquerda direita*/
{
    if (h==NULL) return h;
    h->l=rotL(h->l);
    return rotR(h); 
}

avlLink rotRL(avlLink h) /*rotação dupla direita esquerda*/
{
    if (h==NULL) return h;
    h->r=rotR(h->r); 
    return rotL(h); 
}

int Balance(avlLink h) {/*Balance factor*/ 
    if(h == NULL) return 0; 
    return height(h->l)-height(h->r); 
}

avlLink AVLbalance(avlLink h) { 
    int balanceFactor;
    if (h==NULL) return h;
    balanceFactor= Balance(h); 
    if(balanceFactor>1) { 
        if (Balance(h->l)>=0) h=rotR(h); 
        else h=rotLR(h); 
    } 
    else if(balanceFactor<-1) { 
        if (Balance(h->r)<=0) h = rotL(h); 
        else h = rotRL(h); 
    }
    else
        update_height(h);
    return h; 
}

avlLink insertR(avlLink h, char *item) 
{
    if (h == NULL) {
        return new(item, NULL, NULL);
    }
    if ((strcmp(item, h->item) < 0))
        h->l = insertR(h->l, item);
    else 
        h->r = insertR(h->r, item);
    h = AVLbalance(h);
    return h;
}

avlLink deleteR(avlLink h, char* k) {
    if (h==NULL) return h; 
    else if ((strcmp(k, h->item) < 0)) h->l=deleteR(h->l,k);
    else if ((strcmp(h->item, k) < 0)) h->r=deleteR(h->r,k) ;
    else {
        if (h->l !=NULL && h->r !=NULL) { 
            avlLink aux = max(h->l);
            {char* x; x=h->item; h->item=aux->item; aux->item=x;} 
            h->l= deleteR(h->l, aux->item);
        }
        else {
            avlLink aux=h;
            if (h->l == NULL && h->r == NULL) h=NULL;
            else if (h->l==NULL) h=h->r;
            else h=h->l;
            free(aux->item);
            free(aux);
        }
    } 
    h = AVLbalance(h);
    return h;
}

avlLink STinsert(avlLink head, char *item)
{   
    head = insertR(head, item);
    return head;
}

char* searchR(avlLink h, char *v)
{
    if (h == NULL)
        return NULL;
    if (strcmp(v, h->item) == 0)
        return h->item;
    if (strcmp(v, h->item) == 0)
        return searchR(h->l, v);
    else
        return searchR(h->r, v);
}

char* STsearch(avlLink head, char *v)
{
    return searchR(head, v);
}

void STdelete(avlLink* head, char *k) {
    *head = deleteR(*head, k);
}

avlLink freeR(avlLink h)
{
    if (h == NULL)
    return h;
    h->l = freeR(h->l);
    h->r = freeR(h->r);
    return deleteR(h, h->item);
}

avlLink STfree(avlLink head)
{
    head = freeR(head);
    return head;
}

void sortR(avlLink h, int pathLen, char *input)
{
    char *path;
    char *pathChopped;
    char *helper;
    int compareBytes;

    if (h == NULL)
    return;

    compareBytes = strlen(input);

    sortR(h->l, pathLen, input);

    /* allocating memory for a string */
    path = (char *) malloc(sizeof(char) * (strlen(h->item) + 1));
    strcpy(path, h->item);
        
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

    sortR(h->r, pathLen, input);
}

void STsort(avlLink head, int pathLen, char *input)
{
    sortR(head, pathLen, input);
}

void STsortDelete(avlLink *head, link *headLL, int pathLen, char *input)
{
    char *path;
    int compareBytes;
    avlLink h = *head;


    if (h == NULL)
    return;

    compareBytes = strlen(input);

    STsortDelete(&(h->l), headLL, pathLen, input);
    STsortDelete(&(h->r), headLL, pathLen, input);

    /* allocating memory for a string */
    path = (char *) malloc(sizeof(char) * (strlen(h->item) + 1));
    strcpy(path, h->item);

    if (strcmp(path, "") != 0) {
        if (strncmp(path, input, compareBytes) == 0) {
            STdelete(head, path);
            deleteFromLinkedList(*headLL, path);
        }
    }

    free(path);
}