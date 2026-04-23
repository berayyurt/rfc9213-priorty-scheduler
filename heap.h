#ifndef HEAP_H
#define HEAP_H

#include "request.h"

typedef struct {
    Request *arr;
    int size;
    int capacity;
} MinHeap;

MinHeap* create_heap(int capacity);
void insert(MinHeap* heap, Request req);
Request extract_min(MinHeap* heap);
void heapify_up(MinHeap* heap, int index);
void heapify_down(MinHeap* heap, int index);
void free_heap(MinHeap* heap);

#endif
