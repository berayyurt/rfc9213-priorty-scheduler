#include <stdio.h>
#include "heap.h"
#include "parser.h"

int main() {

    MinHeap* heap = create_heap(4);

	char *headers[] = {
        "u=3",
        "u=1",
        "u=5",
        "u=2",
        "u=0"
    };

    printf("Istekler kuyruga ekleniyor...\n");

	    int i;
	for (i = 0; i < 5; i++) {
        Request req;
        req.id = i + 1;
        req.priority = parse_priority(headers[i]);

        printf("Request %d eklendi (priority=%d)\n", req.id, req.priority);
        insert(heap, req);
    }

    printf("\nIsleme sirasi:\n");

     while (heap->size > 0) {
        Request r = extract_min(heap);
        printf("Request %d (priority=%d)\n", r.id, r.priority);
    }

	free_heap(heap);

    return 0;
}
