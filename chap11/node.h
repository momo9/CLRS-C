#ifndef NODE_H
#define NODE_H
#include <stdarg.h>

#define NODE_FREE(np)           free(np); (np) = NULL

typedef int NodeValType;

typedef struct Node {
  struct Node *pPre;
  NodeValType val;
  struct Node *pPost;
} Node;

// (Node *) produced by nodeFactory should be freed by NODE_FREE
// Node *nodeFactory(0): Produce a nil node.
// Node *nodeFactory(3, Node *pre, int val, Node *post)
Node *nodeFactory (int argc, ...);

#endif
