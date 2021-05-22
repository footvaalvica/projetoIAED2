#include "ST.h"

struct STnode {
    Item item; 
    avlLink l, r; 
    int height
};

void update_height(avlLink h)
{
    int height_left = height(h->l); 
    int height_right = height(h->r);
    h->height = height_left > 
    height_right ? height_left + 1 : 
    height_right + 1;
}

avlLink new(Item item, avlLink l, avlLink r)
{
    avlLink x = (avlLink)malloc(sizeof(struct STnode));

    /* malloc of the string */
    x->item = (char *)malloc(sizeof(char) * (strlen(item) + 1));
    strcpy(x->item, item);

    x->l = l;
    x->r = r;
    x->height=1;
    return x;
}

int height(avlLink h){
    if (h == NULL) return 0;
    return h->height;
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

avlLink insertR(avlLink h, Item item) 
{
    if (h == NULL) 
        return new(item, NULL, NULL);
    if ((strcmp(item, h->item) < 0))
        h->l = insertR(h->l, item);
    else 
        h->r = insertR(h->r, item);
    h=AVLbalance(h);
    return h;
}

avlLink deleteR(avlLink h, Key k) {
    if (h==NULL) return h; 
    else if ((strcmp(k, h->item) < 0)) h->l=deleteR(h->l,k);
    else if ((strcmp(h->item, k) < 0)) h->r=deleteR(h->r,k) ;
    else {
        if (h->l !=NULL && h->r !=NULL) { 
            avlLink aux = max(h->l);
            {Item x; x=h->item; h->item=aux->item; aux->item=x;} 
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