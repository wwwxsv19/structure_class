/* 
버블 정렬 : 인접한 두 인덱스끼리 비교해서 정렬, 
정렬된 가장 마지막 인덱스는 다음 순회부턴 제외하고 정렬
*/

#include <stdio.h>
int main(){
	int list[] = {5, 3, 8, 1, 2, 7};
	int key, min, num;
	int n = sizeof(list) / sizeof(int);

	for(int i=n-1; i>0; i--){
		for(int j=0; j<i; j++){
			if(list[j] > list[j+1]){
				num = list[j+1];
				list[j+1] = list[j];
				list[j] = num;
			}
		}
	} 
	for(int i=0; i<n; i++){
		printf("%d ", list[i]);
	}
	return 0;
}