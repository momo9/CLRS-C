#include "tool.h"
#include <stdio.h>
#include <stdint.h>

#define SIZE    16

#define SEARCH(bv, key)         ((bv[key]) ? key : -1)
#define INSERT(bv, key)         bv[key] = 1 
#define DELETE(bv, key)         bv[key] = 0

void trav(uint8_t bv[]);

main() {
  uint8_t bitVec[SIZE];

  int i;
  for (i = 0; i < SIZE; ++i) {
    bitVec[i] = 0;
  }

  INSERT(bitVec, 5);
  INSERT(bitVec, 7);

  trav(bitVec);

  PUTDLN(SEARCH(bitVec, 3));
  PUTDLN(SEARCH(bitVec, 5));

  DELETE(bitVec, 5);
  trav(bitVec);

}

void trav(uint8_t bv[]) {
  int i;
  for (i = 0; i < SIZE; ++i) {
    if (bv[i]) PUTD(i);
  }
  puts("");
}
