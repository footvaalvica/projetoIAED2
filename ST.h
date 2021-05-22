#ifndef _ST_
#define _ST_

#include <stdlib.h>
#include <stdio.h>

typedef char* Item;
typedef char* Key;

typedef struct STnode* avlLink;

void STinit(avlLink*);
int STcount(avlLink);
Item STsearch(avlLink,Key);
void STinsert(avlLink*,Item);
void STdelete(avlLink*,Key);
void STsort(avlLink,void (*visit)(Item));
void STfree(avlLink*);

#endif