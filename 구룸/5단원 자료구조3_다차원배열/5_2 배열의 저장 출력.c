#include<stdio.h> 
int main(){
	int a[101][101]={0}, n, num=1;
	scanf("%d",&n);
	
	for(int i=0; i<n; i++){
		if(i%2==0){
			for(int j=0; j<n; j++){
				a[i][j]=num++;
			}
		}
		else{ // made by wwwxsv19
			for(int j=n-1; j>=0; j--){
				a[i][j]=num++;
			}
		}
	}
	
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}