#include <stdio.h>
#include <string.h>

typedef struct Person{
	char name[10];
	int age;
} Ps; // made by wwwxsv19

void inputData( Ps *p ){
	scanf("%s %d", p->name, &p->age);
}

void outputData( Ps *p ){
	printf("%s, %d\n", p->name, p->age);
} 

int main(){
	Ps p[3];
	
	for(int i=0; i<3; i++){
		inputData(&p[i]);
	}

	for(int i=0; i<3; i++){
		outputData(&p[i]);
	}
	return 0;
}