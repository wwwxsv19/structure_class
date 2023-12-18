/*
쉘 정렬 : 간격별 부분 리스트를 만들어 그 리스트를 삽입 정렬 후, 
정렬된 부분 리스트를 합쳐 다시 정렬 ( 간격을 줄여나가면서 )
*/ 

#include <stdio.h>

insertSort(int list[], int first, int last, int gap){
	int i, j, key;
	for(i=first+gap; i<=last; i= i+gap){
		key = list[i];
		for(j=i-gap; j>=first && key<list[j]; j=j-gap){
			list[j+gap] = list[j];
		}
		list[j+gap] = key;
	}
}

int main(){
	int list[] = {10, 8, 6, 20, 4, 3, 22, 1, 0, 15, 16};
	int i, j, gap;
	int n = sizeof(list) / sizeof(int);
	
	for(gap=n/2; gap>0; gap/=2){
		if(gap % 2 == 0) gap++;
		for(i=0; i<gap; i++){
			insertSort(list, i, n-1, gap);
		}
	}
	
	for(i=0; i<n; i++){
		printf("%d ", list[i]);
	} 
	
	return 0;
}
