#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define Key 10
#define Table 13

#define empty(item) (strlen(item.key)==0)
#define equal(item1, item2) (!strcmp(item.key, item2.key))

typedef struct{
	char key[Key];
} element;

element hash_table[Table];

void init_table(element hs[]){
	for(int i=0; i<Table; i++){
		hs[i].key[0] = NULL;
	}
}

int trans(char* key){
	int num = 0;
	while(*key){
		num = 3 * num + *key++;
	}
	return num;
}

int hash_f(char* key){
	return trans(key) % Table;
}

void hashAdd(element item, element hs[]){
	int i, value;
	value = i = hash_f(item.key);
	
	while(!empty(hs[i])){
		if(equal(item, hs[i])){
			fprintf(stderr, "탐색기가 중복되었습니다.\n");
			exit(1);
		}
		i = (i+1) % Table;
		if(i == value){
			fprintf(stderr, "테이블이 가득 찼습니다.\n");
			exit(1);
		}
	}
	hs[i] = item;
}

void hashSearch(element item, element hs[]){
	int i, value;
	value = i = hash_f(item.key);
	while(!empty(hs[i])){
		if(equal(item, hs[i])){
			fprintf(stderr, "탐색 %s: 위치 = %d\n", item.key, i);
			return;
		}
		i = (i+1) % Table;
		if(i == value){
			fprintf(stderr, "찾는 값이 없습니다.\n");
			return;
		}
	}
	fprintf(stderr, "찾는 값이 없습니다.\n");
}

void hashPrint(element hs[]){
	printf("\n====================\n");
	for(int i=0; i<Table; i++){
		printf("[%d] %s\n", i, hs[i].key);
	}
	printf("\n====================\n");
}

int main(void){
	char *s[7] = {"do", "for", "if", "case", "else", "return", "function"};
	element e;
	
	for(int i=0; i<7; i++){
		strcpy(e.key, s[i]);
		hashAdd(e, hash_table);
		hashPrint(hash_table);
	}
	for(int i=0; i<7; i++){
		strcpy(e.key, s[i]);
		hashSearch(e, hash_table);
	}
	
	return 0;
}