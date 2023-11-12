#include <stdio.h>
int main(){
	int a[50][50], num=0, lt, rt, top, bt, n;
	
	scanf("%d", &n);
	// made by wwwxsv19
	rt = bt = n;
	lt = top = 1;
	
	while(num<n*n){
		for(int j=lt; j<=rt && num<=n*n; j++){
			a[top][j]=++num; //[1][1]=1, [1][2]=2, [1][3]=3;
		}
		top++; // top = 2;
		for(int i=top; i<= bt && num <= n*n; i++){
			a[i][rt]=++num; //[2][3]=4, [3][3]=5;
		}
		rt--; // rt = 2;
		for(int j=rt; j>= lt && num <= n*n; j--){
			a[bt][j]=++num; //[3][2]=6; [3][1]=7;
		}
		bt--; // bt = 2;
		for(int i=bt; i>=top && num <= n*n; i--){
			a[i][lt]=++num; // [2][1]=8; [2][2]=9;
		}
		lt++;
	}
	
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){ // made by wwwxsv19
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}