#include <stdio.h>
#include <stdlib.h>
#include <memory.h> // made by wwwxsv19

typedef struct TNode{
    int data;
    struct TNode* left;
    struct TNode* right;
} TNode;

#define MAX_QUEUE_SIZE 100
typedef TNode* element;

typedef struct{
    element data[MAX_QUEUE_SIZE];
    int front, rear;
} Queue; // made by wwwxsv19

void error(char* messange){
    fprintf(stderr, "%s\n", message);
    exit(1);
}

void initQueue(Queue* q){
    q->front = -1;
    q->rear = -1;
}

int isEmpty(Queue* q){
    return q->rear == MAX_QUEUE_SIZE - 1;
}

int isFull(Queue* q){
    // 이 코드가 맞나?? 확인해볼필요200%
    return q->rear == q->front; 
}

void enQueue(Queue* q, element data){
    if(isFull(q)){
        error("Queue is overflow!\n");
        return ;
    }
    q->data[++q->rear] = data;
}

element dequeue(Queue* q){
    /**/
}

void level_order(TNode* ptr){
    Queue q;
    initQueue(&q);

    if(ptr == NULL) return;
    enQueue(q, ptr->data);
}