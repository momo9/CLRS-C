#include <stdio.h>
#include "tool.h"
#include "array_tree.h"

main() {
  ArrayTree *pt = treeFactory();

  treeInsert(pt,  20, 0 );
  treeInsert(pt,  10, 1 );
  treeInsert(pt,  30, 2 );
  treeInsert(pt,  5 , 3 );
  treeInsert(pt,  15, 4 );
  treeInsert(pt,  25, 5 );
  treeInsert(pt,  35, 6 );
  treeInsert(pt,  13, 9 );
  treeInsert(pt,  18, 10);
  treeInsert(pt,  33, 13);
  treeInsert(pt,  50, 14);
  treeInsert(pt,  12, 19);
  treeInsert(pt,  14, 20);
  treeInsert(pt,  19, 22);
  treeInsert(pt,  31, 27);

  PUTDLN(findMax(pt, 0));
  PUTDLN(findMin(pt, 0));

  int pos;
  PUTDLN(pos = treeSearch(pt, 5));
  PUTDLN(pos = treeSearch(pt, 19));
  PUTDLN(pos = treeSearch(pt, 33));
  PUTDLN(pos = treeSearch(pt, 20));

  pos = findPre(pt, pos);
  PUTDLN(pt->tree[pos]);

  PUTDLN(pos = treeSearch(pt, 5));
  pos = findPre(pt, pos);
  if (pos == -1) {
    puts("cannot find.");
  } else {
    PUTDLN(pt->tree[pos]);
  }

  PUTDLN(pos = treeSearch(pt, 33));
  pos = findPost(pt, pos);
  PUTDLN(pt->tree[pos]);

  PUTDLN(pos = treeSearch(pt, 50));
  pos = findPost(pt, pos);
  if (pos == -1) {
    puts("cannot find.");
  } else {
    PUTDLN(pt->tree[pos]);
  }
  

  walkNonRecur(pt);

  TREE_FREE(pt);
}
