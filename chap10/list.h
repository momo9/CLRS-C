#ifndef LIST_H
#define LIST_H
#include "node.h"

#define LIST_FREE(pl)           free(pl); (pl) = NULL
#define LIST_NIL(pl)            (pl)->pNil
#define LIST_FRONT(pl)          (pl)->pNil->pPost
#define LIST_BACK(pl)           (pl)->pNil->pPre

#define LIST_PUSH_BACK(pl, v)   listInsert(LIST_NIL(pl), (v))

typedef struct List{
  Node *pNil;
} List;

// Should be freed by listFree()
List *listFactory();
void listFree(List *pl);

void listInsert(Node *pn, NodeValType val);

void listDelete(Node *pn);

void listTrav(List *pl);

// return NULL when not found
// return the node when found
Node *listSearch(List *pl, NodeValType val);

// exercise 10.2-6
// pl1 is the union
void listUnion(List *pl1, List *pl2);

#endif
