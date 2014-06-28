#include "treenode.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  TreeNode *proot = NULL, *p;
  int pool[] = {
    20,
    10,
    30,
    5,
    15,
    13,
    18,
    12,
    14,
    19,
    25,
    35,
    33,
    50,
    31
  };
  int i;
  const int size = sizeof(pool) / sizeof(int);
  for (i = 0; i < size; ++i) {
    proot = addnode(proot, &pool[i]);
  }

  puttree(proot);
  printf("\n");


  for (i = 0; i < size; ++i) {
    printf("%d: delete %d\n==============\n", i, pool[i]);
    p = search(proot, &pool[i]);
    proot = delnode(proot, p);

    puttree(proot);
    printf("\n");
  }

  freenode(proot);

  exit(EXIT_SUCCESS);
}
