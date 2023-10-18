#include <stdio.h>

int n = 8;

int hash(int key){
    return key%n;
}

int f(int list[], int key){
    int index = hash(key);
    int t = index, k = 0;

    while(1){
        if(list[index] == key){
            return index;
        }
        else{
            k++;
            index = (hash(key) + k)%n;  // +1 을 하며 배열의 빈칸을 찾아 넣는다!
            if(t==index){
                return -1;
            }
        }
    }
}

int main(){
    int key, list[8] = {0, 0, 10, 3, 2, 5, 0, 0};
    scanf("%d", &key);

    int index = f(list, key);


    if(index == -1){
        printf("overflow\n");
    }
    else{
        printf("%d\n", index);
        
        for(int i=0; i<n; i++){
            printf("%d ", list[i]);
        }
    }

	return 0;
}
