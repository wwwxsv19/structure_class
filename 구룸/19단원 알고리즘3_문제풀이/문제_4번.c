#include <stdio.h>
int main(){
	int n, num, min=101, max=1;
	
	scanf("%d", &n);
	
	for(int i=0; i<n; i++){
		scanf("%d", &num);
		if(num < min) min = num;
		if(num > max) max = num;
	}
	// made by wwwxsv19
	printf("%d", max-min);
	
	return 0;
}