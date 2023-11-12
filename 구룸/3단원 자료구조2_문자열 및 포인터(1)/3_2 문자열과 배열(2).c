#include <stdio.h>
int main(){
	char c, alpha[101] = {0};
	int i=0;
	
	scanf("%s", alpha);
	getchar();
	scanf("%c", &c);
	// made by wwwxsv19
	while(1){
		if(alpha[i]==c) break;
		else i++;
	}
	
	printf("%d번째\n", i+1);
	return 0;
}