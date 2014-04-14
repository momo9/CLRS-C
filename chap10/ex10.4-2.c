#include "link_tree.h"
#include <stdio.h>

main() {
  LinkTree *pt = treeFactory(0);
  TreeNode *pn1 = nodeFactory(pt->pRoot, NULL, NULL, 1);
  pt->pRoot->pLeft = pn1;
  TreeNode *pn2 = nodeFactory(pt->pRoot, NULL, NULL, 2);
  pt->pRoot->pRight = pn2;
  TreeNode *pn3 = nodeFactory(pn1, NULL, NULL, 3);
  pn1->pLeft = pn3;
  TreeNode *pn4 = nodeFactory(pn1, NULL, NULL, 4);
  pn1->pRight = pn4;
  TreeNode *pn5 = nodeFactory(pn2, NULL, NULL, 5);
  pn2->pRight = pn5;

  TREE_PRINT(pt);
  treeFree(pt);
}
