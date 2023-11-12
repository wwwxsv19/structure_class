#include <stdio.h>
#include <stdlib.h>

typedef int element ;

typedef struct {
	element* data; // made by wwwxsv19
	int front;
	int rear;
	int size;
} Queue;

Queue* initQueue(int n){
	Queue *temp = (Queue*)malloc(sizeof(Queue)); 
	temp->size = n; // n을 크기로 하는 큐
	temp->rear = temp->front = -1;
	temp->data = (int*)malloc(sizeof(int) * n); // 크기 n을 가지는 동적 배열 
	
	return temp;
}
int isFull( Queue *q ){
	return q->rear == q->size-1;
}
int isEmpty( Queue *q ){
	return q->rear == q->front;
}

void enQueue( Queue *q, element data ){
	if(isFull(q)){
		printf("Queue is full\n");
		return ; // made by wwwxsv19
	}
	q->data[++q->rear] = data;
}
element deQueue( Queue *q ){
	if(isEmpty(q)){
		printf("Queue is empty\n");\
		return 0;
	}
	return q->data[q->front++];
}
void printAll( Queue *q ){
	int i;
	for(i=0; i<q->size; i++){
		if (i <= q->front || i > q->rear){
			printf(" | ");
		} // made by wwwxsv19
		else{
			printf("%d | ", q->data[i]);
		}
	}
	printf("\n");
}

void destroyQueue( Queue * q ){
	free(q->data);
	free(q);
}

int main() {
	Queue *q;
	element data;

	q = initQueue(5); 
	
	enQueue(q, 10); printAll(q);
	enQueue(q, 20); printAll(q);
	enQueue(q, 30); printAll(q);
	enQueue(q, 40); printAll(q);
	enQueue(q, 50); printAll(q);
	
	data = deQueue(q); printAll(q);
	// made by wwwxsv19
	enQueue(q, data); printAll(q);
	
	destroyQueue( q );
	
	return 0;
}