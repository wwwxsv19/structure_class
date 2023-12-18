/*
삽입 정렬 : 1번째 인덱스부터 시작해
n번째 인덱스부터 0번째 인덱스까지 비교하며 정렬
*/ 

#include <stdio.h>
int main(){
	int list[] = {5, 3, 8, 1, 2, 7};
	int key, min, num;
	int n = sizeof(list) / sizeof(int);
	
	for(int i=1; i<n; i++){
		key = list[i];
		for(int j=i-1; j>=0 && list[j]>key; j--){
			list[j+1] = list[j];
		}
		list[j+1] = key;
	}
	for(int i=0; i<n; i++){
		printf("%d ", list[i]);
	}
	return 0;
}
