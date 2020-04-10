#include<iostream>

using namespace std;

class Complex {
private:
	double real;
	double imaginary;
public:
	Complex (double real = 0.0, double imaginary = 0.0) {
		this->real = real;
		this->imaginary = imaginary;
	}

	Complex (const Complex & c) {
		this->real = c.real;
		this->imaginary = c.imaginary;
	}

	//+,-,+=,-+,>>, <<, + (double number)

	//Complex c1,c2,c3; c3=c1+c2;
	Complex operator + (const Complex & c) {
		return Complex(this->real + c.real, this->imaginary + c.imaginary);
	}

	Complex operator - (const Complex & c) {
		return Complex(this->real - c.real, this->imaginary - c.imaginary);
	}

	//c1+=c2; 
	Complex & operator += (const Complex & c) {
		this->real+=c.real;
		this->imaginary += c.imaginary;
		return *this;
	}

	Complex & operator -= (const Complex & c) {
		this->real-=c.real;
		this->imaginary -= c.imaginary;
		return *this;
	}

	friend istream & operator >>(istream & in, Complex & c) {
		return in>>c.real>>c.imaginary;
	}

	friend ostream & operator <<(ostream & out, const Complex & c) {
		if (c.imaginary<0) {
			out<<c.real<<c.imaginary<<"i"<<endl;; //2-3i
		}
		else {
			out<<c.real<<"+"<<c.imaginary<<"i"<<endl;
		}
		return out;
	}

	//(2-3i) + 5.6 = (7.6 - 3i)
	Complex operator + (double number) {
		return Complex(this->real + number, this->imaginary);
	}

	//(2-3i)+=5.6 -> (7.6 - 3i) the same compelx number object 

	Complex & operator += (double number) {
		this->real+=number;
		return *this;
	}

	Complex & operator -= (double number) {
		this->real-=number;
		return *this;
	}



};

int main () {
	Complex c1 (2.1,3.1);
	Complex c2 (-6,-5.1);
	Complex c3,c4;

	c3 = c1+c2;
	cout<<c1<<c2<<c3<<c4;

	c4 = c1-c2;
	cout<<c1<<c2<<c3<<c4;

	c1+=5.6;
	c2-=4.1;
	cout<<c1<<c2<<c3<<c4;

	c3+=c1;
	c4-=c2;
	cout<<c1<<c2<<c3<<c4;

	return 0;
}