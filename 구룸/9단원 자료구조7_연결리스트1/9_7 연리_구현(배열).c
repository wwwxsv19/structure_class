#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef int element;

typedef struct ArrayList{
    element array[MAX];
    int size;
} AL; // made by wwwxsv19


void init(AL* L){
    L->size = 0;
}
int isEmpty(AL* L){
    return L->size == 0;
}
int isFull(AL* L){
    return L->size == MAX;
}

element getEntry(AL* L, int pos){
    if(pos < 0 || pos >= L->size){
        printf("error\n");
        exit(1);
    }
    return L->array[pos];
}

void printList(AL* L){
    for(int i=0; i<L->size; i++){
        printf("%d->", L->array[i]);
    } // made by wwwxsv19
    printf("\n");
}

void insertLast(AL* L, element item){
    if(L->size >= MAX){
        printf("overflow!\n");
        exit(1);
    }
    L->array[L->size++] = item;
}

void insert(AL* L, int pos, element item){
    if(!isFull(L) && (pos >= 0 && pos <= L->size)){
        for(int i=L->size-1; i>=pos; i--){
            L->array[i+1] = L->array[i];
        }
        L->array[pos] = item; // made by wwwxsv19
        L->size++;
    }
}

void delete(AL* L, int pos){
    if(pos < 0 || pos >= MAX){
        printf("error\n");
        exit(1);
    }
    for(int i=pos; i<L->size; i++){
        L->array[i] = L->array[i+1];
    }
    L->size--;
}
// made by wwwxsv19
int main(){
    AL list;

    init(&list);

    insert(&list, 0, 10); printList(&list);
    insertLast(&list, 20); printList(&list);
    insertLast(&list, 30); printList(&list);
    insertLast(&list, 40); printList(&list);
    insert(&list, 2, 100); printList(&list);
    delete(&list, 1); printList(&list);
    
    return 0;
}