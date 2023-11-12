#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct Node{
    element data; // made by wwwxsv19
    struct Node* next;
} Node;

void printList(Node* head){
    Node* p = head->next; // 현재 head 가 맨 마지막 노드를 가리키므로!
    int cnt = 0;

    if(head == NULL) return ;
    do{
        if(p == NULL) break;
        printf("%d->", p->data);
        p = p->next;
        cnt++;
    } while(cnt < 10);
    printf("\n");
}

Node* insertFirst(Node* head, element data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    if(head == NULL){
        newNode->next = newNode;
        head = newNode;
    }
    else{
        newNode->next = head->next;
        head->next = newNode;
    }
    return head; // made by wwwxsv19
}

Node* insertLast(Node* head, element data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    if(head == NULL){
        newNode->next = newNode;
        head = newNode;
    }
    else{
        newNode->next = head->next;
        head->next = newNode;
        head = newNode;
    }
    return head;
}

int main() {
	Node* head = NULL;
	
    printf("처음위치에 연결\n");
	// made by wwwxsv19
    for(int i=1; i<5; i++){
		head = insertFirst(head, i);
	}
	printList(head);

	printf("마지막위치에 연결\n");
	for(int i=11; i<15; i++){
		head = insertLast(head, i);	
	}
	printList(head);

	return 0;
}