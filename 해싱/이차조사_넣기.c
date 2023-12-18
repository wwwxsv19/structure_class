#include <stdio.h>

int k, n = 8;

int hash(int key){
    return key % n;
}

int main(){
    int key, list[8] = {0, 0, 10, 3, 2, 5, 0, 0};
    scanf("%d", &key);
    
	int index = hash(key);

    while(1){
        if(list[index] == 0){
            list[index] = key;
            break;
        }
        else{
            k++;
            index = (hash(key) + (k*k)) % n
        }
    }

	printf("%d\n", index);
		
    for(int i=0; i<8; i++){
            printf("%d ", list[i]);
	}

	return 0;
}