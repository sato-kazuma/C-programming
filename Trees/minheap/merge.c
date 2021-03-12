#include"minheap_int.h"

#include<string.h>
#include<stdlib.h>

Heap* MergeHeap(const Heap* h1, const Heap* h2) {

	Heap* h = CreateEmptyHeap();

	if (IsEmptyHeap(h1) && IsEmptyHeap(h2)) {
		return h;
	}

	if (!IsEmptyHeap(h1) && IsEmptyHeap(h2)) {

		h->data = malloc(h1->size * sizeof(ElemType));
		h->size = h1->size;
		memcpy(h->data, h1->data, h->size * sizeof(ElemType));
	}
	if (IsEmptyHeap(h1) && !IsEmptyHeap(h2)) {

		h->data = malloc(h2->size * sizeof(ElemType));
		h->size = h2->size;
		memcpy(h->data, h2->data, h->size * sizeof(ElemType));
	}
	if (!IsEmptyHeap(h1) && !IsEmptyHeap(h2)) {

		h->data = malloc((h1->size + h2->size) * sizeof(ElemType));
		h->size = h1->size + h2->size;
		memcpy(h->data, h1->data, h1->size * sizeof(ElemType));
		memcpy(h->data + h1->size, h2->data, h2->size * sizeof(ElemType));

		for (int i = h->size / 2 - 1; i >= 0; --i) {

			MoveDownMinHeap(h, i);
		}
	}

	return h;
}
