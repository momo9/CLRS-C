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

  walkNonRecur(pt);

  TREE_FREE(pt);
}
