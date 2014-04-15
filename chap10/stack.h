#ifndef STACK_H
#define STACK_H
#include "link_tree.h"
#include "tool.h"

#define STACK_SIZE              64
#define STACK_FREE(ps)          free(ps); ps = NULL
#define STACK_PUSH(ps, val)     (ps)->container[(ps)->top++] = (val)
#define STACK_POP(ps)           ((ps)->container[--(ps)->top])
#define STACK_IS_EMPTY(ps)      (!(ps)->top)

typedef TreeNode *StackValType;
//typedef int StackValType;
typedef struct Stack {
  StackValType container[STACK_SIZE];
  int top;
} Stack;

// should be freed by STACK_FREE()
Stack *stackFactory();

void stackPrint(Stack *ps);

#endif
