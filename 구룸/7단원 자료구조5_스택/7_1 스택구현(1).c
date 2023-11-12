#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_STACK_SIZE 100

typedef int element; // made by wwwxsv19

typedef struct{
	int top;
	element data[MAX_STACK_SIZE];
}Stack;

Stack s; // 전역 변수

void initStack(){
	s.top = -1;
}

bool isEmpty(){
	return (s.top == -1); // made by wwwxsv19
}

bool isFull(){
	return (s.top == MAX_STACK_SIZE-1);
}

void push(element item){
	if(isFull()){
		printf("스택 : 꽉 찼습니다.\n");
		return ;
	}
	s.data[++s.top] = item;
}

element pop(){ //반환후 제거
	if(isEmpty()){
		printf("스택 : 텅 비었습니다.\n");
		return 0;
	} // made by wwwxsv19
	return s.data[s.top--];
}

element peek(){//반환만
	if(isEmpty()){
		printf("스택 : 텅 비었습니다.\n");
		return 0;
	}
	return s.data[s.top];
}

int main(){
	s.top = -1;
	
	push(1);
	push(2);
	push(3);
	
	printf("%d\n", pop());
	printf("%d\n", peek());
	printf("%d\n", pop()); // made by wwwxsv19
	printf("%d\n", pop());
	
	return 0;
}