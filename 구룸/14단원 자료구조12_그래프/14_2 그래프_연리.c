#include <stdio.h>
#include <stdlib.h>

#define MAX 30

typedef struct GraphNode{
	int vertex;
	struct GraphNode* link;
} GraphNode;
// made by wwwxsv19
typedef struct GraphType{
	int n;
	GraphNode* adjList[MAX];
} GraphType;

void createGraph(GraphType* g){
	int v;
	g->n = 0;
	for(v=0; v<MAX; v++){
		g->adjList[v] = NULL;
	}
}

void insertVertex(GraphType* g, int v)
{
	if(((g->n)+1) > MAX){
		printf("\n 그래프 정점의 개수를 초과하였습니다!");
		return;
	}
	g->n++;
} // made by wwwxsv19

void insertEdge(GraphType* g, int u, int v){
	GraphNode* newNode;
	if(u >= g->n || v >= g->n){
		printf("\n 그래프에 없는 정점입니다!");
		return ;
	}
	newNode = (GraphNode*)malloc(sizeof(GraphNode));
	newNode->vertex = v;
	newNode->link = g->adjList[u];
	g->adjList[u] = newNode; // made by wwwxsv19
}

void print_adjList(GraphType* g){
	GraphNode* p;
	for(int i=0; i<g->n; i++){
		printf("\n정점 %C의 인접리스트 ", i+65);
		p = g->adjList[i];
		while(p != NULL){
			printf(" -> %c", p->vertex + 'A');
			p = p->link;
		}
	}
}

int main(){
	GraphType* G;
	G = (GraphType*)malloc(sizeof(GraphType));
	createGraph(G); 
	
	for(int i=0; i<4; i++)
		insertVertex(G, i);
	insertEdge(G, 0, 1);
	insertEdge(G, 1, 3);
	insertEdge(G, 1, 2);
	insertEdge(G, 1, 0);
	insertEdge(G, 2, 3);
	insertEdge(G, 2, 1);
	insertEdge(G, 3, 2);
	insertEdge(G, 3, 1);
	
	printf("<G의 인접 리스트>");
	print_adjList(G);
	// made by wwwxsv19	
    return 0;
} 