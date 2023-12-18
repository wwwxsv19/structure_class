#include <stdio.h>
int list[] = {2, 6, 11, 13, 18, 20, 22, 27, 29, 30, 34, 38, 41, 42, 45, 47};
int key, result;

int binary_search(int low, int high){
	int middle;
	
	while(low<=high){
		middle = (low+high)/2;
		
		if(key == list[middle]) return middle + 1;
		else if(key < list[middle]) high = middle - 1;
		else low = middle + 1;
	}
	
	return -1;
}

int main(){
	int n = sizeof(list)/sizeof(int);
	
	printf("탐색할 key 값 입력 : ");
	scanf("%d", &key);
	
	result = binary_search(0, n-1);
	
	if(result == -1) printf("탐색 실패\n");
	else printf("탐색 성공, 비교 횟수 : %d\n", result);
	
	return 0;
}
