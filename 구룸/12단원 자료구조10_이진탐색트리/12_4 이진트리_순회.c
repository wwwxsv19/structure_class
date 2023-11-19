#include <stdio.h>
#include <stdlib.h>

typedef char element;

typedef struct TNode{
	element data;
	struct TNode* left;
	struct TNode* right;
} TNode;

int main(){
	int n;
	scanf("%d", &n);
	
	char rv, lf, rt;
	for(int i=0; i<n; i++){
		scanf("%c %c %c", &rv, &lf, &rt);
		
	}
	
}