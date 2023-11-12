#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct DNode{
    element index; 
    element data;
    struct DNode* prev;
    struct DNode* next; // made by wwwxsv19
} DNode;

typedef struct Head{
    element size; // 풍선의 개수
    struct DNode* link;
} Head;

void insertLast(Head* phead, element data){
    DNode* head = phead->link;
    DNode* newNode = (DNode*)malloc(sizeof(DNode));
    newNode->data = data;
    newNode->index = phead->size + 1;

    if(head == NULL){
        phead->link = newNode;
        newNode->prev = newNode;
        newNode->next = newNode;
    }
    else{
        newNode->prev = head->prev;
        newNode->next = head;
        head->prev->next = newNode;
        head->prev = newNode;
    }
    phead->size++;
}

void deleteNode(Head* phead){
    int index = phead->link->index;
    int count = phead->link->data;

    printf("%d ", index);

    if(phead->size == 1){
        phead->size--; // made by wwwxsv19
        return ;
    }

    DNode* removed = (DNode*)malloc(sizeof(DNode));
    removed = phead->link;

	if(count > 0){ 
		for(int i=0; i<count; i++){
			phead->link = phead->link->next;
			if (phead->link == removed){
				phead->link = phead->link->next; // made by wwwxsv19
			}
		}
	}
	else{
		for(int i=0; i<count * (-1); i++){
			phead->link = phead->link->prev;
			if(phead->link == removed){
				phead->link = phead->link->prev;
			}
		}
	}
	removed->prev->next = removed->next;
	removed->next->prev = removed->prev;  
    
    free(removed);
	phead->size--;
}

void printList(Head* phead){
    DNode* p = phead->link;
    do{
        printf("[%d] ->", p->data); // made by wwwxsv19
        p = p->next;
    } while(p != phead->link);
}

int main(){
	Head* head = (Head*)malloc(sizeof(Head));
	head->link = NULL; head->size = 0;

    int size; // 연결 리스트 사이즈
	scanf("%d", &size);

    int num; // 풍선 노드의 값 입력
	for(int i=0; i<size; i++){
		scanf("%d", &num);
        insertLast(head, num); // made by wwwxsv19
	}

    for(int i=0; i<size; i++){
		deleteNode(head);
	}

	free(head->link);
	free(head);
    
    return 0;
}