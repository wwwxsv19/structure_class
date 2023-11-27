#include <stdio.h>
int main() {
	char a[101];
	gets(a, 101, stdin);
	
	for(int i=0; a[i]!='\0'; i++){
		if(a[i]==' ') continue;
		printf("%c", (a[i] < 'a')? a[i] + 32 : a[i]);
	}
	
	return 0;
}