#ifndef LINK_TREE_H
#define LINK_TREE_H

#define TREE_PRINT(pt)  nodePrint((pt)->pRoot); puts("")

typedef int NodeValType;

typedef struct TreeNode {
  struct TreeNode *pPar;
  struct TreeNode *pLeft;
  struct TreeNode *pRight;
  NodeValType val;
} TreeNode;

typedef struct LinkTree {
  TreeNode *pRoot;
} LinkTree;

// should be freed by nodeFree()
TreeNode *nodeFactory(TreeNode *pPar, TreeNode *pLeft, TreeNode *pRight, NodeValType val); 
void nodeFree(TreeNode *pn);

// should be freed by treeFree()
LinkTree *treeFactory(NodeValType valRoot);
void treeFree(LinkTree *pt);

void nodePrint(TreeNode *pn);
#endif
