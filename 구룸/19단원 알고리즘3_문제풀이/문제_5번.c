#include <stdio.h>
int main(){
	char a[15], gen;
	int age;
	
	scanf("%s", a);
	
	age = (a[0] - '0') * 10 + (a[1]-'0');
	age += (a[7] - '0') < 3? 1900 : 2000;
	
	gen = (a[7]-'0')% 2 == 1? 'M' : 'W';
	
	printf("%d %c", (2019 - age) + 1, gen); // made by wwwxsv19
	
	return 0;
}