// 1 - 이  결과가 의미하는 것은? 행 우선? 열 우선?
/*
#include <stdio.h>
int main(){
    int i, j, a[2][3] = {{10, 20, 30}, {40, 50, 60}};

    printf("배열 전체의 크기 : %d\n", sizeof(a));
    printf("배열 요소의 개수 : %d\n", sizeof(a)/sizeof(int));\

    printf("%d\n", &a[1][0]-&a[0][0]);
    
    printf("배열 요소의 값과 주소 출력\n");

    for(int i=0; i<2; i++){
        for(int j=0; j<3; j++){
            printf("%d %8X, ", a[i][j], &a[i][j]); // 행 우선이다
        }
        printf("\n");
    } // made by wwwxsv19
    
    return 0;
}
*/

// 2 - 2차원 배열 초기화 및 출력
/*
#include <stdio.h>
int main(){
    int arr[2][4] = {{80, 96, 83, 100}, {88, 100, 96, 98}};

    for(int i=0; i<2; i++){
        for(int j=0; j<4; j++){
            printf("%3d", arr[i][j]);
        }
        printf("\n");
    }

    return 0; // made by wwwxsv19
}
*/

// 3 - 2차원 배열 입력 & 출력 코드를 완성하여 실행해 보자
/*
#include <stdio.h>
void inputArray( int a[][3], int r){
	for(int i=0; i<r; i++){
        for(int j=0; j<3; j++){
            scanf("%d", &a[i][j]);
        }
    }
}
void outputArray( int a[][3], int r){
	for(int i=0; i<r; i++){
        for(int j=0; j<3; j++){
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

int main(){
	int array[4][3];
	int row = 4;
	
	inputArray(array, row);
	outputArray(array, row);

    return 0;
}
*/

#include <stdio.h>
int main(){
	int arr[3][5]={0};
	
	for(int i=0; i<3; i++){
		for(int j=0; j<4; j++){
			scanf("%d", &arr[i][j]);
			arr[i][4] += arr[i][j];
		}
	}
	
	for(int i=0; i<3; i++){
		printf("총점 : %d, 평균 : %.2f\n", arr[i][4], (float)(arr[i][4]/4.0) );
	}
	
	return 0;
}