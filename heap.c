#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

void swap(Request *a, Request *b) {
    Request temp = *a;
    *a = *b;
    *b = temp;
}

MinHeap* create_heap(int capacity) {
    MinHeap* heap = (MinHeap*) malloc(sizeof(MinHeap));

    if (capacity <= 0)
        capacity = 1;

    heap->arr = (Request*) malloc(sizeof(Request) * capacity);
    heap->size = 0;
    heap->capacity = capacity;

    return heap;
}

void heapify_up(MinHeap* heap, int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;

        if (heap->arr[parent].priority <= heap->arr[index].priority)
            break;

        swap(&heap->arr[parent], &heap->arr[index]);
        index = parent;
    }
}

void heapify_down(MinHeap* heap, int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < heap->size &&
        heap->arr[left].priority < heap->arr[smallest].priority)
        smallest = left;

    if (right < heap->size &&
        heap->arr[right].priority < heap->arr[smallest].priority)
        smallest = right;

    if (smallest != index) {
        swap(&heap->arr[index], &heap->arr[smallest]);
        heapify_down(heap, smallest);
    }
}

void insert(MinHeap* heap, Request req) {
    if (heap->size == heap->capacity) {

        if (heap->capacity == 0)
            heap->capacity = 1;
        else
            heap->capacity *= 2;

        Request *temp = realloc(heap->arr, sizeof(Request) * heap->capacity);
        if (temp == NULL) {
            printf("Bellek tahsis edilemedi!\n");
            exit(1);
        }
        heap->arr = temp;
    }

    heap->arr[heap->size] = req;
    heapify_up(heap, heap->size);
    heap->size++;
}

Request extract_min(MinHeap* heap) {
    if (heap->size == 0) {
        printf("Heap bos!\n");
        exit(1);
    }

    Request min = heap->arr[0];
    heap->arr[0] = heap->arr[heap->size - 1];
    heap->size--;

    heapify_down(heap, 0);
    return min;
}

void free_heap(MinHeap* heap) {
    free(heap->arr);
    free(heap);
}
