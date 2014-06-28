#include "treenode.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  TreeNode *proot = NULL, *p;
  int i;
  i = 1;
  proot = addnode(proot, &i);
  i = 5;
  proot = addnode(proot, &i);
  i = 10;
  proot = addnode(proot, &i);
  i = 256;
  proot = addnode(proot, &i);
  i = 20;
  proot = addnode(proot, &i);
  i = -21;
  proot = addnode(proot, &i);
  i = 130;
  proot = addnode(proot, &i);
  i = 35;
  proot = addnode(proot, &i);
  i = 40;
  proot = addnode(proot, &i);

  puttree(proot);
  printf("\n");

  p = nodemin(proot);
  putnode(p);
  treemin(proot, &i);
  printf("min: %d\n", i);

  p = nodemax(proot);
  putnode(p);
  treemax(proot, &i);
  printf("max: %d\n", i);

  freenode(proot);

  exit(EXIT_SUCCESS);
}
