#include <stdio.h>
int main(){
	int n, m, i, j, x, y, k, num;
	scanf("%d %d", &n, &m);
	
	int **arr = (int**)malloc(sizeof(int*) * n);
	for(i=0; i<n; i++){
		arr[i] = (int*)malloc(sizeof(int) * m); // made by wwwxsv19
	}
	
	for(i=0; i<n; i++){
		for(j=0; j<m; j++){
			scanf("%d", &arr[i][j]);
		}
	}
	
	scanf("%d", &k);
	
	while(k--){
		num = 0;
		scanf("%d %d %d %d", &i, &j, &x, &y);
		for(int a = i-1; a<x; a++){
			for(int b = j-1; b<y; b++){
				num+=arr[a][b];
			}
		} // made by wwwxsv19
		printf("%d\n", num);
	}

	for(i=0; i<n; i++){
		free(arr[i]);
	}
	free(arr);
}