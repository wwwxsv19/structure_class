#include <stdio.h>

#define MAX 100

typedef struct Stack{
	char str[MAX];
	int top;
} Stack;

void initStack(Stack *s){
	s->top = -1;
}
int isFull(Stack *s){
	return s->top == MAX-1;
}
int isEmpty(Stack *s){	
	return s->top == -1;
}

void push(Stack* s, char c){
	if(isFull(s)){
		printf("FULL\n");
	}
	else{
		s->str[++s->top] = c;
	}
}

char pop(Stack *s){
	if(isEmpty(s)){
		printf("EMPTY\n");
		return 0;
	}
	return s->str[s->top--];
}

int palindrome(char string[]){
	Stack s;
	int i;

	initStack(&s);
	
	for(i=0; string[i]!='\0'; i++){
		if(string[i] >= 'A' && string[i] <= 'Z') string[i] += 'a'-'A';
		push(&s, string[i]);
	}
	
	for(i=0; string[i]!='\0';i++){
		char c = pop(&s);
		if(string[i] != c) 
			return 0;
	}
	return 1;
}

int main(void){
	char str[MAX];
	scanf("%s", str);
	
	if(palindrome(str)) printf("TRUE");
	else printf("FALSE");

	return 0;
}