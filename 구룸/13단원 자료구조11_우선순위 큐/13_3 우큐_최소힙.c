#include <stdio.h>
#include <stdlib.h>

#define MAX 200

typedef int element;

typedef struct{
	element heap[MAX];
	int size;
} Heap;
// made by wwwxsv19
void insertMinHeap(Heap* h, element item){
	int i = ++(h->size);
	while((i != 1) && (item < h->heap[i / 2])){
		h->heap[i] = h->heap[i / 2];
		i = i / 2;
	}
	h->heap[i] = item;
}

element deleteMinHeap(Heap* h){ 
	int parent = 1, child = 2;
	
	element pData = h->heap[1];
	element cData = h->heap[(h->size)--];
	
	while(child <= h->size){
		if (child < h->size && (h->heap[child] > h->heap[child + 1])) child++;
		if (pData >= h->heap[child]) break; 
		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
	} // made by wwwxsv19
	h->heap[parent] = cData;
	return pData;
}

void printHeap(Heap* h){
	for(int i = 1;i<=h->size;i++)
		printf("[%d]: %d ",i, h->heap[i]);
	printf("\n");
}

int main(){
	element e1 = 10, e2 = 5, e3 = 30;
	Heap* heap = (Heap*)malloc(sizeof(Heap));
	heap->size = 0;
	
	//삽입
	printf("최소힙 삽입\n");
	insertMinHeap(heap, e1);	printHeap(heap);
	insertMinHeap(heap, e2);	printHeap(heap);
	insertMinHeap(heap, e3);	printHeap(heap);

	//삭제
	printf("최소힙 삭제\n"); // made by wwwxsv19
	printHeap(heap);
	deleteMinHeap(heap);	printHeap(heap);
	deleteMinHeap(heap);	printHeap(heap);
	deleteMinHeap(heap);	printHeap(heap);
	
	free(heap);
	
	return 0;
}