#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "tool.h"
#include "node.h"
#include "list.h"

main() {

  List *pl = listFactory();

  int j;
  for (j = 0; j < 3; j ++) {
    uint32_t i;
    for (i = 0; i < INT16_MAX*100; ++i) {
      listInsert(LIST_NIL(pl), 1);
    }


    puts("freed");
    getchar();
  }

  listFree(pl);

  puts("accomplished");
}

