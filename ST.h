#ifndef _ST_
#define _ST_

#include "linkedList.h"

typedef struct STnode* avlLink;

void STinit(avlLink*);
int STcount(avlLink);
char* STsearch(avlLink, char*);
avlLink STinsert(avlLink, char*);
void STsort(avlLink head, int pathLen, char *input);
void STsortDelete(avlLink *head, link *headLL, int pathLen, char *input);
void STdelete(avlLink* head, char *k);
avlLink STfree(avlLink head);

#endif