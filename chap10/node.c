#include "tool.h"
#include "node.h"
#include <stdlib.h>

Node *nodeFactory(int argc, ...) {
  va_list vl;
  va_start(vl, argc);
  Node *pNew = ALLOC_ONE(Node);
  // Node *nodeFactory(0)
  if (argc == 0) {
    pNew->pPre = pNew;
    pNew->val = 0;
    pNew->pPost = pNew;
  // Node *nodeFactory(3, Node *pre, int val, Node *post)
  } else if (argc == 3) {
    pNew->pPre = va_arg(vl, Node *);
    pNew->val = va_arg(vl, int);
    pNew->pPost = va_arg(vl, Node *);
  }
  va_end(vl);
  return pNew;
}
