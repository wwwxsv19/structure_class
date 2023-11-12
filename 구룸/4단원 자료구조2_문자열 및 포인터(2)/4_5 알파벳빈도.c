#include <stdio.h>
#include <string.h>
int main() {
	char s[1000001];
	int aph[26]={0}, num;
	scanf("%s", s);
	
	
	for(int i=0; s[i]!='\0'; i++){
		num = s[i];
		aph[num-65]++; // made by wwwxsv19
	}	
	
	for(int i=0; i<26; i++){
		if(aph[i]!=0){
			printf("%c : %d\n", i+65, aph[i]);
		}
	}	
	
	return 0;
}