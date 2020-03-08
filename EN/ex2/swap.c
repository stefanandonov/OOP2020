#include<stdio.h>

void swap (int * xPtr, int * yPtr) {
	int tmp = *xPtr;
	*xPtr = *yPtr;
	*yPtr = tmp;
}

int main () {
	int x = 5;
	int y = 6;

	swap (&x,&y);
	printf("%d %d", x, y);
}