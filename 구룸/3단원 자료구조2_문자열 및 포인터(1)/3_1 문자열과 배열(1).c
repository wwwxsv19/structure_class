// 예제1
#include <stdio.h>
int main(){
	char alpha[6] = { 'H', 'E', 'L', 'L', 'O', '!'}, c;
	printf("찾고 싶은 문자 : ");
	scanf("%c", &c);
// made by wwwxsv19
	for(int i=0; i<6; i++){
		if(alpha[i] == c){
			printf("%d번째\n", i+1);
			break;
		} 
	}
	
	return 0;
}