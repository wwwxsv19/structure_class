#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    int data;
    struct Node* next;
} Node;

void printList(Node* head){
    Node* p = head;
    while(p != NULL){
        printf("%d", p->data);
        p = p->next;
        if(p != NULL) printf("->");
    }
    printf("\n");
}

Node* reverse(Node* head){
    Node* p = head; // made by wwwxsv19
    Node* q = NULL; 
    Node* r;

    while(p != NULL){
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }

    return q;
}

Node* insertFirst(Node* head, int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data; // made by wwwxsv19
    newNode->next = head;
    return newNode;
}

int main(){
    Node* head = NULL;
    for(int i=10; i<=50; i+=10){
        head = insertFirst(head, i);
        printList(head);
    }
    head = reverse(head);
    printf("역순으로 출력\n");
    printList(head);

    return 0; // made by wwwxsv19
}