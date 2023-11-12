#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    char data[100];
    struct Node* next;
} Node;

Node* insertFirst(Node* head, char* data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->data, data);
    newNode->next = head;
    return newNode;
}

Node* insert(Node* head, Node* pre, char* data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->data, data);
    newNode->next = pre->next;
    pre->next = newNode;
    return head;
}

Node* deleteFirst(Node* head){
    if(head == NULL) return NULL;
    Node* removed = head;
    Node* newHead = head->next;
    free(removed); // made by wwwxsv19
    return newHead;
}

Node* delete(Node* head, Node* pre){
    Node* removed = pre->next;
    pre->next = removed->next;
    free(removed);
    return head;
}

void printList(Node* head){
    while(head != NULL){
        printf("%s->", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main(){ // made by wwwxsv19
    Node* head = NULL;
    Node* p;

    char str[3][10] = {"melon", "kiwi", "apple"};
    char find[10];

    head = insertFirst(head, str[0]);
    printList(head);

    head = insertFirst(head, str[1]);
    printList(head);

    head = insertFirst(head, str[2]); // made by wwwxsv19
    printList(head);

    printf("찾을 데이터를 입력하세요\n");
    scanf("%s", find);
    for(p=head; p!=NULL; p=p->next){
        if(strcmp(p->data, find) == 0){
            printf("%s을 찾았습니다.", find);
        }
    }

    return 0;
}