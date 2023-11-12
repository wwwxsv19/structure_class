#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct point{
	int x, y;
} POINT;

void inputPoint( POINT *p ){ // made by wwwxsv19
	for(int i=0; i<5; i++){
		scanf("%d %d", &p[i].x, &p[i].y);
	}
}
	
void outputPoint( POINT p ){
	printf("(%4d, %4d)\n", p.x, p.y);
}

POINT distance(POINT *p) {
	POINT c = p[0];
	int n = abs(p[0].x) + abs(p[0].y);
// made by wwwxsv19
	for (int i = 1; i < 5; i++) {
		int m = abs(p[i].x) + abs(p[i].y);
		if (m < n) {
			c = p[i];
			n = m;
		}
		else if (n == m) {
			int j = p[i].x + p[i].y;
			int k = c.x + c.y;
			if (j < k) c = p[i];
		}
	}
	
	return c;
}

int main() {
	POINT p[5];
	POINT origin; // made by wwwxsv19
	
	inputPoint(p);
	
	origin = distance(p);
	
	printf("원점에서 가장 가까운 좌표 : ");
	outputPoint(origin);
	
	return 0;
}
