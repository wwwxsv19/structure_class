#include <stdio.h>
#include <stdlib.h>

#define MAX 200

typedef int element;

typedef struct Heap{
	element heap[MAX];
	int heap_size;
} Heap;

void insertMaxHeap(Heap* h, element item){
	int i = ++(h->heap_size);
	while((i != 1) && (item > h->heap[i / 2])){
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i] = item;
}

element deleteMaxHeap(Heap* h){ 
	int parent = 1, child = 2;
	
	element pData = h->heap[1];
	element cData = h->heap[(h->heap_size)--];
	
	while(child <= h->heap_size){
		if (child < h->heap_size && (h->heap[child] < h->heap[child + 1])) child++;
		if (cData >= h->heap[child]) break; 
		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
	}
	h->heap[parent] = cData;
	return pData;
}

void printHeap(Heap* heap){
	for(int i=1; i<=heap->heap_size; i++)
		printf("[%d]: %d ", i, heap->heap[i]);
	printf("\n");
}
	
int main(){
	element e1 = 10, e2 = 5, e3 = 30;
	Heap* heap = (Heap*)malloc(sizeof(Heap));
	heap->heap_size = 0;
	
	printf("최대힙 삽입\n");
	insertMaxHeap(heap, e1); printHeap(heap);
	insertMaxHeap(heap, e2); printHeap(heap);
	insertMaxHeap(heap, e3); printHeap(heap);

	printf("최대힙 삭제\n");
	printHeap(heap);
	deleteMaxHeap(heap); printHeap(heap);
	deleteMaxHeap(heap); printHeap(heap);
	deleteMaxHeap(heap); printHeap(heap);
	free(heap);
	
	return 0;
}