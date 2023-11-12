#include <stdio.h>
int main(){
	int n, m, sum=0;
	scanf("%d %d", &n, &m);
	
	for(int i=n; i<=m; i++){
		if(i == m) printf("%d = %d", i, sum+i);
		else{
			printf("%d + ", i);
			sum += i;
		}
	}
	
	return 0;
} // made by wwwxsv19