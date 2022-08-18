#ifndef __hash__
#define __hash__

#define M 11

struct node {
    int key;
    int value;
}; typedef struct node node_t;

struct arrayItem {
    struct node *head;
    struct node *tail;
    int size;
}; typedef struct arrayItem arrayItem_t;

int h1(int key);

int h2(int key);

int find(node_t *list, int key);

void insert(node_t* t1, node_t* t2, int value);

void delete_hash(node_t* t1, node_t* t2);

void print(arrayItem_t *list);

#endif