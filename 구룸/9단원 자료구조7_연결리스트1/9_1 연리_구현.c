// 동적으로 구조체 생성하기

#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct NODE{ // made by wwwxsv19
	element data;
	struct Node* link;
} Node;

int main(){
	Node *n1, *n2 ,*n3, *head;

	n1 = (Node*)malloc(sizeof(Node));
	n2 = (Node*)malloc(sizeof(Node));
	n3 = (Node*)malloc(sizeof(Node));
	
	n1->data = 10;
	n1->link = n2;
	
	n2->data = 20;
	n2->link = n3;
	
	n3->data = 30;
	n3->link = NULL;
	
	head = n1; // made by wwwxsv19
	
	while(head){
		printf("%d->", head->data);
		head = head->link;
	}

	return 0;
}