#include <stdio.h>
int main(){
	char arr[51];
	int num = 0, cnt = 0;
	scanf("%s", arr);
	
	for(int i=0; arr[i]!='\0'; i++){
		if(arr[i] >= '0' && arr[i] <= '9'){
			num *= 10;
			num += arr[i] - '0';
		}
	}
	
	for(int i=1; i<=num; i++){
		if(num % i == 0) cnt++;
	}
	
	printf("%d\n%d", num, cnt);
	
	return 0;
}