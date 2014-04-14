#include <stdio.h>
#include "tool.h"

#define SIZE    8
#define N       6

void trav(int beg, int post[]);
void compactify(int pre[], int post[], int isFree[], int *pList, int *pFree);

main() {
  int post[SIZE];
  int pre[SIZE];
  int isFree[SIZE];
  int list;
  int free;
  list = 7;
  post[7] = 0; pre[7] = -1; isFree[7] = 0; 
  post[0] = 3; pre[0] = 7;  isFree[0] = 0;
  post[3] = 6; pre[3] = 7;  isFree[3] = 0;
  post[6] = 2; pre[6] = 3;  isFree[6] = 0;
  post[2] = 5; pre[2] = 6;  isFree[2] = 0;
  post[5] = -1; pre[5] = 2; isFree[5] = 0;
  free = 4;
  post[4] = 1; pre[4] = -1; isFree[4] = 1;
  post[1] = -1; pre[1] = 4; isFree[1] = 1;

  trav(free, post);
  trav(list, post);

  compactify(pre, post, isFree, &list, &free);
  trav(free, post);
  trav(list, post);
}

void trav(int beg, int post[]) {
  int i;
  for (i = beg; i != -1; i = post[i]) PUTD(i);
  puts("");
}

void compactify(int pre[], int post[], int isFree[], int *pList, int *pFree) {
  int af = 0;
  int al = *pList;

  while (1) {
    PUTDLN(al);
    PUTDLN(af);
    getchar();

    while (al < N) al = post[al];
    while (! isFree[af]) ++af;
    
    PUTDLN(al);
    PUTDLN(af);
    getchar();

    if (af == N) break;
    
    if (pre[al] == -1) *pList = af;
    else post[pre[al]] = af;
    if (pre[af] == -1) *pFree = al;
    else post[pre[af]] = al;
    
    if (post[al] != -1) pre[post[al]] = af;
    if (post[af] != -1) pre[post[af]] = al;

    swap(&pre[af], &pre[al]);
    swap(&post[af], &post[al]);
    swap(&isFree[af], &isFree[al]);

    al = af;
  }
}

