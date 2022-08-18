#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "hash.h"

int h1(int value) {
    return value % M; 
}

int h2(int value) {
    return (floor(M * (value * 0.9) - floor(value * 0.9)));
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
    return t;
}

node_t* init_node()
{
    node_t* aux = malloc(sizeof(node_t));
    aux->removed = 0;
    return aux;
}

void insert(node_t** t1, node_t** t2, int value) {
    int index = h1(value);
    if (t1[index] == NULL)
    {
        t1[index] = init_node();
        t1[index]->value = value;
    }
    else if (t1[index]->removed)
    {
        t1[index]->value = value;
        t1[index]->removed = 0;
    }
    else
    {
        int index2 = h2(t1[index]->value);
        if (t2[index2] == NULL)
            t2[index2] = init_node();
        t2[index2]->value = t1[index]->value;
        t1[index]->value = value;
    }
}

void delete_hash(node_t** t)
{
    for (int i = 0; i < M; i++)
        if (t[i])
            free(t[i]);
    free(t);
}

void print(node_t** t) {
    for (int i = 0; i < M; i++) {
        if(t[i] != NULL && !t[i]->removed)
            printf("KEY(%d), VALUE(%d), T1\n" , i, t[i]->value);
    }
}


