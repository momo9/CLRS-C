#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include "list.h"
#include "tool.h"

#define HASH_SIZE       8
#define HASH(x)         ((x) % 8)

typedef struct HashTable {
  List *table[HASH_SIZE];
} HashTable;

// should be freed by hashFree()
HashTable *hashFactory();
void hashFree(HashTable **ppht);

Node *hashSearch(HashTable *pht, NodeValType val);
void hashDelete(Node *pn);
void hashInsert(HashTable *pht, NodeValType val);

void hashPrint(HashTable *pht);

#endif
