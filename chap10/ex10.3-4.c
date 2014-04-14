#include <stdio.h>
#include "tool.h"

#define SIZE            16

int alloc(int *pFree, int post[]);
void myfree(int x, int *pFree, int post[]);
void printFree(int free, int post[]);

main() {
  int post[SIZE];
  int i;
  // use ordered post to make allocation compact
  for (i = 0; i < SIZE; ++i) post[i] = i + 1;
  post[i] = -1;
  int free = 0;
  printFree(free, post);
  PUTDLN(alloc(&free, post));
  PUTDLN(alloc(&free, post));
  PUTDLN(alloc(&free, post));
  PUTDLN(alloc(&free, post));
  PUTDLN(alloc(&free, post));
  printFree(free, post);
  
  myfree(0, &free, post);
  myfree(2, &free, post);

  printFree(free, post);
}

int alloc(int *pFree, int post[]) {
  int x = *pFree;
  *pFree = post[x];
  return x;
}

void myfree(int x, int *pFree, int post[]) {
  post[x] = *pFree;
  *pFree = x;
}

void printFree(int free, int post[]) {
  int i;
  for (i = free; post[i] != -1; i = post[i]) PUTD(i);
  puts("");
}
