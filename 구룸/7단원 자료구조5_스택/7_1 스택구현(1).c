#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef int element; // made by wwwxsv19

typedef struct Stack{
	int top;
	element data[MAX];
} Stack;

void initStack(Stack* s){
	s->top = -1;
}
int isEmpty(Stack* s){
	return s->top == -1; // made by wwwxsv19
}
int isFull(Stack* s){
	return s->top == MAX - 1;
}

void push(Stack* s, element item){
	if(isFull(s)){
		printf("Overflow!\n");
		return ;
	}
	s->data[++s->top] = item;
}

element pop(Stack* s){ // 반환 후 제거
	if(isEmpty(s)){
		printf("Underflow!\n");
		return 0;
	} // made by wwwxsv19
	return s->data[s->top--];
}

element peek(Stack* s){ // 반환만
	if(isEmpty(s)){
		printf("Underflow!\n");
		return 0;
	}
	return s->data[s->top];
}

int main(){
	Stack s;
	initStack(&s);

	push(&s, 1);
	push(&s, 2);
	push(&s, 3);
	
	printf("%d\n", pop(&s));
	printf("%d\n", peek(&s));
	printf("%d\n", pop(&s)); // made by wwwxsv19
	printf("%d\n", pop(&s));
	
	return 0;
}