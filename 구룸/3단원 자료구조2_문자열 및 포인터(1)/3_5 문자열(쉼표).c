#include <stdio.h>
#include <string.h>
int main() {
	char str[] = "123,456,789";
	int num = 0, i, len;
	
	for(i=0; str[i]!='\0'; i++){
		if(str[i] == ','){
			printf("%d\n", num);
			num = 0;
			continue; // made by wwwxsv19
		}
		num = num*10+(str[i]-'0');
	}
	printf("%d\n", num);

	return 0;
}