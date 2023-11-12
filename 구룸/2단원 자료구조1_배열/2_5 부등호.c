#include <stdio.h>
#include <stdlib.h>
int main(){
	int n;
	scanf("%d", &n);
	
	int* arr = (int*)malloc(sizeof(int)*n);
	
	for(int i=0; i<n; i++){
		scanf("%d", &arr[i]);
	}
	// made by wwwxsv19
	for(int i=0; i<n; i++){
		printf("%d: ", i+1);
		
		for(int j=0; j<n; j++){
			if(i==j) continue;
		
			printf("%c", (arr[i]>arr[j])? '>':(arr[i]<arr[j])? '<':'=');
			printf("%c", (j!=n-1)? ' ':'\n');
		}
	}
	// made by wwwxsv19
	free(arr);
	
	return 0;
}