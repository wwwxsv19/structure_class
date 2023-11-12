#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char element;

typedef struct QNode{
    element data;
    struct QNode* link;
} QNode; // made by wwwxsv19

typedef struct QADT{
    QNode* front;
    QNode* rear;
} QList;

QList* createQList(){
    QList* q;
    q = (QList*)malloc(sizeof(QList));
    q->front = NULL;
    q->rear = NULL;
    return q;
}

int isEmpty(QList* q){ // made by wwwxsv19
    if(q->front == NULL){
        // printf("\n Linked Queue is empty! \n");
        return 1;
    }
    return 0;
}

void enQueue(QList* q, element data){
    QNode* newNode = (QNode*)malloc(sizeof(QNode));
    newNode->data = data;
    newNode->link = NULL;

    if(isEmpty(q)){
        q->front = newNode;
        q->rear = newNode;
        return ;
    }
    q->rear->link = newNode; // made by wwwxsv19
    q->rear = newNode;
}

element deQueue(QList* q){
    QNode* removed = q->front;
    element data;
    if(isEmpty(q)) return (element)0;
    data = removed->data;
    q->front = q->front->link;
    if(isEmpty(q)) q->rear = NULL;
    free(removed);
    // made by wwwxsv19
    return data;
}

element peek(QList* q){
    if(isEmpty(q)) return 0;
    return q->front->data;
}

void printList(QList* q){
    QNode* p = q->front;
    printf("\n[");

    while(p != NULL){
        printf(" %c", p->data);
        p = p->link;
    }
    printf(" ]");
}

int main(){
    QList* q = createQList();
    element data;

    enQueue(q, 'A'); printList(q);
	enQueue(q, 'B'); printList(q);
	
    deQueue(q);	printList(q);
	
    enQueue(q, 'C'); printList(q);
	
    data = peek(q);	
    printf("\n peek item : %c", data);
	
    deQueue(q);	printList(q);
	deQueue(q);	printList(q);

	return 0; 
}