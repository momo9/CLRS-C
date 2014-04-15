#include "stack.h"
#include <stdio.h>

// should be freed by STACK_FREE()
Stack *stackFactory() {
  Stack *ps = ALLOC_ONE(Stack);
  ps->top = 0;
  return ps;
}

void stackPrint(Stack *ps) {
  int i;
  for (i = 0; i < ps->top; ++i) PUTD(ps->container[i]);
  puts("");
}
