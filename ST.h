#ifndef _ST_
#define _ST_

#include <stdlib.h>
#include <stdio.h>

typedef struct STnode* avlLink;

void STinit(avlLink*);
int STcount(avlLink);
char* STsearch(avlLink, char*);
avlLink STinsert(avlLink, char*);
avlLink STdelete(avlLink head, char *k);
void STsort(avlLink head, int pathLen, char *input);
void STsortDelete(avlLink head, int pathLen, char *input);
avlLink STfree(avlLink head);

#endif