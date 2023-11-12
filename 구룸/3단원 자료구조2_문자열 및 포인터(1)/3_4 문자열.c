#include <stdio.h>
int main() {
	char a[101];
	gets(a, 101, stdin);
	
    for(int i=0; a[i]!='\0'; i++){
		if(a[i]==' ') ;
		else printf("%c", a[i]);
	} // made by wwwxsv19

	return 0;
}