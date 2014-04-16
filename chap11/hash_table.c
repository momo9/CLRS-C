#include "hash_table.h"
#include <stdio.h>

HashTable *hashFactory() {
  HashTable *pht = ALLOC_ONE(HashTable);
  int i;
  for (i = 0; i < HASH_SIZE; ++ i) pht->table[i] = listFactory();
  return pht;
}

void hashFree(HashTable **ppht) {
  HashTable *pht = *ppht;
  int i;
  for (i = 0; i < HASH_SIZE; ++i) listFree(&pht->table[i]);
  free(pht);
  *ppht = NULL;
}

Node *hashSearch(HashTable *pht, NodeValType val) {
  int hash = HASH(val);
  return listSearch(pht->table[hash], val);
}
void hashDelete(Node *pn) {
  listDelete(pn);
}
void hashInsert(HashTable *pht, NodeValType val) {
  listInsert(LIST_FRONT(pht->table[HASH(val)]), val);
}

void hashPrint(HashTable *pht) {
  int i;
  for (i = 0; i < HASH_SIZE; ++i) {
    printf("%d: ", i);
    listTrav(pht->table[i]);
  }
}
