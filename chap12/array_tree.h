#ifndef ARRAY_TREE_H
#define ARRAY_TREE_H

#define TREE_SIZE       64

#define TREE_FREE(pt)   free(pt); pt = NULL

#define TREE_PAR(pos)   ((pos - 1) / 2)
#define TREE_LEFT(pos)  (pos * 2 + 1)
#define TREE_RIGHT(pos) (pos * 2 + 2)

typedef int TypeTreeVal;

typedef struct ArrayTree {
  TypeTreeVal tree[TREE_SIZE];
  char valid[TREE_SIZE];
} ArrayTree;

// should be freed by TREE_FREE()
ArrayTree *treeFactory();

void treeInsert(ArrayTree *pt, TypeTreeVal val, int pos);
void treeDelete(ArrayTree *pt, int pos);

void walkNonRecur(ArrayTree *pt);
int findMostLeft(ArrayTree *pt);
int findMostRight(ArrayTree *pt);
// findMax(pt, 0)
int findMax(ArrayTree *pt, int pos);
// findMin(pt, 0)
int findMin(ArrayTree *pt, int pos);

int treeSearch(ArrayTree *pt, TypeTreeVal val);
int findPre(ArrayTree *pt, int pos);
int findPost(ArrayTree *pt, int pos);

int isValid(ArrayTree *pt, int pos);

#endif
