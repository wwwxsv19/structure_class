#include <stdio.h>
#include <stdlib.h>

#define MAX_TERMS 100

typedef struct{
	int row;
	int col;
	int value;
} element; // made by wwwxsv19

typedef struct{
	element data[MAX_TERMS];
	int rows;
	int cols;
	int terms;
} Smatrix;

Smatrix matrixTrans2(Smatrix a){ // made by wwwxsv19
	int bindex = 0;
	Smatrix b;
	
    // 행과 열 값 개수 복사
	b.rows = a.cols;
	b.cols = a.rows;
	b.terms = a.terms;	
	
    // smatrix 에 element 데이터의 행과 열을 바꿔서 넣기 (a, b, c) -> (b, a, c)
	for(int i=0; i < a.cols; i++){
		for(int j=0; j < a.terms; j++){
			if (a.data[j].col == i){
				b.data[bindex].row = a.data[j].col;
				b.data[bindex].col = a.data[j].row;
				b.data[bindex].value = a.data[j].value;
				bindex++;
			}
		}
	}
	
	return b;
}

void matrixPrint(Smatrix a){
	for(int i=0; i < a.terms; i++){
		printf("(%d, %d, %d) \n", a.data[i].row, a.data[i].col, a.data[i].value);
	}
	printf("---------------------\n");
}

int main(void){ // made by wwwxsv19
	Smatrix m;

	scanf("%d %d %d",&m.terms, &m.rows,&m.cols);

	for(int i=0; i < m.terms; i++){
		scanf("%d %d %d", &m.data[i].row, &m.data[i].col, &m.data[i].value);
	}
	
	Smatrix r;
	r = matrixTrans2(m);
	
	matrixPrint(m);
	matrixPrint(r);

	return 0;
}