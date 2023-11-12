#include <stdio.h>
int main(){
	int n, num = 1;
	scanf("%d", &n);
	
	printf("1");
	
	for(int i=2; i<n; i++){
		if(n%i==0){
			printf(" + %d", i);
			num += i;
		}
	}
	printf(" = %d", num); 
	
	return 0;
} // made by wwwxsv19