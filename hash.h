#ifndef __HASH__
#define __HASH__

#define M 11

typedef struct node
{
    int value;
    int removed;
} node_t;

int h1(int key);

int h2(int key);

node_t** init_hash();

node_t* init_node();

int find(node_t** t, int value);

void insert(node_t** t1, node_t** t2, int value);

void remove_value(node_t** t1, node_t** t2, int value);

void delete_hash(node_t** t);

void print(node_t** t1, node_t** t2);

#endif