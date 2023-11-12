#include <stdio.h>
#include <stdlib.h>

typedef int element;
// made by wwwxsv19
typedef struct Node{
	element data;
	struct Node* next;
} Node;

void init(Node* top){
	top->next = NULL;
}

int isEmpty(Node* top){
	return top->next == NULL;
}

void push(Node* top, element data){
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data; // made by wwwxsv19
	node->next = top->next;
	top->next = node;
}

void pop(Node* top){
	element data;
	Node* temp;

	if(isEmpty(top->next)){
		top->next = NULL;
		return ;
	} // made by wwwxsv19
	else{
		temp = top->next;
		top->next = temp->next;
		free(temp);
	}
}

void printList(Node* top){
	Node* p = top->next;
	
	while(p != NULL){
		printf("%d->", p->data);
		p = p->next;
	} // made by wwwxsv19
	printf("NULL\n");
}

int main() {
	Node top;

	init(&top);
	
	push(&top,1); printList(&top);
	push(&top,2); printList(&top);
	push(&top,3); printList(&top);
	
	pop(&top); printList(&top);
	pop(&top); printList(&top);
	pop(&top); printList(&top);
	
	return 0;
}