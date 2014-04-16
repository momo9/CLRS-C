#include <stdio.h>
#include "hash_table.h"
#include "node.h"
#include "tool.h"

main() {
  HashTable *pht = hashFactory();
  hashInsert(pht, 10);
  hashInsert(pht, 7);
  hashInsert(pht, 18);
  hashInsert(pht, 37);
  hashPrint(pht);

  Node *pn;
  pn = hashSearch(pht, 18);
  if (pn) {
    PUTDLN(pn->val);
    hashDelete(pn);
  }  

  pn = hashSearch(pht, 18);
  if (pn) {
    PUTDLN(pn->val);
    hashDelete(pn);
  }  

  pn = hashSearch(pht, 7);
  if (pn) {
    PUTDLN(pn->val);
    hashDelete(pn);
  }  

  hashPrint(pht);

  hashFree(&pht);
}
