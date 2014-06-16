#include "treenode.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  TreeNode *proot = NULL;
  int i;
  i = 1;
  proot = addnode(proot, &i);
  i = 5;
  proot = addnode(proot, &i);
  i = 10;
  proot = addnode(proot, &i);
  i = 14;
  proot = addnode(proot, &i);
  i = 20;
  proot = addnode(proot, &i);
  i = 21;
  proot = addnode(proot, &i);
  i = 130;
  proot = addnode(proot, &i);
  i = 35;
  proot = addnode(proot, &i);
  i = 40;
  proot = addnode(proot, &i);

  puttree(proot);
  printf("\n");
  puttree_stack(proot);
  printf("\n");
  puttree_nostack(proot);
  printf("\n");

  freenode(proot);

  exit(EXIT_SUCCESS);
}
