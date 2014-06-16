#ifndef STACK_H
#define STACK_H

#define STACKSIZ 64

#include "treenode.h"

typedef TreeNode *StackType;

StackType pop();

void push(StackType v);

int stackempty();

#endif
