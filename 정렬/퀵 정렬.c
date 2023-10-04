#include <stdio.h>
#define SWAP(x, y, t) ((t)=(x), (x)=(y), (y)=(t))

int partition(int list[], int left, int right){
	int pivot, temp;
	int low, high;
	
	low=left-1;
	high=right+1;
	pivot = list[left];
	
	do{
		do{
			low++;
		}while(list[low]<pivot);
		do{
			high--;
		}while(list[high]>pivot);
		if(low<high) SWAP(list[low], list[high], temp); 
	}while (low<high);
	
	//SWAP(list[low], list[high], temp); 
	return high;
}

void quicksort(int list[], int left, int right){
	if(left < right){
		int q = partition(list, left, right);
		for(int i=0; i<9; i++){
			printf("%d ", list[i]);
		}
		printf("\n");
		quicksort(list, left, q);
		quicksort(list, q+1, right);
	}	
}

int main(){
	int list[]={5, 3, 8, 4, 9, 1, 6, 2, 7};
	int n = sizeof(list)/sizeof(int);
	
	quicksort(list, 0, n-1);
	
	for(int i=0; i<n; i++){
		printf("%d ", list[i]);
	}
	
	return 0;
}
