#include<iostream>
#include<cmath>

using namespace std;

class ComplexNumber {
private:
	double r,i;
public:
	ComplexNumber (double r = 0.0, double i = 0.0) {
		this->r = r;
		this->i = i;
	}

	ComplexNumber (const ComplexNumber & c) {
		this->r = c.r;
		this->i = c.i;
	}

	//+,-, ovie vrakjat sosema nov objekt od klasata ComplexNumber

	ComplexNumber operator + (const ComplexNumber & c) {
		ComplexNumber cNew (this->r + c.r, this->i + c.i);
		return cNew;
	}

	ComplexNumber operator - (const ComplexNumber & c) {
		ComplexNumber cNew (this->r - c.r, this->i - c.i);
		return cNew;
	}

	//+=, -=, 

	ComplexNumber & operator += (const ComplexNumber & c) {
		this->r += c.r;
		this->i += c.i;
		return *this;
	}

	ComplexNumber & operator -= (const ComplexNumber & c) {
		this->r -= c.r;
		this->i -= c.i;
		return *this;
	}

	friend ostream & operator << (ostream & out, const ComplexNumber & c) {
		//5" "6i
		return out<<c.r<<" "<<c.i<<"i"<<endl;
	}

	friend istream & operator >> (istream & in, ComplexNumber & c) {
		//5" "6i
		return in>>c.r>>c.i;
	}

};

int main () {

	ComplexNumber c1,c2;

	cin>>c1>>c2;

	cout<<c1+c2;
	cout<<c1-c2;

	c1+=c2;
	cout<<c1;

	ComplexNumber c3 (3.1,4.0);

	c1-=c3;
	cout<<c1;



	return 0;
}