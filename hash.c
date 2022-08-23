#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "hash.h"

int h1(int value) {
    return value % M; 
}

int h2(int value) {
    return floor(M * ((value * 0.9) - floor(value * 0.9)));
}

int find(node_t** t, int value) {
    int key = h1(value);
    if (t[key]->removed)
        return -1;
    else if (t[key]->value == value)
        return key;
    else
        return h2(value);

    /* node_t *nodoAux = list;
    while(nodoAux != NULL && nodoAux->key != key) {
        nodoAux = nodoAux->next;
    }
    if(nodoAux == NULL) {
        return -1;
    } else {
        return 0;
    } */
}

node_t** init_hash()
{
    // node_t* t = malloc(sizeof(node_t) * M);
    node_t** t = malloc(sizeof(node_t*) * M);
    for (int i = 0; i < M; i++)
        t[i] = NULL;
    return t;
}

node_t* init_node(int value)
{
    node_t* aux = malloc(sizeof(node_t));
    aux->removed = 0;
    aux->value = value;
    return aux;
}

void insert(node_t** t1, node_t** t2, int value) {
    int index = h1(value);
    if (t1[index] == NULL)
        t1[index] = init_node(value);
    else if (t1[index]->removed)
    {
        t1[index]->value = value;
        t1[index]->removed = 0;
    }
    else
    {
        int index2 = h2(t1[index]->value);
        if (t2[index2] == NULL)
            t2[index2] = init_node(t1[index]->value);
        else if (t2[index2]->removed)
        {
            t2[index2]->value = t1[index]->value;
            t2[index2]->removed = 0;
        }
        t1[index]->value = value;
    }
}

void remove_value(node_t** t1, node_t** t2, int value) {
    int index1 = h1(value);
    int index2 = h2(value);
    if (t2[index2] != NULL && t2[index2]->value == value)
    {
        t2[index2]->removed = 1;
        free(t2[index2]);
        printf("removido valor %d\n", value);
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

void print(node_t** t1, node_t** t2)
{
    for (int i = 0; i < M; i++)
        if (t1[i] != NULL && t1[i]->removed == 0)
            printf("%d,T1,%d\n", t1[i]->value, i);

    for (int i = 0; i < M; i++)
        if (t2[i] != NULL && t2[i]->removed == 0)
            printf("%d,T2,%d\n", t2[i]->value, i);
}


