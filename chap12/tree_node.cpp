#include "tree_node.h"
#include <cstdio>

TreeNode::TreeNode(TypeVal val)
  :val(val)
{
  this->pPar.reset();
  this->pLeft.reset();
  this->pRight.reset();
}

TreeNode::TreeNode(TypeVal val, const Pshr &pPar, const Pshr &pLeft, const Pshr &pRight) 
  :val(val)
  ,pPar(pPar)
  ,pLeft(pLeft)
  ,pRight(pRight)
{
}

TreeNode::~TreeNode() {
}
