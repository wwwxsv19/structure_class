#include <stdio.h>
#include <stdlib.h>
void genRandom(int a[][5], int r){
	for(int i=0; i<r; i++) // made by wwwxsv19
		for(int j=0; j<5; j++)
			a[i][j] = rand()%10+1;
}

void outputArray(int a[][5], int r){
	for(int i=0; i<r; i++){
		for(int j=0; j<5; j++){
			printf("%5d", a[i][j]);
		}
		printf("\n"); // made by wwwxsv19
	}
}
	
float averageScore(int *row, int size){
	int num = 0, max = -1, min = 11;
	for(int i=0; i<size; i++){
		num += row[i];
		if(max < row[i]) max = row[i];
		if(min > row[i]) min = row[i];
	}
	num -= max+min;
	return (float)(num/3.00);
} // made by wwwxsv19

int main() {
	int score[4][5];

	genRandom(score, 4);
	outputArray(score, 4);
	
	for(int i=0; i<4; i++){
		printf("선수 %d : %.2f\n", i+1, averageScore(score[i], 5));
	}
	
	return 0;
}