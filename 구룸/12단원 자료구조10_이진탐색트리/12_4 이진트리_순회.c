#include <stdio.h>
#include <stdlib.h>

typedef char element;

typedef struct TNode{
	element data;
	struct TNode* left;
	struct TNode* right;
} TNode;

TNode* search(TNode* root, int data){
    if(root == NULL) return NULL;

    if(data == root->data) return root;
    else if(data < root->data) return search(root->left, data);
    else return search(root->right, data);
}

TNode* makeNewNode(char rv, char lf, char rt){
    TNode* newNode = (TNode*)malloc(sizeof(TNode));
    newNode->data = item;
    newNode->left = newNode->right = NULL;
    return newNode; // made by wwwxsv19
}

TNode* insertNode(TNode* root, char rvdata, char lfdata, char rtdata){
    if(root == NULL) return root = makeNewNode(rvdata, lfdata, rtdata);
    
    else if(data > root->data) root->right = insertNode(root->right, data);
    return root;
}

TNode* minNode(TNode* root){
    TNode* minNode = root;
    while(minNode->left != NULL){
        minNode = minNode->left;
    }
    return minNode;
}

TNode* deleteNode(TNode* root, int data){ // made by wwwxsv19
    if(root == NULL) return root;

    if(data < root->data) root->left = deleteNode(root->left, data);
    else if(data > root->data) root->right = deleteNode(root->right, data);
    else if(data == root->data){
        if(root->left == NULL){
            TNode* Node = root->right;
            free(root);
            return Node;
        }
        if(root->right == NULL){
            TNode* Node = root->left;
            free(root);
            return Node;
        }
        TNode* newRoot = minNode(root->right);
        root->data = newRoot->data;
        root->right = deleteNode(root->right, newRoot->data);
    }
    return root;
}

void preorder(TNode* root){
    if(root == NULL) return ;
    printf("[%d] ", root->data);
	preorder(root->left);
	preorder(root->right);
}

void inorder(TNode* root){
    if(root == NULL) return ;
    inorder(root->left);
    printf("%c", root->data);
    inorder(root->right);
}

void postorder(TNode* root){
    if(root == NULL) return ;
    postorder(root->left);
    postorder(root->right);
	printf("%c", root->data);
}

int main(){
	TNode* root = NULL;

	int n;
	scanf("%d", &n);
	getchar();
	
	char rv, lf, rt;
	for(int i=0; i<n; i++){
		scanf("%c %c %c", &rv, &lf, &rt);
		root = insertNode(root, rv);
	}
	
	inorder(root);
	
	return 0;
}