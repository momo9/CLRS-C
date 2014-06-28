#include "treenode.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  TreeNode *proot = NULL, *p;
  int pool[] = {
    1,
    5,
    10,
    256,
    20,
    -21,
    130,
    35,
    40
  };
  int i;
  const int size = sizeof(pool) / sizeof(int);
  for (i = 0; i < size; ++i) {
    proot = addnode(proot, &pool[i]);
  }

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

  for (i = 0; i < size; ++i) {
    p = search(proot, &pool[i]);
    printf("%d -> ", *p->ptrkey);
    if (NULL != (p = predecessor(p))) {
      printf("%d\n", *p->ptrkey);
    } else {
      printf("\n");
    }
  }

  printf("=======================\n");

  for (i = 0; i < size; ++i) {
    p = search(proot, &pool[i]);
    printf("%d <- ", *p->ptrkey);
    if (NULL != (p = successor(p))) {
      printf("%d\n", *p->ptrkey);
    } else {
      printf("\n");
    }
  }


  freenode(proot);

  exit(EXIT_SUCCESS);
}
