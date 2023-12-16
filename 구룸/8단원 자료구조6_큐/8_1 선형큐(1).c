#include <stdio.h>
#include <stdlib.h>

#define MAX 5

typedef int element;

typedef struct Queue{
	int front, rear;
	element data[MAX];
} Queue;

void error(char* msg){
	printf("%s\n", msg);
	exit(0); // main 종료
}

void initQueue(Queue* q){
	q->front = q->rear = -1;
}
int isEmpty(Queue* q){
	return q->rear == q->front;
}
int isFull(Queue* q){
	return q->rear == MAX - 1;
}

void enQueue(Queue* q, element item){
	if(isFull(q)) 
		error("Queue Overflow!");
	q->data[++q->rear] = item;
}

element deQueue(Queue* q){ // made by wwwxsv19
	if(isEmpty(q)) 
		error("Queue Underflow!");
	return q->data[++q->front];
}

void printQueue(Queue* q){
	for(int i=0; i<MAX; i++){
		if(i <= q->front || i > q->rear){
			printf(" | ");
		}
		else{
			printf("%d | ", q->data[i]);
		}
	}
	printf("\n");
}

int main() {
	element item = 0;
	Queue q;
	
	initQueue(&q); // made by wwwxsv19
	
	enQueue(&q, 10); printQueue(&q);
	enQueue(&q, 20); printQueue(&q);
	enQueue(&q, 30); printQueue(&q);
	enQueue(&q, 40); printQueue(&q);
	enQueue(&q, 50); printQueue(&q);
	enQueue(&q, 60); printQueue(&q);
	
	printf("꺼낸 값 : %d\n", deQueue(&q)); printQueue(&q);
	printf("꺼낸 값 : %d\n", deQueue(&q)); printQueue(&q);
	printf("꺼낸 값 : %d\n", deQueue(&q)); printQueue(&q);
	printf("꺼낸 값 : %d\n", deQueue(&q)); printQueue(&q);
	
	return 0;
}