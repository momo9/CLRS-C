#ifndef TREENODE_H
#define TREENODE_H

typedef int KeyType;

typedef struct TreeNode {
  struct TreeNode *par;
  struct TreeNode *left;
  struct TreeNode *right;
  KeyType *ptrkey;
} TreeNode;

TreeNode *addnode(TreeNode *proot, KeyType *ptrkey);

// recursion version
void puttree(TreeNode *proot);

// not recursive, using stack
void puttree_stack(TreeNode *proot);

// not recursion, not using stack
void puttree_nostack(TreeNode *proot);

TreeNode *freenode(TreeNode *proot);

#endif
