#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct NODE{
	element data;
	struct Node* next;
} Node;

Node* createNode(element data){
	Node* new;
	new = (Node*)malloc(sizeof(Node));
	new->data = data;
	new->next = NULL;
	return new;
}

void All(Node* ptr){
	while(ptr){
		if(ptr->next){
			printf("%d->", ptr->data);
			ptr = ptr->next;
		}
		else{
			printf("%d", ptr->data);
			return ; // 프린트 종료
		}
	}
}

int main(){
	Node *head, *node1, *node2, *node3;
	
	node1 = createNode(12);
	node2 = createNode(99);
	node3 = createNode(37);
	
	head = node1;

	node1->next = node2;
	node2->next = node3;
	node3->next = NULL;
	
	All(head);
	
	return 0;
}