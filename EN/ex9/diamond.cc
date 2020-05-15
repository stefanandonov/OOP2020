#include<iostream>
#include<cstring>

using namespace std;

class Vehicle {
public:
	Vehicle () {
		cout<<"Vehicle constructor called"<<endl;
	}

	~Vehicle () {
		cout<<"Vehicle destructor called"<<endl;
	}

	virtual void accelarate () {
		cout<<"Vehicle accelaration"<<endl;
	}
};

class Car : virtual public Vehicle {
public:
	Car() : Vehicle(){
		cout<<"Car constructor called"<<endl;
	}

	~Car() {
		cout<<"Car destructor called"<<endl;
	}

	void accelarate () {
		cout<<"Car accelaration"<<endl;
	}

	void drive () {
		cout<<"Car driving"<<endl;
	}
};

class Jet : virtual public Vehicle {
public:
	Jet () : Vehicle () {
		cout<<"Jet constructor called"<<endl;
	}

	~Jet() {
		cout<<"Jet destructor called"<<endl;
	}

	void accelarate () {
		cout<<"Jet accelaration"<<endl;
	}

	void fly () {
		cout<<"Jet fly"<<endl;
	}
};

class CarJet : public Car, public Jet {
public:
	CarJet () : Car(), Jet() {
		cout<<"CarJet constructor called"<<endl;
	}

	~CarJet() {
		cout<<"CarJet destructor called"<<endl;
	}

	void accelarate () {
		cout<<"CarJet accelaration"<<endl;
	}
};

int main () {

	CarJet cj;

	cj.accelarate();
	return 0;
}