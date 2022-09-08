#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

int hash_merge(node_t** t1, node_t** t2, node_t** aux)
{
    int j = 0;
    for (int i = 0; i < M; i++)
        if ((t1[i] != NULL) && (t1[i]->removed == 0))
        {
            aux[j] = t1[i];
            j++;
        }

    for (int i = 0; i < M; i++)
        if ((t2[i] != NULL) && (t2[i]->removed == 0))
        {
            aux[j] = t2[i];
            j++;
        }
    return j-1;
}

int sort(node_t** vet, int a, int b)
{
	if (a >= b)
	    return 0;
	sort(vet, a, b-1);
	insert(vet, a, b);
	return 0;
}

void insert(node_t** vet, int a, int b)
{
	int p = search(vet[b]->value, vet, a, b-1);
	int i = b;
	while (i > p+1)
    {
		shift(vet, i, i-1);
		i = i-1;
	}
}

int search(int x, node_t** vet, int a, int b)
{
	if (a > b)
		return -1;
	if (vet[b]->value <= x)
		return b;
	return search(x, vet, a, b-1);
}

void shift(node_t** vet, int a, int b)
{
    node_t* aux;
    aux = vet[a];
    vet[a] = vet[b];
    vet[b] = aux;
}