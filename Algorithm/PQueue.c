#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

//Priority Queue 
typedef int ElementType; 
typedef struct _HeapNode {
	ElementType Data;
}HeapNode;

typedef struct _Heap {
	HeapNode* nodes; 
	int capacity;
	int used_size;
}Heap;

Heap* HEAP_Create(int capacity) {
	Heap* new_heap = NULL; 
	new_heap = (Heap*)calloc(1, sizeof(Heap));
	if (new_heap == NULL) {
		exit(1); 
	}
	new_heap->capacity = capacity; 
	HeapNode* temp = (HeapNode*)calloc(capacity, sizeof(HeapNode));
	if (temp == NULL) {
		free(new_heap); 
		exit(1); 
	}
	new_heap->nodes = temp; 
	new_heap->used_size = 0; 
	return new_heap; 
}

void HEAP_Destroy(Heap* h) {
	free(h->nodes);
	free(h);
}

void swap(HeapNode* a, HeapNode* b) {
	HeapNode temp = *a; 
	*a = *b;
	*b = temp; 
}

void HEAP_PrintNodes(Heap* h) {
	for (int i = 1; i <= h->used_size; i++) {
		printf("%d ", h->nodes[i].Data);
	}
	printf("\n");
}

int comp_max(int parent, int child) {
	return (parent > child); 
}

int comp_min(int parent, int child) {
	return (parent < child);
}

typedef int (*Comp_t) (int, int); 

void HEAP_Insert(Heap* h, ElementType data, Comp_t comp_fun) {
	int i = ++(h->used_size);
	h->nodes[i].Data = data; 
	while (i > 0 && comp_func(h->nodes[i].Data, h->nodes[i / 2].Data)) {
		swap(&h->nodes[i], &h->nodes[i / 2]);
		i /= 2;
	}
}

ElementType HEAP_Pop(Heap* h) {
	ElementType temp = h->nodes[1].Data; //the first element 

	h->nodes[1] = h->nodes[h->used_size--]; //replace the place with the last element
	
	int parent = 1; 
	while (1) {
		int left = parent * 2; 
		int right = parent * 2 + 1;
		int smallest = parent;

		if (h->nodes[left].Data < h->nodes[smallest].Data) {
			smallest = left; 
		} 
		if (h->nodes[right].Data < h->nodes[smallest].Data) {
			smallest = right; 
		}

		//exit condition
		if (parent == smallest) break;

		swap(&h->nodes[smallest], &h->nodes[parent]); //reorder the minHeap
		parent = smallest; 
	}
	return temp;
}

int main() {
	int N = 5; 
	ElementType temp;
	Heap* minHeap = NULL; 
	(void)freopen("pq_data.txt", "rt", stdin);
	(void)scanf("%d", &N);

	minHeap = HEAP_Create(N + 1);
	for (int i = 0; i < N; i++) {
		(void)scanf("%d", &temp); 
		HEAP_Insert(minHeap, temp, comp_max); 
	}
	HEAP_PrintNodes(minHeap);
	//HEAP_Insert(minHeap, 7);
	//HEAP_PrintNodes(minHeap);

	for (int i = 0; i < N+1; i++) {
		ElementType data = HEAP_Pop(minHeap);
		printf("%d\n", data);
	}

}