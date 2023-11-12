#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct Node{
    element data;
    struct Node* next;
} Node;

Node* insertFirst(Node* head, element value){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = head;
    return newNode;
}

Node* insert(Node* head, Node* pre, element value){
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->data, value);
    newNode->next = pre->next;
    pre->next = newNode;
    return head;
}

Node* deleteFirst(Node* head){
    if(head == NULL) return NULL;
    Node* removed = head;
    Node* newHead = head->next;
    free(removed);
    return newHead;
}

Node* delete(Node* head, Node* pre){
    Node* removed = pre->next;
    pre->next = removed->next;
    free(removed);
    return head;
}

void printList(Node* head){ // made by wwwxsv19
    while(head != NULL){
        printf("%d->", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int getSum(Node* head){
    int sum = 0;
    while(head != NULL){
        sum += head->data;
        head = head->next;
    }
    return sum;
} // made by wwwxsv19

int main(){
    Node* head = NULL;
    int cnt, data;

    printf("노드의 개수: ");
    scanf("%d", &cnt);

    for(int i=0; i<cnt; i++){
        printf("\n노드 #%d 데이터 : ", i+1);
        scanf("%d", &data);
        head = insertFirst(head, data);
    }
    printf("\n연결 리스트 데이터의 합 : %d \n", getSum(head));

    return 0;
} // made by wwwxsv19