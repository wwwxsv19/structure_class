#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

typedef struct element{
    char word[100];
    char meaning[200]; // made by wwwxsv19
} element;

typedef struct TNode{
    element key;
    struct TNode* left;
    struct TNode* right;
} TNode;

int flag; // compare 의 결과를 저장할 전역 변수 ~ ! >.<

int compare(element e1, element e2){
    return strcmp(e1.word, e2.word);
    /*
    e1 < e2 : -1
    e1 == e2 : 0
    e1 > e2 : 1
    */
}

void display(TNode* p){
    if(!p) return ;
    display(p->left);
    printf("(%s:%s)", p->key.word, p->key.meaning);
    display(p->right);
}

TNode* search(TNode* root, element key){
    if(root == NULL) return NULL; // made by wwwxsv19

    flag = compare(key, root->key);

    if(flag == 0) return root;
    else if(flag < 0) return search(root->left, key);
    else return search(root->right, key);
}

TNode* makeNewNode(element item){
    TNode* newNode = (TNode*)malloc(sizeof(TNode));
    newNode->key  = item;
    newNode->left = newNode->right = NULL;
    return newNode;
}

TNode* insertNode(TNode* root, element key){
    if(root == NULL) return makeNewNode(key);

    flag = compare(key, root->key);
    
    if(flag < 0) root->left = insertNode(root->left, key);
    else if(flag > 0) root->right = insertNode(root->right, key);
    return root;
}
// made by wwwxsv19
TNode* minNode(TNode* root){
    TNode* minNode = root;
    while(minNode->left != NULL){
        minNode = minNode->left;
    }
    return minNode;
}

TNode* deleteNode(TNode* root, element key){
    if(root == NULL) return root;

    flag = compare(key, root->key);
    if(flag < 0) root->left = deleteNode(root->left, key);
    else if(flag > 0) root->right = deleteNode(root->right, key);
    else{
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

int main(){
    char command;
    element e;

    TNode* root = NULL; // made by wwwxsv19
    TNode* temp;

    do{
		printf("\n ****i: 입력, d: 삭제,s: 탐색,p: 출력,q:종료****:");
		command = getchar();
		getchar();
		switch(command){
			case 'i':
				printf("단어:"); fgets(e.word, 100, stdin);
				printf("의미:"); fgets(e.meaning, 200, stdin);
				root = insertNode(root, e);
				break; 
			case 'd':
				printf("단어:"); fgets(e.word, 100, stdin);
				root = deleteNode(root, e);
				break; 
			case 's':
				printf("단어:"); fgets(e.word, 100, stdin);
				temp = search(root, e);
				if(temp != NULL){
					printf("의미: %s\n", temp->key.meaning);
				}
				break;
			case 'p':
				display(root);
				printf("\n");
				break;
		} 
	}while(command != 'q');

	return 0; 
} // made by wwwxsv19