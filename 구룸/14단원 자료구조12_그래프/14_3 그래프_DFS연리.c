#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 50

#define TRUE 1
#define FALSE 0

typedef struct GraphNode{
	int vertex;
	struct GraphNode* link;
} GraphNode;

typedef struct GraphType{
	int n; 
	GraphNode* adj_list[MAX_VERTICES];
} GraphType; 

void init(GraphType* g){
	g->n = 0; 
	for(int v=0; v < MAX_VERTICES; v++){
		g->adj_list[v] = NULL;	
	}
}

void insert_vertex(GraphType* g, int v){ 
	if((g->n) + 1 > MAX_VERTICES){
		printf("그래프: 정점의 개수 초과");
		return ; 
	}
	g->n++;
} 

void insert_edge(GraphType* g, int u, int v){
	GraphNode* Node;
	GraphNode* p;
	if(u >= g->n || v >= g->n){
		printf("그래프: 정점번호 오류");
		return; 
	}
	Node = (GraphNode*)malloc(sizeof(GraphNode));
	Node->vertex = v;
	if(g->adj_list[u] == NULL){
		Node->link = g->adj_list[u]; 
		g->adj_list[u] = Node; 
	} else{
		for(p = g->adj_list[u]; p->link != NULL; p = p->link);	
		p->link = Node;
		Node->link = NULL;
	}
}

void print_adj_list(GraphType* g){
	GraphNode* p;
	for(int i=0; i < g->n; i++){ 
		printf("정점 %d의 인접리스트",i);
		for(p = g->adj_list[i]; p != NULL; p = p->link){
			printf("->%d",p->vertex);
		}
		printf("\n");
	}
}

int visited[MAX_VERTICES];

void dfsList(GraphType* g, int v){
	GraphNode* w;
	visited[v] = TRUE;
	printf("정점 %d-> ", v);
	for(w = g->adj_list[v]; w != NULL; w = w->link){
		if(visited[w->vertex] == 0) dfsList(g, w->vertex);
	}
}

int main(){
	GraphType* g = (GraphType*)malloc(sizeof(GraphType));
	init(g);
	
	for(int i=0; i<5; i++){
		insert_vertex(g, i);
	}
	
	insert_edge(g, 0, 1);	insert_edge(g, 0, 2);
	insert_edge(g, 0, 4);	insert_edge(g, 1, 0);
	insert_edge(g, 1, 2); insert_edge(g, 2, 0);
	insert_edge(g, 2, 1); insert_edge(g, 2, 3);	
	insert_edge(g, 2, 4); insert_edge(g, 3, 2);
	insert_edge(g, 3, 4);	insert_edge(g, 4, 0);	
	insert_edge(g, 4, 2);	insert_edge(g, 4, 3);	
	
	int n;
	printf("깊이 우선탐색 시작 정점 입력 \n");
	scanf("%d", &n);
	dfsList(g, n);
	
	free(g);
	
	return 0;
}