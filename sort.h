#ifndef __SORT__
#define __SORT__

#include "hash.h"

int sort(node_t** vet, int a, int b);

void insert(node_t** vet, int a, int b);

int search(int x, node_t** vet, int a, int b);

void shift(node_t** vet, int a, int b);

#endif