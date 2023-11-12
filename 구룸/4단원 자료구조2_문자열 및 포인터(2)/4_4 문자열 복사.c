#include <stdio.h>
void mystrcpy(char str2[], char str1[]) {
	int i = 0;
	while(str1[i]!='\0'){ // 문자열이 끝나면 와일문 중단
		str2[i] = str1[i];
		i++;
	}
	str2[i+1] = '\0'; // made by wwwxsv19
}

void mystrcpy2(int* str3[], int* str1[]) {
    int i = 0;
	while(str1[i]!='\0'){
		str3[i] = str1[i];
		i++;
	}   
	str3[i+1]='\0';
}

int main() {
	char str1[257],	str2[257], str3[257];
	fgets(str1,257,stdin);
	
    mystrcpy(str2, str1); // made by wwwxsv19
    puts(str2);
	
    mystrcpy2(str3, str1);
    puts(str3);
	
    return 0;
}