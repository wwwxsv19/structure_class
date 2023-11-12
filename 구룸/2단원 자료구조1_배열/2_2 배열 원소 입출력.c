#include <stdio.h>
int main(){
	int arr[100]={0}, n, i=0;
	
	while(1){
		scanf("%d", &n);
		if(n==0) break; 
		// 굳이 이렇게 한 이유? 0 이 입력되기 전에 끝내려고...
		arr[i++]=n;
	}
	
	i--;
	
	for( ; i>=0; i--){
		printf("%d ", arr[i]);
	}
	// made by wwwxsv19
	return 0;
}