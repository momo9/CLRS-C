#include "link_tree.h"
#include "tool.h"
#include "stack.h"
#include <stdlib.h>
#include <stdio.h>

// should be freed by nodeFree()
TreeNode *nodeFactory(TreeNode *pPar, TreeNode *pLeft, TreeNode *pRight, NodeValType val) {
  TreeNode *pn = ALLOC_ONE(TreeNode);
  pn->pPar = pPar;
  pn->pLeft = pLeft;
  pn->pRight = pRight;
  pn->val = val;
  return pn;
}
void nodeFree(TreeNode *pn) {
  if (pn->pLeft) nodeFree(pn->pLeft);
  if (pn->pRight) nodeFree(pn->pRight);
  printf("%d is freed.\n", pn->val);
  free(pn);
  pn = NULL;
}

// should be freed by treeFree()
LinkTree *treeFactory(NodeValType valRoot) {
  LinkTree *pt = ALLOC_ONE(LinkTree);
  pt->pRoot = nodeFactory(NULL, NULL, NULL, valRoot);
  return pt;
}
void treeFree(LinkTree *pt) {
  nodeFree(pt->pRoot);
  free(pt);
  pt = NULL;
}

void nodePrint(TreeNode *pn) {
  PUTD(pn->val);
  if (pn->pLeft) nodePrint(pn->pLeft);
  if (pn->pRight) nodePrint(pn->pRight);
}

void treePrintNonRecur(LinkTree *pt) {
  Stack *ps = stackFactory();
  STACK_PUSH(ps, pt->pRoot);
  while (! STACK_IS_EMPTY(ps)) {
    TreeNode *pn = STACK_POP(ps);
    PUTD(pn->val);
    if (pn->pLeft) STACK_PUSH(ps, pn->pLeft);
    if (pn->pRight) STACK_PUSH(ps, pn->pRight);
  }
  STACK_FREE(ps);
  puts("");
}
