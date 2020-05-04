#include<iostream>
using namespace std;

class Vehicle {
protected:
	double acceleration;
public:
	Vehicle (double acceleration = 1.0) {
		cout<<"Vehicle constructor called"<<endl;
		this->acceleration = acceleration;
	}

	~Vehicle () {
		cout<<"Vehicle destructor called"<<endl;
	}

	void setAcceleration (double acceleration) {
		this->acceleration = acceleration;
	}

	double getAcceleration () {
		return acceleration;
	}

	virtual void accelerate () {
		acceleration+=0.1;
		cout<<"Vehicle accelerated"<<endl;
	}
};

class Car : virtual public Vehicle {
public:
	Car (double acceleration = 1.0) : Vehicle(acceleration) {
		cout<<"Car constructor called"<<endl;
	}

	~Car () {
		cout<<"Car destructor called"<<endl;
	}

	virtual void drive() {
		cout<<"Car is driving"<<endl;
	}

	void accelerate () {
		acceleration+=0.1;
		cout<<"Car accelerated"<<endl;
	}
};

class Jet : virtual public Vehicle {
public:
	Jet(double acceleration = 1.0) : Vehicle(acceleration) {
		cout<<"Jet constructor called"<<endl;
	}

	~Jet() {
		cout<<"Jet destructor called"<<endl;
	}

	virtual void fly () {
		cout<<"Jet is flying"<<endl;
	}

	void accelerate () {
		acceleration+=0.3;
		cout<<"Jet accelerated"<<endl;
	}
};

class JetCar : public Car, public Jet {
public:
	JetCar (double acceleration = 0) : Car(acceleration) {
		cout<<"JetCar constructor called"<<endl;
	}

	~JetCar() {
		cout<<"JetCar destructor called"<<endl;
	}

	void drive() {
		cout<<"JetCar is driving"<<endl;
	}

	void fly() {
		cout<<"JetCar is flying"<<endl;
	}

	void accelerate () {
		acceleration+=0.35;
		cout<<"JetCar accelerated"<<endl;
	}
};
int main () {
	JetCar jetCar;
	return 0;
}