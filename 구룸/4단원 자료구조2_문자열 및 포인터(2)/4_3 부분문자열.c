#include <stdio.h>
#include <stdlib.h>
int main(){
	int a, b;
	char* str = (char*)malloc(sizeof(char) * 100); //char str[100]의 의미
	scanf("%s", str); 
	scanf("%d %d", &a, &b);
	
	for(int i=a-1; i<b; i++){
		printf("%c", str[i]); // made by wwwxsv19
	}
	
	return 0;
}