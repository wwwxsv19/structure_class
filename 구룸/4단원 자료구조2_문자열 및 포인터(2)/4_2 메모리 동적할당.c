#include <stdio.h>
#include <stdlib.h>
int maxh(int* height, int n) {
	int maxn = height[0];
	for(int i=1; i<n; i++){
		if(maxn < height[i]) maxn = height[i];
	}
	return maxn; // made by wwwxsv19
}

int main(){
    int n;
    int* height;

	scanf("%d", &n) ;
	
	height = malloc(sizeof(int) * n);
	
	for(int i=0; i<n; i++){
		scanf("%d", &height[i]);
	}
	// made by wwwxsv19
	printf("%d\n", maxh(height, n)) ;
	
	free(height);
    
    return 0; 
}