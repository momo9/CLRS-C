#ifndef LIST_H
#define LIST_H
#include "node.h"

#define LIST_FREE(pl)           free(pl); (pl) = NULL
#define LIST_NIL(pl)            (pl)->pNil
#define LIST_FRONT(pl)          (pl)->pNil->pPost
#define LIST_BACK(pl)           (pl)->pNil->pPre

typedef struct List{
  Node *pNil;
} List;

// Should be freed by listFree()
List *listFactory();
void listFree(List *pl);

void listInsert(Node *pn, int val);

void listDelete(Node *pn);

void listTrav(List *pl);

// return NULL when not found
// return the node when found
Node *listSearch(List *pl, int val);

#endif
