#include "stack.h"


static StackType stack[STACKSIZ];
static top = 0;

StackType pop() {
  return stack[--top];
}

void push(StackType v) {
  stack[top++] = v;
}

int stackempty() {
  if (top == 0) {
    return 1;
  }
  return 0;
}
