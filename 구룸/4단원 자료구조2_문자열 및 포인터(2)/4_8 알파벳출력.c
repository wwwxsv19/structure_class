#include <stdio.h>
#include <string.h>
int main() {
	char s[1000001];
	int cnt[25] = {0}, n, max=0;
	
	scanf("%s", s);
	
	for(int i=0; s[i]!='\0'; i++){
		n=s[i];
		if(n>90) n-=32;
		n-=65; // made by wwwxsv19
		cnt[n]++;
	}
	
	for(int i=1; i<26; i++){
		if(cnt[max] < cnt[i]) max = i;
	}
	
	for(int i=0; i<26; i++){
		if(cnt[max] == cnt[i] && max!=i){ 
			max = -1;
			break;
		}
	}
	// made by wwwxsv19
	if(max != -1) printf("%c", max+65);
	else printf("?");
	
	return 0;
}