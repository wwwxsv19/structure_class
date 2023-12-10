/* 프로젝트 설명

1. 주제 :
오늘 처음 카페 알바를 시작한 김소마!
주문을 받고 음료를 만드는 데에 서툴러서 원형 큐 자료구조의 도움을 받으려 한다.
김소마가 주문을 받고 처리하는 과정을 원형 큐로 알아보자.

2. 이용한 자료 구조 : 연결리스트

3. 기능설명 : while 문으로 주문을 받거나(enqueue) 주문을 완료하고(dequeue) 
주문이 너무 많을 경우 바쁜 부소마가 주문을 받지 못할 수도 있다(isFull)

코드 오류가 너무 심함!! ㅠㅠ
입력이 이상하게 들어가는 걸 어떻게 바꿔야 하는데...

*/

#include <stdio.h>
#include <stdlib.h> // made by wwwxsv19

#define MAX 8

typedef struct element{
	char menu[10];
	int price;
} element;

typedef struct Queue{
	element order[MAX];
	int front, rear;
} Queue;

element Null = {"", 0};

void initQueue(Queue* q){
	q->front = q->rear = 0;
}
int isFull(Queue* q){
	return (q->rear + 1) % MAX == q->front;
}
int isEmpty(Queue* q){ // made by wwwxsv19
	return q->rear == q->front;
}
void enQueue(Queue* q, element item){
	if(isFull(q)){
		printf("Overflow!\n");
		return ;
	}
	q->rear = (q->rear + 1) % MAX;
	q->order[q->rear] = item;
}
element deQueue(Queue* q){
	if(isEmpty(q)){
		printf("Underflow!\n");
		return Null;
	} else{
		q->front = (q->front + 1) % MAX;
		element temp = q->order[q->front];
		q->order[q->front] = Null;
		return temp;
	}
}
void printQueue(Queue* q){
	for(int i = q->front + 1; i <= q->rear; i++){
		if(q->order[i].price == Null.price) printf("NULL | ");
		else printf("%s(%d원) | ", q->order[i].menu, q->order[i].price);
	} // made by wwwxsv19
	printf("\n");
}

int main(){
	Queue q;
	initQueue(&q);
	
	element item;
	char c;
	
	do{
		printf("\n**** e: 주문 받기, d: 주문 완료, p: 주문 확인, q: 종료 **** : ");
		c = getchar();
		getchar();
		switch(c){
			case 'e':
				if(!isFull(&q)){
					printf("주문 메뉴 : "); 
					scanf("%s", item.menu); getchar();
					printf("가격 : "); 
					scanf("%d", &item.price); getchar();
					enQueue(&q, item);
				}
				break;
			case 'd':
				item = deQueue(&q);
				if(item.price != Null.price){
					printf("주문하신 메뉴가 나왔습니다! : ");
					printf("%s(%d원)", item.menu, item.price);
				}
				break; 
			case 'p': // made by wwwxsv19
				printf("현재 주문 : ");
				printQueue(&q);
				break;
		}
	} while(c != 'q');
	
	return 0;
}