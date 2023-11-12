#include <stdio.h>
#include <stdlib.h>
#define STACK_SIZE 20

typedef char element;

typedef struct{
	element data[STACK_SIZE];
	int top;
} Stack;

void initStack( Stack *s ){ // made by wwwxsv19
	s->top = -1;
}
int isFull( Stack *s ){
	return s->top == STACK_SIZE -1;
}
int isEmpty( Stack *s ){
	return s->top == -1;
}

void push( Stack *s, element c ){
	if(isFull(s)){
		return;
	}
	s->top++;
	s->data[s->top] = c;
}
// made by wwwxsv19
void pop( Stack *s ){
	if(isEmpty(s)){
		return ;
	}
	else{
		printf("%c", s->data[s->top]);
		s->top--;
	}
}

int main(){
	int i, n;    
    element str[STACK_SIZE];

	Stack s;
	
	initStack(&s);
	
	printf("문자열 입력 : "); // made by wwwxsv19
	scanf("%s", str);
	
	for(i=0; str[i]!='\0'; i++){
		push(&s, str[i]);
	}
	
	while(!isEmpty(&s)){
		pop(&s);
	}
	
	return 0;
}