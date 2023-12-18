// 선택 정렬 : 최솟값을 찾아 바꾼다

#include <stdio.h>
int main(){
	int list[] = {5, 3, 8, 1, 2, 7};
	int index, min, num;
	int n = sizeof(list) / sizeof(int);
	
	for(int i=0; i<n-1; i++){ 
		min = i;
		for(int j=i+1; j<n; j++){
			if(list[j] < list[min]) min = j;
		}
		num = list[i];
		list[i] = list[min];
		list[min] = num;
	}
	for(int i=0; i<n; i++){
		printf("%d ", list[i]);
	}
	return 0; 
}