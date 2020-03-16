#include<iostream>
#include<cmath>
using namespace std;

class Triangle {
private:
	int a,b,c;
public:

	Triangle (int aa = 0, int bb = 0, int cc = 0) {
		a = aa;
		b = bb;
		c = cc;
	}

	//set-eri
	void setA (int aa) {
		a = aa;
	}

	void setB (int bb) {
		b = bb;
	}

	void setC (int cc) {
		c = cc;
	}

	//get-eri
	int getA () {
		return a;
	}

	int getB () {
		return b;
	}

	int getC () {
		return c;
	}

	// ~Triangle() {

	// }

	int perimetar () {
		return a+b+c;
	}

	double plostina() {
		double s = perimetar()/2.0;
		return sqrt(s * (s-a) * (s-b) * (s-c));
	}
};

int main () {

	//povikuvanje na konstruktor so args
	Triangle t;

	cout<<"Perimetar na triagolnikot = "<<t.perimetar()<<endl;
	cout<<"Plostina na triagolnikot = "<<t.plostina()<<endl;

	int a,b,c;
	cin>>a>>b>>c;

	t.setA(a);
	t.setB(b);
	t.setC(c);

	cout<<"Perimetar na triagolnikot = "<<t.perimetar()<<endl;
	cout<<"Plostina na triagolnikot = "<<t.plostina()<<endl;


	return 0;
}