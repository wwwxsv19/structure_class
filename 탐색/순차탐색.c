#include <stdio.h>
int list[] = {9, 5, 8, 3, 7};
int key, result;

int search(int low, int high){
	for(int i=low; i<high; i++){
		if(list[i] == key) return i+1;
	}
	return -1; 
}

int main(){
	int n = sizeof(list)/sizeof(int);
	
	printf("탐색할 key 값 입력 : ");
	scanf("%d", &key);
	
	result = search(0, n);
	
	if(result == -1) printf("탐색 실패\n");
	else printf("탐색 성공, 비교 횟수 : %d\n", result);
	
	return 0;
}