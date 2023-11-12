#include <stdio.h>
int arr[201][201]={0};

int main(){
	int n, m, count=1;
	scanf("%d %d",&n, &m);
	
	for(int i=0; i<n+m-1; i++){ // made by wwwxsv19
		for(int j=0; j<m; j++){
			for(int k=0; k<n; k++){
				if(j+k==i){
					arr[k][j] = count++;
					break;
				}
			}
		}
	}

	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	} // made by wwwxsv19
	
	return 0;
}
