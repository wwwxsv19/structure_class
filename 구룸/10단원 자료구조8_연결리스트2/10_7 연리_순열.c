#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct Node{
    element data;
    struct Node* next;
} Node;

Node* insert(Node* head, element data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    if(head == NULL){ // made by wwwxsv19
        newNode->next = newNode;
        head = newNode;
    }
    else{
        newNode->next = head->next;
        head->next = newNode;
        head = newNode;
    }
    return head;
}

void delete(Node* head, int count){
    Node* p = head;
    Node* removed = p;
    printf("<"); // made by wwwxsv19
    while(p->next != p){
        for(int i=0; i<count-1; i++){
            p = p->next;
        }
        removed = p->next;
        p->next = removed->next;
        printf("%d, ", removed->data);
        free(removed);
    }
    printf("%d>", p->data);
    free(p);
    return ;
}

int main() {
	Node* head = NULL; // made by wwwxsv19
	
    int n, count;
    scanf("%d %d", &n, &count);

	for(int i=1; i<=n; i++){
		head = insert(head, i);
	}

	delete(head, count);

    return 0;
}