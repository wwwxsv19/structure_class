#include <stdio.h>
int main(){
	char a[5];
	
	for(int i=0; i<5; i++){
		scanf("%c ", &a[i]); 
		/*
		공백(문자)으로 띄워진 채 입력받기 때문에 
		공백이 잘못 입력될 수도 있음
		이를 방지하기 위해 %c 뒤에 띄어쓰기를 붙인다
		*/
	}
	
	for(int i=4; i>=0; i--){
		printf("%c", a[i]); // made by wwwxsv19
	}
	
	return 0;
}