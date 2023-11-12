// 1
/*
#include <stdio.h>
// typedef unsigned int size_t; // unsigned int 가 너무 기니까 size_t 로 줄여버리기
char myStrlen(const char* str); // 함수 선언

unsigned int main(void){
	char s[]="hello"; 
	printf("%d\n", myStrlen(s));
	return 0; // made by wwwxsv19
}

unsigned int myStrlen(const char* str){
	char* s; // 포인터 변수 s
	for(s = str; *s; s++){ // 공백일 때까지 str 문자열 끝까지 가면서 이동
		printf("%8X\n", s); // 이동하면서 주소 출력
	}
	printf("s = %8X, str = %8X\n", s, str); // 메모리상의 주소출력 s 는 공백\0의 인덱스주소값
	return s - str; //끝 주소 - 처음 주소 = 차이가 문자열의 길이! H e l l o \0 일 경우 6-0의 느낌?
}
*/

// 2
/*
#include <stdio.h>
int main(){
	char* s = "world";
	int i;
	printf("%08X %08X %08X %s\n", &s, s, &s[0], s); // 문자열 포인터의 주소, 문자열의 주소, 문자열의 주소, 문자열 
	for(i=0; s[i]!='\0'; i++){
		printf("%08X %c\n", &s[i], s[i]); // 각 주소와 그 값 
	}
	return 0; // made by wwwxsv19
}
*/

// 3
/*
#include <stdio.h>
void outputArray(int* p, int n){
	int i;
	for(i=0; i<n; i++){
		printf("%d %d\n", p[i], *(p+i)); // 직접 참조, 간접 참조 
	}
} 

int main(){
	int array[3] = {10, 20, 30};
	int size = sizeof(array)/sizeof(array[0]);
	outputArray(array, size);
	return 0;
} // made by wwwxsv19
*/