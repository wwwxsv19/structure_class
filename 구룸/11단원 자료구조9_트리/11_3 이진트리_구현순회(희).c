#include <stdio.h>
#include <stdlib.h>
#include <memory.h> // made by wwwxsv19

typedef struct TNode{
    int data;
    struct TNode* left;
    struct TNode* right;
} TNode;

TNode* makeRootNode(int data, TNode* left, TNode* right){
    TNode* root = (TNode*)malloc(sizeof(TNode));
    root->data = data;
    root->left = left; 
    root->right = right;
    return root;
}

void preorder(TNode* root){ // 전위 순회
    TNode* x = root;
    if(x ==  NULL) return ;
    printf("[%d] ", x->data);
    preorder(x->left);
    preorder(x->right);
}

void inorder(TNode* root){ // 중위 순회
    TNode* x = root;
    if(x ==  NULL) return ;
    inorder(x->left);
    printf("[%d] ", x->data);
    inorder(x->right);
}

void postorder(TNode* root){ // 후위 순회
    TNode* x = root;
    if(x ==  NULL) return ;
    postorder(x->left);
    postorder(x->right);
    printf("[%d] ", x->data);
}

int main(){
    TNode* n1 = makeRootNode(1, NULL, NULL);
    TNode* n2 = makeRootNode(4, n1, NULL);
    TNode* n3 = makeRootNode(16, NULL, NULL);
    TNode* n4 = makeRootNode(25, NULL, NULL);
    TNode* n5 = makeRootNode(20, n3, n4);
    TNode* n6 = makeRootNode(15, n2, n5);
    TNode* root = n6;

    printf("중위 순회=");
    inorder(root);
    printf("\n");
    printf("전위 순회=");
    preorder(root);
    printf("\n");
    printf("후위 순회=");
    postorder(root);
    printf("\n");
    
    free(n1); free(n2); free(n3);
	free(n4); free(n5); free(n6);
	
    return 0;
}