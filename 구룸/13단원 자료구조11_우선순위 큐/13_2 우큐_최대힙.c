#include <stdio.h>
#include <stdlib.h>

#define MAX 200

typedef struct{
	int key;
} element; // made by wwwxsv19

typedef struct{
	element heap[MAX];
	int size;
} Heap;

Heap* create(){
	return (Heap*)malloc(sizeof(Heap));
}
void init(Heap* h){ // made by wwwxsv19
	h->size = 0;
}

void insertMaxHeap(Heap* h, element item){
    int i = ++(h->size);
    while(i!=1 && item.key > h->heap[i / 2].key){
        h->heap[i] = h->heap[i / 2];
        i = i / 2;
    }
    h->heap[i] = item;
}

element deleteMaxHeap(Heap* h){ 
	int parent = 1, child = 2;
	
	element pData = h->heap[1];
	element cData = h->heap[(h->size)--];
	
	while(child <= h->size){
		if (child < h->size && (h->heap[child].key < h->heap[child + 1].key)) child++;
		if (cData.key >= h->heap[child].key) break; 
		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
	} // made by wwwxsv19
	h->heap[parent] = cData;
	return pData;
}

void heap_sort(element a[], int n){
	Heap* h = create();
	init(h);
	
	for(int i=0; i<n ;i++){
		insertMaxHeap(h, a[i]);
	}
	for(int i=n-1; i>=0; i--){
		a[i] = deleteMaxHeap(h);
	}
	
	free(h);
} 

#define SIZE 8

int main(){
	element list[SIZE] = {23, 56, 11, 9, 56, 99, 27, 34};
	heap_sort(list, SIZE);
	
	for(int i=0; i<SIZE; i++){
		printf("%d ",list[i].key);
	}
	printf("\n");
	
	return 0;
} // made by wwwxsv19