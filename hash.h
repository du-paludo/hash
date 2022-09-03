#ifndef __HASH__
#define __HASH__

#define M 11
#define A 22

typedef struct node
{
    int value;
    int removed;
    int index;
    char* table;
} node_t;

int h1(int key);

int h2(int key);

node_t** init_hash();

node_t** init_aux();

node_t* init_node();

int find(node_t** t, int value);

void insert(node_t** t1, node_t** t2, int value);

void remove_value(node_t** t1, node_t** t2, int value);

void delete_hash(node_t** t);

void delete_aux(node_t** aux);

void print(node_t** aux);

void shift(node_t** vet, int a, int b);

int search(int x, node_t** vet, int a, int b);

void insere(node_t** vet, int a, int b);

int insertionSort(node_t** vet, int a, int b);

void sort(node_t** t1, node_t** t2, node_t** aux);

#endif