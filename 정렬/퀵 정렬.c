#include <stdio.h>
#define SWAP(x, y, t) ((t)=(x), (x)=(y), (y)=(t))

int n, cnt; 

int partition(int list[], int left, int right){
	int pivot, temp;
	int low, high;
	
	low = left;
	high = right+1;
	pivot = list[left];
	
	do{
		do{
			low++;
		}while(list[low] < pivot);
		do{
			high--;
		}while(list[high] > pivot);
		if(low < high) SWAP(list[low], list[high], temp); 
	}while (low < high);
	
	SWAP(list[high], list[left], temp); 
	
	return high;
}

void quicksort(int list[], int left, int right){
	if(left < right){
		int q = partition(list, left, right);
		
		for(int i=0; i<n; i++){
			printf("%d ", list[i]);
		}
		printf("\n");
		
		quicksort(list, left, q-1);
		quicksort(list, q+1, right);
	}	
}

int main(){
	scanf("%d", &n);
	
	int list[n];
	for(int i=0; i<n; i++){
		scanf("%d", &list[i]);
	}
	
	quicksort(list, 0, n-1);
	
	return 0;
}