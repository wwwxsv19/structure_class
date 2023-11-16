#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct TNode{
    element key;
    struct TNode* left;
    struct TNode* right; // made by wwwxsv19
} TNode;

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
    return newNode;
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
    return minNode; // made by wwwxsv19
}

TNode* deleteNode(TNode* root, int key){
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
} // made by wwwxsv19

void inorder(TNode* root){
    if(root == NULL) return ;
    inorder(root->left);
    printf("[%c] ", root->key);
    inorder(root->right);
}

void menu(){
	printf("\n*-----------------------*\n");
	printf("\n\t1 : 트리 출력\n");
	printf("\n\t2 : 문자 삽입\n");
	printf("\n\t3 : 문자 삭제\n");
	printf("\n\t4 : 문자 검색\n");
	printf("\n\t5 : 종료\n");
	printf("\n*-----------------------*\n");
	printf("\n메뉴 입력 >> ");

}

int main() {	 
	TNode* root = NULL;	  
	TNode* foundedNode = NULL; 
	char choice, key;	       

	root = insertNode(root, 'G');
	insertNode(root, 'I');
	insertNode(root, 'H');
	insertNode(root, 'D');
	insertNode(root, 'B');
	insertNode(root, 'M');
	insertNode(root, 'N');
	insertNode(root, 'A');
	insertNode(root, 'J');
	insertNode(root, 'E');
	insertNode(root, 'Q');
	
	while(1){
		menu();
		scanf(" %c", &choice);
		switch(choice - '0'){
			case 1 : printf("\n[이진 트리 출력] ");
				inorder(root);
				printf("\n");
				break; // made by wwwxsv19
			case 2 : printf("삽입할 문자를 입력하세요 : ");
				scanf(" %c", &key);
				foundedNode = search(root, key);
				if(foundedNode != NULL)
					printf("\n이미 같은 키가 있습니다!\n");
				else
					root = insertNode(root, key); 
				break;
			case 3 : printf("삭제할 문자를 입력하세요 : ");
				scanf(" %c", &key);
				foundedNode = search(root, key);
				if(foundedNode == NULL)
					printf("\n찾는 키가 이진 트리에 없습니다!!\n");
				else
					root = deleteNode(root, key);
				break;
			case 4 : printf("찾을 문자를 입력하세요 : ");
				scanf(" %c", &key);
				foundedNode = search(root, key);
				if(foundedNode != NULL)
					printf("\n%c를 찾았습니다!\n", foundedNode->key);
				else printf("\n문자를 찾지 못했습니다.\n");
				break;
			case 5 : return 0;
			default : printf("없는 메뉴입니다. 메뉴를 다시 선택하세요!\n");
				break;
		}
	}
} // made by wwwxsv19