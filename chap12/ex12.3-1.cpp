#include <tr1/memory>
#include <iostream>
#include "ptr_tree.h"

int main(int argc, char *argv[]) {

  using namespace std;

  PtrTree t(10);
  t.insert(5);
  t.insert(15);
  t.insert(3);
  t.insert(8);
  t.insert(17);
  t.insert(13);

  t.walkMidOrder();

  cout<<(t.search(3) ? "o\n" : "x\n");
  cout<<(t.search(15) ? "o\n" : "x\n");
  cout<<(t.search(7) ? "o\n" : "x\n");
  cout<<(t.search(911) ? "o\n" : "x\n");

  TreeNode::Pshr pn;
  pn = t.min();
  cout<<pn->getVal()<<"\n";
  pn = t.max();
  cout<<pn->getVal()<<"\n";
  TreeNode::Pshr pn1(pn);
  cout<<(pn == pn1)<<"\n";

  return 0;
}
