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

int find(node_t* t1, int value) {
    int key = h1(value);
    if (t1[key] == NULL)
        return NULL;
    else if (t1[key] == value)
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

void insert(node_t* t1, node_t* t2, int value) {
    int index = h1(value);
    node_t *list = array[index].head;
    node_t *item = malloc(sizeof(node_t));
    item->key = index;
    item->value = value;
    item->next = NULL;
    if(list == NULL) {
        array[index].head = item;
        array[index].tail = item;
        array[index].size++;
    } else {
        int find_index = find(list, index);
        if(find_index == -1) {
            array[index].tail->next = item;
            array[index].tail = item;
            array[index].size++;
        }
    }
}

void delete_hash(node_t* t1, node_t* t2) {
    free(t1);
    free(t2);
}

void print(arrayItem_t *list) {
    for(int i = 0; i < M; i++) {
        if(list[i].head != NULL && list[i].head->value != 0)
            printf("KEY(%d), VALUE(%d)\n" , list[i].head->key, list[i].head->value);
    }
}


