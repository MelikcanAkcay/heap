#include <stdio.h>
#include <malloc.h>
#include "heap.h"

heap_t *createHeap(){
    heap_t *baum = malloc(sizeof (heap_t));
    baum->size = 0;
    baum->root = NULL;
    return baum;
}

node_t *createNode(int data, node_t* parent){
    node_t *newNode = malloc(sizeof (node_t));
    newNode->leftChild = NULL;
    newNode->rightChild = NULL;
    newNode->parent = parent;
    newNode->data = data;
    return newNode;
}

void insert(heap_t *heap,node_t *currNode, int data){
    if(heap->root == NULL){
        node_t *newNode = createNode(data, currNode);
        heap->root = newNode;
        heap->size++;
        return;
    }
    if(data <= currNode->data){
        if(currNode->leftChild == NULL){
            currNode->leftChild = createNode(data, currNode);
            heap->size++;
            return;
        }
        insert(heap, currNode->leftChild, data);  //rekursiv dargestellt
    }

    if(data > currNode->data){
        if(currNode->rightChild == NULL){
            currNode->rightChild = createNode(data, currNode);
            heap->size++;
            return;
        }
        insert(heap, currNode->rightChild, data);
    }
}

void toString(node_t *currNode){

    if (currNode == NULL){
        printf("NULL\n");
        return;
    }
    printf("%d\n", currNode->data);
    toString(currNode->leftChild);
    toString(currNode->rightChild);
}

int minimum(node_t *currNode) {
    if(currNode->leftChild != NULL){
        minimum(currNode->leftChild);
    } else{
        return currNode->data;
    }
}

void extractMin(node_t *currNode){
    while (currNode->leftChild != NULL){
        currNode = currNode->leftChild;
    }
    if(currNode->rightChild != NULL){
        currNode->rightChild->parent = currNode->parent;
        currNode->parent->leftChild = currNode->rightChild;
        free(currNode);
        return;
    } else{
        currNode->parent->leftChild = NULL;
        free(currNode);
        return;
    }
}

void destroyHeap(heap_t *heap){
    free(heap); //speicher freigeben
}


int main() {

    heap_t *newHeap = createHeap();
    insert(newHeap, newHeap->root,20);
    insert(newHeap, newHeap->root,15);
    insert(newHeap, newHeap->root,25);
    insert(newHeap, newHeap->root,17);
    insert(newHeap, newHeap->root,23);
    insert(newHeap, newHeap->root,1);


    toString(newHeap->root);
    int result = minimum(newHeap->root);
    printf("\nkleinste zahl: %d\n", result);

    extractMin(newHeap->root);

    toString(newHeap->root);
    result = minimum(newHeap->root);
    printf("\nkleinste zahl: %d\n", result);

    extractMin(newHeap->root);

    result = minimum(newHeap->root);
    printf("\nkleinste zahl: %d\n", result);

    printf("Zerstöre den Heap jetzt");
    destroyHeap(newHeap);

    toString(newHeap->root);
    return 0;
}
