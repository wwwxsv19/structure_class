#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTEX 30

#define QSIZE 10

#define TRUE 1
#define FALSE 0

typedef int element;

typedef struct Qtype{
	element queue[QSIZE];
		int front, rear;
} Qtype;

typedef struct graphType{
	int n;
	int adjMatrix[MAX_VERTEX][MAX_VERTEX];	
} graphType;

Qtype* createQueue(){
	Qtype* q = (Qtype*)malloc(sizeof(Qtype));
	q->front = q->rear = 0; 
	return q;
}
void queue_init(Qtype* q){
	q->front = q->rear = 0;
}
int isEmpty(Qtype* q){
	return (q->front == q->rear);
}
int isFull(Qtype* q){
	return ((q->rear + 1) % QSIZE  == q->front);
} 
void enqueue(Qtype* q, element item){
	if(isFull(q)){
		printf("큐가 포화상태입니다.\n");
	} 
	q->rear = (q->rear + 1) % QSIZE;
	q->queue[q->rear] = item; 
}
element dequeue(Qtype* q){
	if(isEmpty(q)) return 0;
	q->front = (q->front + 1) % QSIZE;
	return q->queue[q->front];
}

///////////////////////////////////////////////////

void createGraph(graphType* g){
	for(int i=0; i<MAX_VERTEX; i++) {	
		for(int j=0; j<MAX_VERTEX; j++){
			g->adjMatrix[i][j] = 0;
		}
	}
}

void insertVertex(graphType* g, int v){
	if(((g->n) + 1) > MAX_VERTEX){
		printf("\n 그래프 정점의 개수를 초과하였습니다!");
		return;
	}
	g->n++;	
}

void insertEdge(graphType* g, int u, int v){	
	if(u >= g->n || v >= g->n){
		printf("\n 그래프에 없는 정점입니다!");
		return;
	}
	g->adjMatrix[u][v] = 1;
	g->adjMatrix[v][u] = 1;
}

void print_adjMatrix(graphType* g){
	for(int i=0; i<g->n; i++){
		printf("\n\t\t");
		for(int j=0; j<g->n; j++)
			printf("%2d", g->adjMatrix[i][j]);
	}
}

int visited[MAX_VERTEX];

void bfsList(graphType* g, int v){
	Qtype q;
	queue_init(&q);
	
	visited[v] = 1;
	printf("%d 방문 -> ", v);
	enqueue(&q, v);
	
	while(!isEmpty(&q)){
		v = dequeue(&q);
		for(int w=0; w<g->n; w++){
			if(g->adjMatrix[v][w] && !visited[w]){
				visited[w] = TRUE;
				printf("%d 방문->", w);
				enqueue(&q, w);
			}
		}
	}
}

int main(){
	graphType *G = (graphType*)malloc(sizeof(graphType));

	createGraph(G); 
	
	for(int i=0; i<6; i++){
		insertVertex(G, i);
	}
	
	insertEdge(G, 0, 2);
	insertEdge(G, 2, 1);
	insertEdge(G, 2, 3);
	insertEdge(G, 0, 4);
	insertEdge(G, 4, 5);
	insertEdge(G, 1, 5);
	
	printf("너비 우선탬색 \n");
    /* 참고! 
    위 코드는 (희) 쌤 구룸 기준이며,

    (희) 쌤 구룸 기준:
    123번 줄에 "너비 우선'탬'색 \n"
    
    (승) 쌤 구룸 기준:
    123번 줄에 "너비 우선'탐'색\n"
    
    두 분의 테스트케이스가 다르므로 참고할 것~
    */ 
	bfsList(G, 0);
	
	free(G);
	
	return 0;
}