#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 10

typedef int element;

typedef struct STACK{
	int top;
	int data[STACK_SIZE];
} Stack;

void initStack(Stack *s){ // made by wwwxsv19
	s->top = -1;
}

int isFull(Stack *s){   // 스택이 가득 차 있으면 true 리턴
	return s->top == STACK_SIZE-1;
}

int isEmpty(Stack *s){   // 스택이 비어 있으면 true 리턴
	return s->top == -1;
}

void psh(Stack *s, int data){ //스택이 가득 차 있으면 문구 출력 후 리턴, 아니면 push
	if(isFull(s)){
		printf("stack is full\n");
		return ;
	}
	s->data[++s->top] = data;
}

void pop(Stack *s){  //스택이 비어 있으면 문구 출력 후 0 리턴, 아니면 맨 위 데이터 리턴
	if(isEmpty(s)){
		printf("stack is empty\n");
		return ;
	} // made by wwwxsv19
	else{
		printf("pop 데이터 : %d\n", s->data[s->top--]);
	}
}

int main(){
	int menu;
	element data;
	Stack s;

	initStack( &s );
	
	do{
	
		printf("1:push, 2:pop, 0:exit : ");
		scanf("%d", &menu);
		
		switch(menu){
			case 1:
				printf("데이터 입력 : ");
				scanf("%d", &data);
				psh(&s, data);
				break;
				
			case 2:
				pop(&s);
				break;
				
			case 0: // made by wwwxsv19
				break;
			
			default:
				printf("잘못된 입력 입니다. \n");
				break;
		}
	}while(menu);
	
	return 0;
}