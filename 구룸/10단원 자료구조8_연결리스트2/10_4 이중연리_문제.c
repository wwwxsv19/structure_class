#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct DNode{
    element index; // 풍선 터지는 순서
    element data; // 풍선 데이터
    struct DNode* prev;
    struct DNode* next;
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

    

}

void deleteNode(Head* phead){
    
}

void printList(Head* phead){
    
}

int main(){
	Head* head = (Head*)malloc(sizeof(head));
	head->link = NULL; head->size = 0;

    int size; // 연결 리스트 사이즈
	scanf("%d", &size);

    int num; // 풍선 노드의 값 입력
	for(int i=0; i<size; i++){
		scanf("%d", &num);
        insertLast(head, num);
	}

    for(int i=0; i<size; i++){
		deleteNode(head);
	}

	free(head->link);
	free(head);
    
    return 0;
}