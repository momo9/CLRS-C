#include "tool.h"
#include "array_tree.h"
#include <stdio.h>

// should be freed by TREE_FREE()
ArrayTree *treeFactory() {
  ArrayTree *pt = ALLOC_ONE(ArrayTree);
  int i;
  for (i = 0; i < TREE_SIZE; ++i) {
    pt->valid[i] = 0;
  }
  return pt;
}

void treeInsert(ArrayTree *pt, TypeTreeVal val, int pos) {
  pt->tree[pos] = val;
  pt->valid[pos] = 1;
}

void treeDelete(ArrayTree *pt, int pos) {
  pt->valid[pos] = 0;
}

void walkNonRecur(ArrayTree *pt) {
  char walked[TREE_SIZE];
  int i;
  for (i = 0; i < TREE_SIZE; ++i) walked[i] = 0;
  
  int ml = findMostLeft(pt);
  int mr = findMostRight(pt);
  int pos = ml;
  while (1) {
    int left = TREE_LEFT(pos);
    if (!pt->valid[left] || walked[left]) {
      if (walked[pos]) {
        pos = TREE_PAR(pos);
      } else {
        PUTD(pt->tree[pos]);
        walked[pos] = 1;
        int right = TREE_RIGHT(pos);
        if (!pt->valid[right]) {
          if (pos == mr) {
            break;
          } else {
            pos = TREE_PAR(pos);
          }
        } else {
          pos = right;
        }
      }
    } else {
      pos = left;
    }
  }
  puts("");
}

int findMostLeft(ArrayTree *pt) {
  int pos;
  for (pos = 0; pt->valid[TREE_LEFT(pos)]; pos = TREE_LEFT(pos));
  return pos;
}
int findMostRight(ArrayTree *pt) {
  int pos;
  for (pos = 0; pt->valid[TREE_RIGHT(pos)]; pos = TREE_RIGHT(pos));
  return pos;
}

// findMax(0)
int findMax(ArrayTree *pt, int pos) {
  int right = TREE_RIGHT(pos);
  if (isValid(pt, right)) {
    return findMax(pt, right);
  } else {
    return pos;
  }
}

// findMin(0)
int findMin(ArrayTree *pt, int pos) {
  int left = TREE_LEFT(pos);
  if (isValid(pt, left)) {
    return findMin(pt, left);
  } else {
    return pos;
  }
}

int findPre(ArrayTree *pt, int pos) {
  int left = TREE_LEFT(pos);
  if (isValid(pt, left)){
    return findMax(pt, left);
  } else {
    int par = TREE_PAR(pos);
    while (pos != 0 && TREE_LEFT(par) == pos) {
      pos = par;
      par = TREE_PAR(par);
    }
    return (par == pos) ? -1 : par;
  }

}

int findPost(ArrayTree *pt, int pos) {
  int right = TREE_RIGHT(pos);
  if (isValid(pt, right)){
    return findMin(pt, right);
  } else {
    int par = TREE_PAR(pos);
    while (pos != 0 && TREE_RIGHT(par) == pos) {
      pos = par;
      par = TREE_PAR(par);
    }
    return (par == pos) ? -1 : par;
  }
}

int treeSearch(ArrayTree *pt, TypeTreeVal val) {
  int pos = 0;
  while (isValid(pt, pos) && pt->tree[pos] != val) {
    if (pt->tree[pos] < val) {
      pos = TREE_RIGHT(pos);
    } else {
      pos = TREE_LEFT(pos);
    }
  }
  return (isValid(pt, pos) ? pos : -1);
}

int isValid(ArrayTree *pt, int pos) {
  return pt->valid[pos] && pos < TREE_SIZE;
}

