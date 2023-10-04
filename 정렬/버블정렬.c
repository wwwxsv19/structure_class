#include <stdio.h>
int main(){
	int list[] = {5, 3, 8, 1, 2, 7};
	int key, min, n=sizeof(list)/sizeof(int), num, i, j;
	
	for(i=n-1; i>0; i--){
		for(j=0; j<i; j++){
			if(list[j]>list[j+1]){
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
