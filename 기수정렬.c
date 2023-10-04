#include <stdio.h>
#include <stdlib.h>

#define QSIZE 100
#define BUCKETS 10
#define DIGITS 3
#define size 10

typedef int element;

typedef struct{
    element data[QSIZE];
    int front, rear;
} QueueType;


void error(char *message){
    fprintf(stderr, "%s\n", message);
    exit(1);
}

void init_queue(QueueType *q){
    q->front = q->rear = 0;
}

int is_empty(QueueType *q){
    return (q->front == q->rear);
}

int is_full(QueueType *q){
    return ((q->rear + 1) % QSIZE == q->front);
}

void enqueue(QueueType *q, element item){
    if(is_full(q)) error("큐가 포화상태입니다.");
    q->rear = (q->rear + 1) % QSIZE;
    q->data[q->rear] = item;
}

element dequeue(QueueType *q){
    if(is_empty(q)) error("큐가 공백상태입니다.");
    q->front = (q->front + 1) % QSIZE;
    return q->data[q->front];
}


void radix_sort(int list[], int n){
    int i, b, d, factor = 1;
    QueueType queues[BUCKETS];

    for(b=0; b<BUCKETS; b++){
        init_queue(&queues[b]);
    }

    for(d=0; d<DIGITS; d++){
        for(i=0; i<n; i++){
            enqueue(&queues[(list[i]/factor)%10], list[i]);
        }
        for(b=i=0; b<BUCKETS; b++){
            while(!is_empty(&queues[b])){
                list[i++] = dequeue(&queues[b]);
            }
        }
        factor *= 10;

        for(int k=0; k<n; k++){
            printf("%d ", list[k]);
        }
        printf("\n");
    }
}

int main(void){
    int list[]={412, 73, 125, 221, 137, 82, 194, 367, 150, 256};
    int n = sizeof(list)/sizeof(int);

    radix_sort(list, n);

    for(int i=0; i<n; i++){
        printf("%d ", list[i]);
    }
    
    return 0;
}