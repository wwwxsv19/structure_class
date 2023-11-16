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

void error(char* message){
    fprintf(stderr, "%s\n", message);
    exit(1);
}

void initQueue(Queue* q){
    q->front = 0;
    q->rear = 0;
}

int isEmpty(Queue* q){
    return q->rear == q->front;     
}

int isFull(Queue* q){
    return (q->rear + 1) % MAX_QUEUE_SIZE == q->front;
}

void enQueue(Queue* q, element data){
    if(isFull(q)){
        error("Queue is overflow!\n");
        return ;
    }
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    q->data[q->rear] = data;
}

element deQueue(Queue* q){
    if(isEmpty(q)){
        error("Queue is underflow!\n");
        exit(1);
    }
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    return q->data[q->front];
}

void level_order(TNode* ptr){
    Queue q;
    initQueue(&q);

    if(ptr == NULL) return;
    enQueue(&q, ptr);

    while(!isEmpty(&q)){
        TNode* temp = deQueue(&q);
        printf(" [%d] ", temp->data);
        if(temp->left != NULL){
            enQueue(&q, temp->left);
        } // made by wwwxsv19
        if(temp->right != NULL){
            enQueue(&q, temp->right);
        }
    }
}

TNode n1 = {1, NULL, NULL};
TNode n2 = {4, &n1, NULL};
TNode n3 = {16, NULL, NULL};
TNode n4 = {25, NULL, NULL};
TNode n5 = {20, &n3, &n4};
TNode n6 = {15, &n2, &n5};
TNode* root = &n6;

int main(){
    printf("레벨 순회 = ");
    level_order(root);
    printf("\n");

    return 0;
}