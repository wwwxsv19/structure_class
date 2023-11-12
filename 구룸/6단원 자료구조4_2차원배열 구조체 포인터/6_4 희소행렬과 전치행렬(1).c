#include <stdio.h>

#define ROWS 3
#define COLS 3

void inputMatrix(int a[][COLS]){
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			scanf("%d", &a[i][j]);
		}
	}
}

void transMatrix(int a[][COLS], int b[][COLS]){
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			b[j][i] = a[i][j];
		} // made by wwwxsv19
	}
}

void printMatrix(int a[][COLS]){
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			printf("%4d ", a[i][j]);
		}
		printf("\n");
	}
}
// made by wwwxsv19
int main(){
	int array1[ROWS][COLS];
	int array2[ROWS][COLS];
	
	inputMatrix(array1);	
	transMatrix(array1,array2);
	printMatrix(array1);
	
	printf("\n   전치행렬 출력\n");
	printf("  --------------\n");
	printMatrix(array2);
	
	return 0; // made by wwwxsv19
}