#ifndef __HASH__
#define __HASH__

#define M 11

typedef struct node
{
    int value;
    int removed;
    int index;
    char* table;
} node_t;

int h1(int key);

int h2(int key);

node_t** hash_init(int size);

node_t* node_init();

int hash_search(node_t** t, int value);

void hash_insert(node_t** t1, node_t** t2, int value);

void hash_remove(node_t** t1, node_t** t2, int value);

void hash_delete(node_t** t);

void hash_print(node_t** aux);

int hash_merge(node_t** t1, node_t** t2, node_t** aux);

#endif