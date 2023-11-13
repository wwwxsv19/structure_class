#include <stdio.h>
#include <stdlib.h>

typedef struct TNode{
    int data;
    struct TNode* left;
    struct TNode* right;
} TNode; // made by wwwxsv19

TNode n1 = {1, NULL, NULL};
TNode n2 = {4, NULL, NULL};
TNode n3 = {'*', &n1, &n2};
TNode n4 = {16, NULL, NULL};
TNode n5 = {25, NULL, NULL};
TNode n6 = {'+', &n4, &n5}; // made by wwwxsv19
TNode n7 = {'+', &n3, &n6};
TNode* root = &n7;

int evaluate(TNode* root){
    if(root == NULL) return 0;

    TNode* x = root;
    if(x->left == NULL || x->right == NULL) return x->data;

    int op1 = evaluate(x->left);
    int op2 = evaluate(x->right);

    printf("%d %c %d을 계산합니다.\n", op1, root->data, op2);
    switch(root->data){
        case '+': return op1 + op2; break; // made by wwwxsv19
        case '*': return op1 * op2; break;
    }
}

int main(){
    printf("수식의 값은 %d입니다. \n", evaluate(root));
    
    return 0;
}