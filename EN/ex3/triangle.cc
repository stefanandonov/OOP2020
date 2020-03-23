#include<iostream>
#include<cmath>

using namespace std;

class Triangle {
private:
	int a,b,c;
public:
	//default constructor
	Triangle () {
		a=0; b=0; c=0;
		cout<<"Default constructor called"<<endl;
	}

	//constructor with argumetns
	Triangle (int aa, int bb, int cc) {
		a = aa;
		b = bb;
		c = cc;
		cout<<"Constructor with arguments called"<<endl;
	}

	//perimeter method
	int perimeter () {
		return a+b+c;
	}

	//area method 
	double area () {
		//15/2 = 7 NO we want 15/2 = 7.5
		double s = perimeter()/2;
		return sqrt(s*(s-a)*(s-b)*(s-c));
	}

	//geters and seters
	int getA () {
		return a;
	}

	int getB () {
		return b;
	}

	int getC () {
		return c;
	}

	void setA (int aa) {
		a = aa;
	}

	void setB (int bb) {
		b = bb;
	}

	void setC (int cc) {
		c = cc;
	}
};

int main () {
	Triangle t1;
	Triangle t2 (10,15,20);
	Triangle t3 (3,4,5);

	cout<<t1.perimeter()<<" "<<t1.area()<<endl;
	cout<<t2.perimeter()<<" "<<t2.area()<<endl; 
	t1.setA(t1.getA()+2);
	t1.setB(t1.getB()+2);
	t1.setC(t1.getC()+2);
	cout<<t1.perimeter()<<" "<<t1.area()<<endl;
	cout<<t3.perimeter()<<" "<<t3.area()<<endl;  
	return 0;
}