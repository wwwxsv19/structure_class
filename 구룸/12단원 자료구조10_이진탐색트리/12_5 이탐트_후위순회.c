#include <stdio.h>
#include <stdlib.h>

int a[1001];
int i;

// 루트 노드의 왼쪽 자식은 루트 노드보다 작은 값, 오른쪽 자식은 루트 노드보다 큰 값임을 이용

void post(int start, int end){
	if(start >= end) return;
	for(i = start+1; i<end; i++){
		if(a[start] < a[i]) break; // for 문으로 현재 루트 노드의 오른쪽 자식을 구분함 ( 루트 노드보다 큰 값 )
	}
	post(start+1, i); 
	// 전위 순회는 루트 왼 오 순이므로 시작은 루트 노드의 바로 왼쪽 자식 값 ( start + 1 ), 끝은 어디까지인지 모르므로 end 
	post(i, end); // 왼쪽을 돌고 나면 i ( 루트 노드의 오른쪽 자식 ), 끝은 이하동문 end
	printf("%d\n", a[start]); // 후위 순회이므로 다 돌고 나서 데이터 출력
}

int main() {
	int n = 0;
	while(scanf("%d", &a[n]) != EOF){
		n++;
	}
	post(0, n);
	
	return 0;
}