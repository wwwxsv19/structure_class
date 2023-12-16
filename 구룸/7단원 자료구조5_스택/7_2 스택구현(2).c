#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef int element;

typedef struct Stack{
	int top;
	element data[MAX];
} Stack;

void initStack(Stack* s){ // made by wwwxsv19
	s->top = -1;
}
int isEmpty(Stack* s){ // 스택이 텅 비어 있으면 true
	return s->top == -1;
}
int isFull(Stack* s){ // 스택이 가득 차 있으면 true
	return s->top == MAX - 1;
}

void push(Stack* s, element item){ // 삽입 연산
	if(isFull(s)){
		printf("Stack Overflow!\n");
		return ;
	}
	s->data[++s->top] = item;
}

element pop(Stack* s){ // 삭제 연산
	if(isEmpty(s))
		return -1; // made by wwwxsv19
	return s->data[s->top--];
}

int main(){
	int menu;
	element data;

	Stack s;
	initStack(&s);
	
	do{
		printf("1:push, 2:pop, 0:exit : ");
		scanf("%d", &menu);
		
		switch(menu){
			case 1:
				printf("데이터 입력 : ");
				scanf("%d", &data);
				push(&s, data);
				break;
			case 2:
				data = pop(&s);
				if(data != -1)
					printf("pop 데이터 : %d\n", data);
				else
					printf("Stack Underflow!\n");
				break;
			case 0: // made by wwwxsv19
				break;
			default:
				printf("잘못된 입력 입니다. \n");
				break;
		}
	} while(menu);
	
	return 0;
}