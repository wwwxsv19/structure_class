#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct Node{
    element data;
    struct Node* next;
} Node;

void printList(Node* head){
    Node* p = head->next; // 현재 head 가 맨 마지막 노드를 가리키므로!
    int cnt = 0;

    if(head == NULL) return ;
    do{
        if(p == NULL) break;
        printf("%d->", p->data); // made by wwwxsv19
        p = p->next;
    } while(p != head->next);
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
    return head;
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
        head = newNode; // made by wwwxsv19
    }
    return head;
}

Node* changeCard(Node* head){ // made by wwwxsv19
    Node* removed = head->next;
    head->next = removed->next;
    free(removed);
    return head->next;
}

int main() {
	Node* head = NULL;
	int n;

	printf("카드개수 입력\n");
    scanf("%d",&n);

	for(int i=1; i<=n; i++){ // made by wwwxsv19
		head = insertLast(head, i);
	}

	while(head->next != head){
		head = changeCard(head);
		printList(head);
	}
	printf("마지막 카드번호 : %d", head->data);
	
    return 0;
}