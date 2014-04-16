#include <stdio.h>
#include "open_hash.h"
#include "tool.h"

// should be freed by HASH_FREE()
OpenHash *openHashFactory() {
  OpenHash *poh = ALLOC_ONE(OpenHash);
  int i;
  for (i = 0; i < OPEN_HASH_SIZE; ++i) {
    poh->deleted[i] = 1;
  }
  return poh;
}

void openHashInsert(OpenHash *poh, int key) {
  int pos;
  for (pos = HASH(key); !poh->deleted[pos]; pos = (pos + 1) % OPEN_HASH_SIZE);
  poh->deleted[pos] = 0;
  poh->table[pos] = key;
}
void openHashDelete(OpenHash *poh, int pos) {
  poh->deleted[pos] = 1;
}
int openHashSearch(OpenHash *poh, int key) {
  int pos;
  for (pos = HASH(key); !poh->deleted[pos]; pos = (pos + 1) % OPEN_HASH_SIZE) {
    if (poh->table[pos] == key && !poh->deleted[pos]) {
      return pos;
    }
  }
  return -1; // not found
}

void openHashPrint(OpenHash *poh) {
  int i;
  puts("table: ");
  for (i = 0; i < OPEN_HASH_SIZE; ++i) {
    PUTD(poh->table[i]);
  }
  puts("");
  puts("deleted: ");
  for (i = 0; i < OPEN_HASH_SIZE; ++i) {
    PUTD(poh->deleted[i]);
  }
  puts("");
}
