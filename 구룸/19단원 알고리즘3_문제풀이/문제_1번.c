#include <stdio.h>
int main(){
	int n, m, sum = 0;
	scanf("%d %d", &n, &m);
	
	for(int i=m; i<=n; i=i+m){
		sum += i;
	}
	
	printf("%d", sum);
	
	return 0;
} // made by wwwxsv19