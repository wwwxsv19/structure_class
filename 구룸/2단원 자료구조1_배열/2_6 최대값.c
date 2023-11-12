#include <stdio.h>
int main(){
	int arr[9], max=0;
	
	for(int i=0; i<9; i++){
		scanf("%d", &arr[i]);
		if(arr[i] > arr[max]) max = i;
	}
	// made by wwwxsv19
	printf("%d\n%d", arr[max], max+1);
	
	return 0;
}