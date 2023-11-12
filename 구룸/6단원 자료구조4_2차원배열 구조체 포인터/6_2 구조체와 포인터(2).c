#include <stdio.h>
#include <stdlib.h>

typedef struct{
	char name[20];
	int* p;
} data;

int main(){
	int n = 50;
	data d1;
	data* d2 = (data*)malloc(sizeof(data));
	
    d1.p = &n; // made by wwwxsv19
	d2->p = &n;
	
    printf("%d\n", *d1.p + *d2->p);
	
    strcpy(d2->name, "boddy");
	
    printf("%s\n", (*d2).name);
	printf("%d\n", *(*d2).p);
	
	free(d2);
	
    return 0;
}