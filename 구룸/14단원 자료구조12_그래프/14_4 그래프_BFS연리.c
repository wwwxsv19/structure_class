#include <stdio.h>
#include <stdlib.h> 

#define MAX_VERTICES 50

#define QSIZE 10

#define TRUE 1
#define FALSE 0

typedef int element;

typedef struct Qtype{
	element queue[QSIZE];
	int front, rear; // made by wwwxsv19
} Qtype;

typedef struct GraphNode{
	int vertax;
	struct GraphNode* link;
} GraphNode;

typedef struct GraphType{
	int n;
	GraphNode* adj_list[MAX_VERTICES];
} GraphType;

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
} // made by wwwxsv19
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

void graph_init(GraphType* g){
	g->n = 0;  
	for(int v=0; v<MAX_VERTICES; v++){
		g->adj_list[v] = NULL;	
	}
} 

void insert_vertax(GraphType* g, int v){
	if(g->n + 1 > MAX_VERTICES){
		printf("그래프: 정점의 개수 초과\n");
		return; 
	}
	g->n++;
} 

void insert_edge(GraphType* g, int u, int v){
	if(u >= g->n || v >= g->n){ // made by wwwxsv19
		printf("그래프: 정점번호 오류");
		return; 
	}
	GraphNode* Node = (GraphNode*)malloc(sizeof(GraphNode));
	Node->vertax = v;
	Node->link = NULL;
	if (g->adj_list[u] == NULL){
		g->adj_list[u] = Node;
	} else{
		GraphNode* p;
		for(p = g->adj_list[u]; p->link != NULL; p=p->link);
			p->link = Node;
	}
}

void print_adj_list(GraphType* g){
	for(int i=0; i<g->n; i++){
		GraphNode* p = g->adj_list[i]; 
		printf("정점 %d의 인접리스트", i);
		for( ; p!=NULL; p=p->link){
			printf("->%d",p->vertax);
		}
		printf("\n"); // made by wwwxsv19
	}
}

int visited[MAX_VERTICES];

void bfsMatrix(GraphType* g, int v){
	GraphNode* w;
	Qtype q;
	queue_init(&q);
	visited[v] = TRUE; 
	printf("%C 방문 -> ", v + 'A');
	enqueue(&q, v);
	while(!isEmpty(&q)){
		v = dequeue(&q);
		for(w=g->adj_list[v]; w!=NULL; w=w->link){
			if(visited[w->vertax] == 0){  
				visited[w->vertax] = TRUE; 
				printf("%C 방문->", w->vertax + 'A');
				enqueue(&q, w->vertax);
			}
		}
	}
}

int main(){
	GraphType* g = (GraphType*)malloc(sizeof(GraphType));
	graph_init(g);
	
	for(int i=0; i<6; i++){ // made by wwwxsv19 
		insert_vertax(g,i);
	}
	
	insert_edge(g, 0, 2);	insert_edge(g, 0, 4);	
	insert_edge(g, 1, 2); insert_edge(g, 1, 5);
	insert_edge(g, 2, 1); insert_edge(g, 2, 3);	
	insert_edge(g, 2, 4); 
	insert_edge(g, 3, 2);	insert_edge(g, 3, 5);	
	insert_edge(g, 4, 0);	insert_edge(g, 4, 5);
	insert_edge(g, 5, 1);	insert_edge(g, 5, 2);
	insert_edge(g, 5, 3);	insert_edge(g, 5, 4);
	
	printf("너비 우선탬색 \n");
    /* 참고! 
    위 코드는 (희) 쌤 구룸 기준이며,

    (희) 쌤 구룸 기준:
    114번 줄에 '"%c 방문->"', 138번 줄에 우선'탬'색
    
    (승) 쌤 구룸 기준:
    114번 줄에 '"%c 방문-> "', 138번 줄에 우선'탐'색
    
    두 분의 테스트케이스가 다르므로 참고할 것~
    */ 
	bfsMatrix(g,0);
	printf("\n");
	
	free(g);	
	
	return 0; // made by wwwxsv19
}