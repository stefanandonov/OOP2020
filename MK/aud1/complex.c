#include<stdio.h>

typedef struct complex {
	int real;
	int im;
} complex;

complex add (complex left, complex right) {
	int real = left.real + right.real;
	int im = left.im + right.im;
	complex result;
	result.real = real;
	result.im = im;
	return result;
}

void subtract (complex left, complex right, complex * result){
	int real = left.real - right.real;
	int im = left.im - right.im;
	(*result).real = real;
	(*result).im = im;
}

int main () {
	complex c1,c2;

	scanf("%d %d", &c1.real, &c1.im);
	scanf("%d %d", &c2.real, &c2.im);

	complex result;

	result = add (c1,c2);
	printf("%d %di\n", result.real, result.im);
	subtract(c1,c2,&result);
	printf("%d %di\n", result.real, result.im);

}