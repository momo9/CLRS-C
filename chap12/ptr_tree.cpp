#include "ptr_tree.h"
#include <iostream>
#include <cstdio>

PtrTree::PtrTree(TreeNode::TypeVal val)
  :pRoot(new TreeNode(val))
{
}

PtrTree::~PtrTree() {
}

void PtrTree::walkMidOrder() const {
  walkMidOrderReal(pRoot);
  puts("");
}

void PtrTree::walkMidOrderReal(const TreeNode::Pshr &pRoot) const {
  using namespace std;
  if (pRoot) {
    walkMidOrderReal(pRoot->pLeft);
    cout<<pRoot->getVal()<<" ";
    walkMidOrderReal(pRoot->pRight);
  }
}

TreeNode::Pshr PtrTree::search(TreeNode::TypeVal val) const {
  return searchReal(val, this->pRoot);
}

TreeNode::Pshr PtrTree::searchReal(TreeNode::TypeVal val, const TreeNode::Pshr &pRoot) const {
  if (!pRoot || val == pRoot->getVal()) return pRoot;
  else if (val < pRoot->getVal()) return searchReal(val, pRoot->pLeft);
  else return searchReal(val, pRoot->pRight);
}

void PtrTree::insertReal(TreeNode::TypeVal val, TreeNode::Pshr &pRoot) {
  if (val == pRoot->getVal()) puts("Cannot insert.");
  else if (val < pRoot->getVal()) {
    if (pRoot->pLeft) {
      insertReal(val, pRoot->pLeft);
    } else {
      TreeNode::Pshr pTemp(new TreeNode(val));
      pRoot->pLeft = pTemp;
      pTemp->pPar = pRoot;
    }
  } else {
    if (pRoot->pRight) {
      insertReal(val, pRoot->pRight);
    } else {
      TreeNode::Pshr pTemp(new TreeNode(val));
      pRoot->pRight = pTemp;
      pTemp->pPar = pRoot;
    }
  }
}

void PtrTree::insert(TreeNode::TypeVal val) {
  insertReal(val, this->pRoot);
}

void PtrTree::remove(TreeNode::Pshr &pn) {
  if (!pn->pLeft) {
    TreeNode::Pshr pPar(pn->pPar);
    TreeNode::Pshr pSon(pn->pRight);
    if (pPar->pLeft == pn) pPar->pLeft = pSon;
    else pPar->pRight = pSon;
  }
}
TreeNode::Pshr PtrTree::findMin(const TreeNode::Pshr &pRoot) const {
  TreeNode::Pshr pn;
  for (pn = pRoot; pn->pLeft; pn = pn->pLeft);
  return pn;
}
TreeNode::Pshr PtrTree::findMax(const TreeNode::Pshr &pRoot) const {
  TreeNode::Pshr pn;
  for (pn = pRoot; pn->pRight; pn = pn->pRight);
  return pn;
}
