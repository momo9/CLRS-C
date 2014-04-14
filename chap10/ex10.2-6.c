#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "tool.h"
#include "node.h"
#include "list.h"

main() {

  List *pl1 = listFactory();
  List *pl2 = listFactory();
  LIST_PUSH_BACK(pl1, 1);
  LIST_PUSH_BACK(pl1, 2);
  LIST_PUSH_BACK(pl1, 3);

  LIST_PUSH_BACK(pl2, 4);
  LIST_PUSH_BACK(pl2, 5);
  LIST_PUSH_BACK(pl2, 6);

  listTrav(pl1);
  listTrav(pl2);

  listUnion(pl1, pl2);
  listTrav(pl1);
  listTrav(pl2);

  listFree(pl1);
  listFree(pl2);

}

