#include <stdio.h>

void preorder(char t[], int i, int size){
	if(t[i] == NULL || i > size) return ; // made by wwwxsv19
	printf("%c ", t[i]);
	preorder(t, i*2, size);
	preorder(t, (i*2)+1, size);
}

void inorder(char t[], int i, int size){
	if(t[i] == NULL || i > size) return ;
	inorder(t, i*2, size);
	printf("%c ", t[i]);
	inorder(t, (i*2)+1, size);
}

void postorder(char *t, int i, int size){
	if(t[i] == NULL || i > size) return ; // made by wwwxsv19
	postorder(t, i*2, size);
	postorder(t, (i*2)+1, size);
	printf("%c ", t[i]);
}

int main(){
	char tree[] = {NULL, 'A', 'B', 'C', 'D', 'E', 'F', 'G', NULL, NULL, 'H', 'I', NULL, 'J', 'K', 'L'};
	int size = 16;
	
	printf("\n<<전위 탐색>>\n");
	preorder(tree, 1, size);
	
	printf("\n<<중위 탐색>>\n");
	inorder(tree, 1, size); // made by wwwxsv19
	
	printf("\n<<후위 탐색>>\n");
    postorder(tree, 1, size);
	
	return 0;
}