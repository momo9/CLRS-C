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

void listInsert(Node *pn, int val) {
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
Node *listSearch(List *pl, int val) {
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
