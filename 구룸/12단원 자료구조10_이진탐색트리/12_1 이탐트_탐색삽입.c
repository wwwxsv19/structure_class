#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct TNode{
    element key;
    struct TNode* left;
    struct TNode* right;
} TNode; // made by wwwxsv19

TNode* search(TNode* root, int key){
    if(root == NULL) return NULL;

    if(key == root->key) return root;
    else if(key < root->key) return search(root->left, key);
    else return search(root->right, key);
}

TNode* makeNewNode(int item){
    TNode* newNode = (TNode*)malloc(sizeof(TNode));
    newNode->key = item;
    newNode->left = newNode->right = NULL;
    return newNode; // made by wwwxsv19
}

TNode* insertNode(TNode* root, int key){
    if(root == NULL) return makeNewNode(key);
    else if(key < root->key) root->left = insertNode(root->left, key);
    else if(key > root->key) root->right = insertNode(root->right, key);
    return root;
}

TNode* minNode(TNode* root){
    TNode* minNode = root;
    while(minNode->left != NULL){
        minNode = minNode->left;
    }
    return minNode;
}

TNode* deleteNode(TNode* root, int key){ // made by wwwxsv19
    if(root == NULL) return root;

    if(key < root->key) root->left = deleteNode(root->left, key);
    else if(key > root->key) root->right = deleteNode(root->right, key);
    else if(key == root->key){
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
        root->key = newRoot->key;
        root->right = deleteNode(root->right, newRoot->key);
    }
    return root;
}

void inorder(TNode* root){
    if(root == NULL) return ;
    inorder(root->left);
    printf("[%d] ", root->key);
    inorder(root->right);
}

int main(){
    TNode* root = NULL;
    TNode* Node = NULL;

    int key;

    root = insertNode(root, 35);
    root = insertNode(root, 18);
	root = insertNode(root, 68); // made by wwwxsv19
	root = insertNode(root, 7);
	root = insertNode(root, 26);
	root = insertNode(root, 99);
	root = insertNode(root, 3);
	root = insertNode(root, 12);
	root = insertNode(root, 22);
	root = insertNode(root, 30);

    printf("이진탐색트리 중위순회 결과 출력\n");
	inorder(root);
	
    printf("\n삭제할 숫자를 입력하세요\n");
	scanf("%d", &key);
	deleteNode(root, key);

	printf("이진탐색트리 중위순회 결과 출력\n");
	inorder(root);
	
	return 0;
}