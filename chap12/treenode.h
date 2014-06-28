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
TreeNode *delnode(TreeNode *proot, TreeNode *p);

// recursion version
void puttree(TreeNode *proot);

// not recursive, using stack
void puttree_stack(TreeNode *proot);

// not recursion, not using stack
void puttree_nostack(TreeNode *proot);

TreeNode *freenode(TreeNode *proot);

void treemin(TreeNode *p, KeyType *k);
void treemax(TreeNode *p, KeyType *k);

TreeNode *nodemin(TreeNode *p);
TreeNode *nodemax(TreeNode *p);

void putnode(TreeNode *n);

TreeNode *search(TreeNode *pt, KeyType *p);

TreeNode *predecessor(TreeNode *pn);
TreeNode *successor(TreeNode *pn);

#endif
