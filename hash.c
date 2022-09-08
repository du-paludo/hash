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

int hash_search(node_t** t, int value)
{
    int key = h1(value);
    if (t[key]->removed)
        return -1;
    else if (t[key]->value == value)
        return key;
    else
        return h2(value);
}

node_t** hash_init(int size)
{
    node_t** t = malloc(sizeof(node_t*) * size);
    for (int i = 0; i < M; i++)
        t[i] = NULL;
    return t;
}

node_t* node_init(int value, int index, char* table)
{
    node_t* aux = malloc(sizeof(node_t));
    aux->removed = 0;
    aux->value = value;
    aux->table = table;
    aux->index = index;
    return aux;
}

void hash_insert(node_t** t1, node_t** t2, int value)
{
    int index = h1(value);
    if (t1[index] == NULL)
        t1[index] = node_init(value, index, "T1");
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
            t2[index2] = node_init(t1[index]->value, index2, "T2");
        else if (t2[index2]->removed)
        {
            t2[index2]->value = t1[index]->value;
            t2[index2]->removed = 0;
            t2[index2]->index = index2;
        }
        t1[index]->value = value;
    }
}

void hash_remove(node_t** t1, node_t** t2, int value)
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

void hash_delete(node_t** t)
{
    for (int i = 0; i < M; i++)
        if (t[i] != NULL)
            free(t[i]);
    free(t);
}

void hash_print(node_t** aux)
{
    for (int i = 0; i < M*2; i++)
        if (aux[i] != NULL)
            printf("%d,%s,%d\n", aux[i]->value, aux[i]->table, aux[i]->index);
}