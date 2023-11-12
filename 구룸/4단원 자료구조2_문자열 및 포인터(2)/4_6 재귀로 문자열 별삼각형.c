#include <stdio.h>
char star[20];
int f(int n){
	if(n<1) return 1;
	f(n-1);
	star[n-1] = '*';
	printf("%s\n", star);
}

int main(){
	int n; // made by wwwxsv19
	scanf("%d", &n);
	f(n);
	
	return 0;
}