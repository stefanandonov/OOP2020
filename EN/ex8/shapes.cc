#include<iostream>
#include<cmath>

using namespace std;

class Shape {
protected:
	double height;
public:
	Shape (double height = 0.0) {
		this->height = height;
	}

	Shape (const Shape & s) {
		this->height = s.height;
	}

	double getHeight () {
		return height;
	}

	virtual void print () = 0;
	virtual double volume () = 0;

	friend istream & operator >> (istream & in, Shape & s) {
		return in>>s.height;
	}
};

bool operator > (Shape & left, Shape & right) {
	return left.volume() > right.volume();
}

class Cylinder : public Shape {
private:
	double radius;
public:
	Cylinder (double height = 0.0, double radius = 0.0) : Shape(height) {
		this->radius = radius;
	}

	Cylinder (const Cylinder & c) {
		this->height = c.height;
		this->radius = c.radius;
	}

	void print () {
		cout<<"Cylinder with base: "<<radius<<" and height: "<<height<<endl;
	}

	double volume() {
		return radius*radius*3.14*height;
	}

	friend istream & operator >> (istream & in, Cylinder & s) {
		return in>>s.height>>s.radius;
	}
};

class Cone : public Shape {
private:
	double radius;
public:
	Cone (double height = 0.0, double radius = 0.0) : Shape(height) {
		this->radius = radius;
	}

	Cone (const Cone & c) {
		this->height = c.height;
		this->radius = c.radius;
	}

	void print () {
		cout<<"Cone with base: "<<radius<<" and height: "<<height<<endl;
	}

	double volume() {
		return (radius*radius*3.14*height)/3;
	}

	friend istream & operator >> (istream & in, Cone & s) {
		return in>>s.height>>s.radius;
	}
};

class Cuboid : public Shape {
private:
	double a;
	double b;
public:
	Cuboid (double height = 0.0, double a = 0.0, double b = 0.0) : Shape(height){
		this->a = a;
		this->b = b;
	}

	Cuboid (const Cuboid & c) : Shape(c){
		this->a = c.a;
		this->b = c.b;
	}

	void print () {
		cout<<"Cubioid with base sides: "<<a<<"and "<<b<<" and height: "<<height<<endl;
	}

	double volume() {
		return a*b*height;
	}

	friend istream & operator >> (istream & in, Cuboid & s) {
		return in>>s.height>>s.a>>s.b;
	}
};

void shapeWithMaxVolume (Shape ** shapes, int n) {
	Shape * max = shapes[0];

	for (int i=1;i<n;i++) {
		// if (shapes[i]->volume() > max->volume()) without > operator
		if (*shapes[i] > *max) { //pointer > pointer
			max = shapes[i];
		}
	}

	max->print();
}

int countNotCircleBasedShapes (Shape ** shapes, int n) {
	int count = 0;

	for (int i=0;i<n;i++) {
		//is shapes[i] a cubiod? 
		Cuboid * c = dynamic_cast<Cuboid *>(shapes[i]);
		if (c!=0)
			++count;
	}

	return count;
}



int main () {

	//Shape s; //this is not allowed
	//Shape * s = new Cubioid(10,5,5);

	int n;
	cin>>n;

	Shape ** shapes = new Shape * [n];

	int type; //0 - cylinder, 1 - cone, 2 - cuboid
	double height, radius, a, b;
	for (int i=0;i<n;i++) {
		cin>>type;
		cout<<type;
		switch (type) {
			case 0: //cylinder			
			shapes[i] = new Cylinder();
			cin>>*shapes[i];
			break;
			case 1: //cone
			cin>>height>>radius;
			shapes[i] = new Cone(height, radius);
			break;
			case 2: //cuboid
			cin>>height>>a>>b;
			shapes[i] = new Cuboid(height, a, b);
			break;
			default:
			break;
		}
	}

	shapeWithMaxVolume(shapes,n);

	cout<<countNotCircleBasedShapes(shapes,n);


	return 0;
}