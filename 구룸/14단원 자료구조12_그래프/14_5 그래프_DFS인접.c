#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTEX 30

typedef struct graphType{ // made by wwwxsv19
	int n;
	int adjMatrix[MAX_VERTEX][MAX_VERTEX];	
} graphType;

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
} // made by wwwxsv19

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

void dfsList(graphType* g, int v){ // made by wwwxsv19
	visited[v] = 1;
	printf("정점 %d-> ", v);
	
	for(int i=0; i<g->n; i++){
		if(g->adjMatrix[v][i] == 1 && visited[i] == 0){
			dfsList(g, i);
		}
	}
}

int main(){
	graphType *G = (graphType*)malloc(sizeof(graphType));

	createGraph(G); 
	
	for(int i=0; i<4; i++){
		insertVertex(G, i);
	}
	
	insertEdge(G, 0, 1);
	insertEdge(G, 0, 2);
	insertEdge(G, 0, 3);
	insertEdge(G, 1, 2);
	insertEdge(G, 2, 3);
	
	dfsList(G, 0);
	
	free(G);
	
	return 0;
} // made by wwwxsv19