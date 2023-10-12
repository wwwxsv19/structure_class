#include <stdio.h>
int main(){
	int arr[100]={0}, n, i=0;
	
	while(1){
		scanf("%d", &n);
		if(n==0) break;
		arr[i++]=n;
	}
	
	i--;
	
	for( ; i>=0; i--){
		printf("%d ", arr[i]);
	}
	
	return 0;
}