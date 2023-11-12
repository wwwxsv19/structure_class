#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct TNode{
	char data; // made by wwwxsv19
	struct TNode* left;
	struct TNode* right;
} TNode;

TNode* makeRootNode(char data, TNode* leftNode, TNode* rightNode){
	TNode* root = (TNode*)malloc(sizeof(TNode));
	root->data = data;
	root->left = leftNode;
	root->right = rightNode;
	return root;
}

void preorder(TNode* root){
	TNode* x = root;
	if(x == NULL) return ; // made by wwwxsv19
	printf("%c", x->data);
	preorder(x->left);
	preorder(x->right);
}

void inorder(TNode* root){
	TNode* x = root;
	if(x == NULL) return ;
	inorder(x->left);
	printf("%c", x->data); // made by wwwxsv19
	inorder(x->right);
}

void postorder(TNode* root){
	TNode* x = root;
	if(x == NULL) return ;
	postorder(x->left);
	postorder(x->right);
	printf("%c", x->data);
}

int main(){
	TNode* n7 = makeRootNode('D', NULL, NULL);
	TNode* n6 = makeRootNode('C', NULL, NULL);
	TNode* n5 = makeRootNode('B', NULL, NULL);
	TNode* n4 = makeRootNode('A', NULL, NULL);
	TNode* n3 = makeRootNode('/', n6, n7);
	TNode* n2 = makeRootNode('*', n4, n5);
	TNode* n1 = makeRootNode('-', n2, n3);

	printf("\n preorder  : ");
	preorder(n1);
	
	printf("\n inorder   : ");
	inorder(n1);
	
	printf("\n postorder : ");
	postorder(n1);
	
	free(n1); free(n2); free(n3);
	free(n4); free(n5); free(n6);
	free(n7); 
	
	return 0;
}