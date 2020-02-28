#include<stdio.h>

typedef struct complex {
	int real;
	int im;
} complex;

complex add (complex left, complex right) {
	complex result;
	result.real = left.real + right.real;
	result.im = left.im + right.im;
	return result;
}

void subtract (complex left, complex right, complex * result) {
	result->real = left.real - right.real;
	result->im = left.im - right.im;
}

void printComplex (complex c) {
	printf("%d %di\n", c.real, c.im);
}

int main () {
	complex c1, c2, result;
	scanf("%d %d", &c1.real, &c1.im);
	scanf("%d %d", &c2.real, &c2.im);

	printComplex(add(c1,c2));
	subtract(c1,c2,&result);
	printComplex(result);
	return 0;
}