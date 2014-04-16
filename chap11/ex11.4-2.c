#include <stdio.h>
#include "tool.h"
#include "open_hash.h"

main() {
  OpenHash *poh = openHashFactory();

  openHashPrint(poh);

  openHashInsert(poh, 13);
  openHashInsert(poh, 29);
  openHashInsert(poh, 14);
  openHashInsert(poh, 30);
  openHashInsert(poh, 1);
  openHashPrint(poh);

  int pos;
  PUTDLN(pos = openHashSearch(poh, 30));
  openHashDelete(poh, pos);
  PUTDLN(pos = openHashSearch(poh, 30));
  openHashInsert(poh, 16);
  PUTDLN(pos = openHashSearch(poh, 16));
  PUTDLN(pos = openHashSearch(poh, 13));
  PUTDLN(pos = openHashSearch(poh, 14));
  PUTDLN(pos = openHashSearch(poh, 6));

  OPEN_HASH_FREE(poh);
}
