#include <stdio.h>
#define MAX 300

typedef int element;

typedef struct{
	element data[MAX];
	int top;
} Stack;

void initStack(Stack* s){
	s->top = -1;
} // made by wwwxsv19
int isEmpty(Stack* s){
	return s->top == -1; 
}
int isFull(Stack* s){
	return s->top == MAX-1;
}

void push(Stack* s, element c){
	if(!isFull(s)){
		s->data[++s->top] = c;
	}
}

element pop(Stack* s ){
	if(!isEmpty(s)){
		return s->data[s->top--]; // made by wwwxsv19
	}
}

int main(){
	int n, m;
	char a, expr[MAX];
	Stack s;
	
	initStack(&s);
	
	fgets(expr, MAX, stdin);
	
	for(int i=0; expr[i]!='\0'; i++){
		a = expr[i];
		if(a != ' ' && a >= '1' && a <= '9') push(&s, a-'0'); 
		else if( a == '+' || a == '-' || a == '*'){
			n = pop(&s); 
			m = pop(&s);
			switch(a){
				case '+': push(&s, n+m); break;
				case '-': push(&s, m-n); break;
				case '*': push(&s, n*m); break;
			}
		} // made by wwwxsv19
	}
	
	printf("%d", pop(&s));
	
	return 0;
}