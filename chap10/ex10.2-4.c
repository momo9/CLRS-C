#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "tool.h"
#include "node.h"
#include "list.h"

main() {
  List *pl = listFactory();
  Node *pn;
  listInsert(LIST_FRONT(pl), 5);
  listTrav(pl);
  listInsert(LIST_FRONT(pl), 4);
  listTrav(pl);
  listInsert(LIST_FRONT(pl), 3);
  listTrav(pl);
  listInsert(LIST_NIL(pl), 6);
  listTrav(pl);
  listInsert(LIST_NIL(pl), 7);
  listTrav(pl);

  pn = listSearch(pl, 5);
  listDelete(pn);
  listTrav(pl);
  pn = listSearch(pl, 7);
  listDelete(pn);
  listTrav(pl);

  pn = listSearch(pl, 10);

  uint32_t i;
  for (i = 0; i < INT16_MAX*500; ++i) {
    listInsert(LIST_NIL(pl), 1);
  }

  puts("OK");
  getchar();

  listFree(pl);
}

