#include <stdio.h>
int main(){
	long long int a[100001]={0};
	int n, m;
	
	scanf("%d", &n); // made by wwwxsv19
	
	for(int i=0;i<n;i++){
		scanf("%d", &m);
		a[m]=1;
	}
	
	scanf("%d", &n);
	
	for(int i=0;i<n;i++){
		scanf("%d", &m);
		printf("%d ", a[m]);
	}
	// made by wwwxsv19
	return 0;
}
