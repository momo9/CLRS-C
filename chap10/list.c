#include "list.h"
#include <stdlib.h>
#include <stdio.h>
#include "tool.h"

// Should be freed by listFree()
List *listFactory() {
  List *pl = ALLOC_ONE(List);
  LIST_NIL(pl) = nodeFactory(0);
  return pl;
}

void listFree(List *pl){
  Node *pDel = LIST_BACK(pl);
  Node *pNext = pDel->pPre;
  while (pDel != LIST_NIL(pl)) {
    NODE_FREE(pDel);
    pDel = pNext;
    pNext = pDel->pPre;
  }
  NODE_FREE(LIST_NIL(pl));
  free(pl);
  pl = NULL;
}

void listInsert(Node *pn, NodeValType val) {
  Node *pPre = pn->pPre;
  Node *pNew = nodeFactory(3, pPre, val, pn);
  pPre->pPost = pNew;
  pn->pPre = pNew;
}

void listDelete(Node *pn) {
  pn->pPre->pPost = pn->pPost;
  pn->pPost->pPre = pn->pPre;
  NODE_FREE(pn);
}

void listTrav(List *pl) {
  Node *pn;
  for (pn = LIST_FRONT(pl); pn != LIST_NIL(pl); pn = pn->pPost) {
    PUTD(pn->val);
  }
  puts("");
}

// return NULL when not found
// return the node when found
Node *listSearch(List *pl, NodeValType val) {
  LIST_NIL(pl)->val = val;
  Node *pn;
  for (pn = LIST_FRONT(pl); pn->val != val; pn = pn->pPost);
  if (pn == LIST_NIL(pl)) {
    puts("X");
  } else {
    puts("O");
  }
  return (pn == LIST_NIL(pl)) ? NULL : pn;
}

// exercise 10.2-6
// pl1 is the union
void listUnion(List *pl1, List *pl2) {
  LIST_BACK(pl1)->pPost = LIST_FRONT(pl2);
  LIST_FRONT(pl2)->pPre = LIST_BACK(pl1);
  LIST_BACK(pl2)->pPost = LIST_NIL(pl1);
  LIST_NIL(pl1)->pPre = LIST_BACK(pl2);
  // empty pl2, but didn't free it
  // otherwies whether free it later is confused
  LIST_NIL(pl2)->pPre = LIST_NIL(pl2)->pPost = LIST_NIL(pl2);
}
