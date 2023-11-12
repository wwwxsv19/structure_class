#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct DNode{ // made by wwwxsv19
    element data;
    struct DNode* prev;
    struct DNode* next;
} DNode;

void init(DNode* phead){
    phead->next = phead;
    phead->prev = phead;
}

void dinsert(DNode* before, element data){
    DNode* newNode = (DNode*)malloc(sizeof(DNode));
    newNode->data = data;

    newNode->prev = before;
    newNode->next = before->next;
    before->next->prev = newNode; // made by wwwxsv19
    before->next = newNode;
}

void ddelete(DNode* head, DNode* removed){
    if(removed == head) return ;
    removed->prev->next = removed->next;
    removed->next->prev = removed->prev;
    free(removed);
}

void printDlist(DNode* phead){
    DNode* p;
    for(p = phead->next; p != phead; p=p->next){ // made by wwwxsv19
        printf("<-| |%d| |->", p->data);
    }
    printf("\n");
}

int main(){
	DNode* head = (DNode*)malloc(sizeof(DNode)); 
	
    init(head);
	
    printf("추가단계\n");
	for(int i=0; i<5; i++){ // made by wwwxsv19
		dinsert(head, i);
		printDlist(head);
	}

	printf("삭제단계\n");
	for(int i=0; i<5; i++){
		printDlist(head);
		ddelete(head, head->next);
	}
	free(head);

	return 0;
}