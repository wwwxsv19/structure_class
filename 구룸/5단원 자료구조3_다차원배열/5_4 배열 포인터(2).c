#include <stdio.h>
void inputArray(int a[][4], int row){
	for(int i=0; i<row; i++){ // made by wwwxsv19
		for(int j=0; j<4; j++){
			scanf("%d", &a[i][j]);
		}
	}
}	

int totArray(int* a, int size){ // made by wwwxsv19
	int tot=0;
	for(int i=0; i<size; i++){
		tot += a[i];
	}
	return tot;
}

int main(){
	int score[3][4], tot;
	double avg;

	inputArray(score, 3);
	
	for(int i=0 ; i<3 ; i++){
		tot = totArray(score[i], 4);
		avg = (double)tot / 4.00;
		printf("총점 : %.d, 평균 : %.2lf\n", tot, avg);
	}
    
	return 0;
}