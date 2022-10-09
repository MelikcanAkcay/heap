//
// Created by Melikcan Akcay on 09.10.2022.
//

#ifndef HEAP_HEAP_H
#define HEAP_HEAP_H

#endif //HEAP_HEAP_H

typedef struct node_s {
    struct node_s *parent;
    struct node_s *leftChild;
    struct node_s *rightChild;
    int data;
}node_t;

typedef struct heap_s{
    int size;
    node_t* root;
}heap_t;

heap_t *createHeap();
void insert(heap_t *heap,node_t *currNode, int data);
int minimum(node_t *currNode);
void extractMin(node_t *currNode);
char getError(heap_t *h);
void toString(node_t *currNode);
void destroyHeap(heap_t *h);