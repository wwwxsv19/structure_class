#include <stdio.h>
int main() {
	int n, num, score[81]={0};
	char arr[81]={0}; // OX 문자 입력 받을 배열
	
	scanf("%d", &n); // 입력 받을 횟수 입력

	for(int i=0; i<n; i++){
		num=0; // 새로 입력 받을 때마다 누적 점수 초기화
		scanf("%s", arr); // OX 점수 입력
		for(int j=0; arr[j]!='\0'; j++){ // 공백 나올 때까지 검사
			if(arr[j]=='X') num=0; // X일 경우 누적 점수 초기화
			else{
				num++; // 누적 점수 +1
				score[i]+=num; // n번째 점수 저장란에 즉시 더하기 
			}
		}
	}
	// made by wwwxsv19
	for(int i=0; i<n; i++){
		printf("%d\n", score[i]); // 점수들 출력
	}
	
	return 0;
}
