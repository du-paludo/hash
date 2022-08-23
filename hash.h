#ifndef __hash__
#define __hash__

#define M 11

struct node {
    int value;
    int removed;
}; typedef struct node node_t;

/* struct arrayItem {
    struct node *head;
    struct node *tail;
    int size;
}; typedef struct arrayItem arrayItem_t; */

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