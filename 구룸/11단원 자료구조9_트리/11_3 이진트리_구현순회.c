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

void init_queue(Queue* q){
    q->front = NULL;
    q->rear = NULL;
}

int isEmpty(Queue* q){
    return q->front == NULL;
}

int isFull(Queue* q){
    // 이 코드가 맞나?? 확인해볼필요200%
    return (q->rear + 1) % MAX_QUEUE_SIZE == q->front; 
}