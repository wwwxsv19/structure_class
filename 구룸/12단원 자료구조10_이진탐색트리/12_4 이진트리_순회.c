#include <stdio.h>
#include <stdlib.h>

typedef char element;

typedef struct TNode{
	element data;
	struct TNode* left;
	struct TNode* right;
} TNode; // made by wwwxsv19

TNode* search(TNode* root, int data){
    if(root == NULL) return NULL;
    if(data == root->data) return root;
    else{
        TNode* temp = search(root->left, data);
        if(temp != NULL) return temp;
        return search(root->right, data);
    }
}

TNode* makeNewNode(char data){
    TNode* newNode = (TNode*)malloc(sizeof(TNode));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode; // made by wwwxsv19
}

void insertNode(TNode* root, char data, char lf, char rt){
    root->data = data;
    if(lf != '.') root->left = makeNewNode(lf);
    if(rt != '.') root->right = makeNewNode(rt);
}

void preorder(TNode* root){
    if(root == NULL) return ;
    printf("%c", root->data);
	preorder(root->left);
	preorder(root->right);
}

void inorder(TNode* root){
    if(root == NULL) return ;
    inorder(root->left);
    printf("%c", root->data);
    inorder(root->right); // made by wwwxsv19
}

void postorder(TNode* root){
    if(root == NULL) return ;
    postorder(root->left);
    postorder(root->right);
	printf("%c", root->data);
}

int main(){
	TNode* root = makeNewNode(NULL);
    TNode* temp;

	int n;
	scanf("%d", &n);
	getchar();
	
	char data, lf, rt;
	for(int i=0; i<n; i++){
		scanf("%c %c %c", &data, &lf, &rt);
        getchar();
		temp = search(root, data);
        if(temp != NULL) insertNode(temp, data, lf, rt);
        else insertNode(root, data, lf, rt);
	}
	
    preorder(root); printf("\n");
	inorder(root); printf("\n");
    postorder(root);
	
	return 0;
} // made by wwwxsv19