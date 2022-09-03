#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "hash.h"

int h1(int value)
{
    return value % M; 
}

int h2(int value)
{
    return floor(M * ((value * 0.9) - floor(value * 0.9)));
}

int find(node_t** t, int value)
{
    int key = h1(value);
    if (t[key]->removed)
        return -1;
    else if (t[key]->value == value)
        return key;
    else
        return h2(value);
}

node_t** init_hash()
{
    node_t** t = malloc(sizeof(node_t*) * M);
    for (int i = 0; i < M; i++)
        t[i] = NULL;
    return t;
}

node_t** init_aux()
{
    node_t** t = malloc(sizeof(node_t*) * A);
    for (int i = 0; i < A; i++)
        t[i] = NULL;
    return t;
}

node_t* init_node(int value, int index, char* table)
{
    node_t* aux = malloc(sizeof(node_t));
    aux->removed = 0;
    aux->value = value;
    aux->table = table;
    aux->index = index;
    return aux;
}

void insert(node_t** t1, node_t** t2, int value)
{
    int index = h1(value);
    if (t1[index] == NULL)
        t1[index] = init_node(value, index, "T1");
    else if (t1[index]->removed)
    {
        t1[index]->value = value;
        t1[index]->removed = 0;
        t1[index]->index = index;
    }
    else
    {
        int index2 = h2(t1[index]->value);
        if (t2[index2] == NULL)
            t2[index2] = init_node(t1[index]->value, index2, "T2");
        else if (t2[index2]->removed)
        {
            t2[index2]->value = t1[index]->value;
            t2[index2]->removed = 0;
            t2[index2]->index = index2;
        }
        t1[index]->value = value;
    }
}

void remove_value(node_t** t1, node_t** t2, int value)
{
    int index1 = h1(value);
    int index2 = h2(value);
    if (t2[index2] != NULL && t2[index2]->value == value)
    {
        t2[index2]->removed = 1;
        free(t2[index2]);
        t2[index2] = NULL;
    }
    else if (t1[index1] != NULL && t1[index1]->value == value)
        t1[index1]->removed = 1;
}

void delete_hash(node_t** t)
{
    for (int i = 0; i < M; i++)
        if (t[i] != NULL)
            free(t[i]);
    free(t);
}

void delete_aux(node_t** aux)
{
    free(aux);
}

void print(node_t** aux)
{
    for (int i = 0; i < A; i++)
        if (aux[i] != NULL)
            printf("%d,%s,%d\n", aux[i]->value, aux[i]->table, aux[i]->index);
}

void shift(node_t** vet, int a, int b)
{
    node_t* aux;
    aux = vet[a];
    vet[a] = vet[b];
    vet[b] = aux;

}

int search(int x, node_t** vet, int a, int b)
{
	if(a > b)
		return -1;
	if(vet[b]->value <= x)
		return b;
	return search(x, vet, a, b-1);
}

void insere(node_t** vet, int a, int b)
{
	int p; int i;
	p = search(vet[b]->value, vet, a, b-1);
	i = b;
	while (i > p+1)
    {
		shift(vet, i, i-1);
		i = i-1;
	}
	return;

}

int insertionSort(node_t** vet, int a, int b)
{

	if(a >= b)
		return 0;
	insertionSort(vet,a,b-1);
	insere(vet, a, b);
	return 0;

}

void sort(node_t** t1, node_t** t2, node_t** aux)
{
    int j = 0;
    for (int i = 0; i < M; i++)
    {
        if ((t1[i] != NULL) && (t1[i]->removed == 0))
        {
            aux[j] = t1[i];
            j++;
        }
    }

    for (int i = 0; i < M; i++)
    {
        if ((t2[i] != NULL) && (t2[i]->removed == 0))
        {
            aux[j] = t2[i];
            j++;
        }
    }

    insertionSort(aux, 0, j-1);

}


