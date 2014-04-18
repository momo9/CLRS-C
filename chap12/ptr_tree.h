#ifndef PTR_TREE_H
#define PTR_TREE_H

#include "tree_node.h"

class PtrTree {
private:
  TreeNode::Pshr pRoot;

  void walkMidOrderReal(const TreeNode::Pshr &pRoot) const;
  TreeNode::Pshr searchReal(TreeNode::TypeVal val, const TreeNode::Pshr &pRoot) const;
  void insertReal(TreeNode::TypeVal val, TreeNode::Pshr &pRoot);
  TreeNode::Pshr findMin(const TreeNode::Pshr &pRoot) const;
  TreeNode::Pshr findMax(const TreeNode::Pshr &pRoot) const;
public:
  PtrTree(TreeNode::TypeVal val);
  ~PtrTree();
  void walkMidOrder() const;
  void insert(TreeNode::TypeVal val);
  TreeNode::Pshr search(TreeNode::TypeVal val) const;
  void remove(TreeNode::Pshr &pn);
  TreeNode::Pshr min() const {
    return findMin(this->pRoot);
  }
  TreeNode::Pshr max() const {
    return findMax(this->pRoot);
  }
};

#endif
