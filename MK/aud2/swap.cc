#include<iostream>
using namespace std;

void swap (int & xR, int & yR) {
	int tmp = xR;
	xR = yR;
	yR = tmp;
} 


int main () {

	int x,y;
	x=5;
	y=6;

	//da mu gi smenam vrednostite
	swap(x,y);

	cout<<x<<" "<<y;

	return 0;
}