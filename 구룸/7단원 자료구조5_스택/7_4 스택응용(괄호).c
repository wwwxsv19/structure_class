#include <stdio.h>
#include <stdlib.h>
#define STACK_SIZE 20

typedef char element;

typedef struct{
	element data[STACK_SIZE];
	int top;
} Stack; // made by wwwxsv19

void initStack( Stack *s ){
	s->top = -1;
}
int isFull( Stack *s ){
	return s->top == STACK_SIZE - 1;
}
int isEmpty( Stack *s ){
	return s->top == -1;
}
void push( Stack *s, element c ){
	if(isFull(s)){
		printf("stack is full\n");
		return ;
	}
	s->top++;
	s->data[s->top] = c;
}
element pop( Stack *s ){
	if(isEmpty(s)){ // made by wwwxsv19
		printf("stack is empty\n");
		return 0;
	}
	return s->data[s->top--];
}

int checkTest(char expr[]){
	int i;
	char ch, open_ch;
	Stack s;
	
	initStack(&s);
	
    for(i=0;expr[i]!='\0';i++){ // made by wwwxsv19
		ch = expr[i];
		switch(ch){
			case '(':
			case '[':
			case '{':
				push(&s, ch);
				break;
			case ')':
			case ']':
			case '}':	
				if (isEmpty(&s)) return 0;
					open_ch = pop(&s);
				if ((open_ch == '(' && ch != ')') ||
					(open_ch == '[' && ch != ']') ||
					(open_ch == '{' && ch != '}') ) {
					return 0;
				}
				break;
		}
	}
	if (!isEmpty(&s)) return 0;
	return 1;
}

int main(){
	int i;
	Stack s;
	char expr[20];
	
	printf("괄호포함 수식 입력 : "); // made by wwwxsv19
	scanf("%s", expr);
	
	if (checkTest(expr)) printf("성공");
	else printf("실패");
	
	return 0;
}
