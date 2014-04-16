#ifndef OPEN_HASH_H
#define OPEN_HASH_H

#define OPEN_HASH_SIZE          16
#define HASH(x)                 ((x) % OPEN_HASH_SIZE)
#define OPEN_HASH_FREE(poh)     free(poh); poh = NULL

typedef struct OpenHash {
  int table[OPEN_HASH_SIZE];
  char deleted[OPEN_HASH_SIZE];
} OpenHash;

// should be freed by HASH_FREE()
OpenHash *openHashFactory();

void openHashInsert(OpenHash *poh, int key);
void openHashDelete(OpenHash *poh, int pos);
int openHashSearch(OpenHash *poh, int key);

void openHashPrint(OpenHash *poh);
#endif
