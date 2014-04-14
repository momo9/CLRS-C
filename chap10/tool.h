#ifndef TOOL_H
#define TOOL_H
#define PUTD(x)         printf("%d ", (x))
#define PUTDLN(x)       printf(#x": %d\n", (x))
#define ALLOC_ONE(t)    (t *)malloc(sizeof(t))

void swap(int *a, int *b);

#endif
