#ifndef TREE_NODE_H
#define TREE_NODE_H

#include <tr1/memory>

class TreeNode {
public:
  typedef std::tr1::shared_ptr<TreeNode> Pshr;
  typedef int TypeVal;
  TreeNode(TypeVal val);
  TreeNode(TypeVal val, const Pshr &pPar, const Pshr &pLeft, const Pshr &pRight);
  TypeVal getVal() const {
    return this->val;
  }
  ~TreeNode();
  
  Pshr pPar;
  Pshr pLeft;
  Pshr pRight;
private:
  TypeVal val;
};

#endif
