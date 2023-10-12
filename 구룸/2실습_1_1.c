#include <stdio.h>
int main(){
	long long int a[100001]={0};
	int n, m;
	
	scanf("%d", &n);
	
	for(int i=0;i<n;i++){
		scanf("%d", &m);
		a[m]=1;
	}
	
	scanf("%d", &n);
	
	for(int i=0;i<n;i++){
		scanf("%d", &m);
		printf("%d ", a[m]);
	}
	
	return 0;
}
