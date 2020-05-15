#include<iostream>
#include<cstring>

using namespace std;

enum Color {
	RED,
	GREEN,
	BLUE
};

class Shape {
protected:
	char id [5];
	char * description;
	Color color; 

	void copy (const Shape &s) {
		strcpy(this->id, s.id);
		this->description = new char [strlen(s.description)+1];
		strcpy(this->description, s.description);
		this->color = s.color;
	}

public:
	Shape (const char * id = "NOID",  char * description = "nodescription", Color color = RED) {
		strcpy(this->id, id);
		this->description = new char [strlen(description)+1];
		strcpy(this->description, description);
		//this->area = area;
		this->color = color;
	}

	Shape (const Shape &s) {
		copy(s);
	}

	Shape & operator = (const Shape &s) {
		if (this!=&s) {
			delete [] description;
			copy(s);
		}
		return *this;
	}

	~Shape () {
		delete [] description;
	}

	char * getColor () {
		switch(color) {
			case RED:
			return "RED";
			case GREEN:
			return "GREEN";
			case BLUE:
			return "BLUE";
			default:
			return "";
		}
	}

	virtual void draw() {
		cout<<id<<" "<<getColor()<<" "<<description<<" type: ";
	}
	virtual double area() = 0;
	virtual double perimeter() = 0;

};

bool operator > (Shape & left, Shape & right) {
	return left.perimeter() > right.perimeter();
}

class Circle : public Shape{
private:
	double radius;

	void copy (const Circle & c) {
		Shape::copy(c);
		this->radius = radius;
	}

public:
	Circle (const char * id = "NOID",  char * description = "nodescription", 
		Color color = RED, double radius = 1.0) : Shape (id, description, color) {
		this->radius = radius;
	}

	Circle (const Circle & c) {
		copy(c);
	}

	Circle & operator = (const Circle &c){
		if (this!=&c) {
			delete [] description;
			copy(c);
		}
	}

	void draw () {
		Shape::draw();
		cout<<"circle "<<perimeter()<<" "<<area()<<endl;
	}

	double perimeter () {
		return 2*radius*3.14;
	}

	double area () {
		return radius* radius*3.14;
	}
};


class Square : public Shape {
private:
	double a;

	void copy (const Square & s) {
		Shape::copy(s);
		this->a=a;
	}

public:
	Square (const char * id = "NOID",  char * description = "nodescription", 
		Color color = RED, double a = 1.0) : Shape (id, description, color) {
		this->a = a;
	}

	Square (const Square & s) : Shape(s) {
		copy(s);
	}

	Square & operator = (const Square & s) {
		if (this!=&s) {
			delete [] description;
			copy(s);
		}
	}

	~Square() {
		delete [] description;
	}

	void draw () {
		Shape::draw();
		cout<<"square "<<perimeter()<<" "<<area()<<endl;
	}

	double perimeter () {
		return 4*a;
	}

	double area () {
		return a*a;
	}

};

class Rectangle : public Shape {
private:
	double a;
	double b;

	void copy (const Rectangle & s) {
		Shape::copy(s);
		this->a=a;
		this->b=b;
	}

public:
	Rectangle (const char * id = "NOID",  char * description = "nodescription", 
		Color color = RED, double a = 1.0, double b = 1.0) : Shape (id, description, color) {
		this->a = a;
		this->b=b;
	}

	Rectangle (const Rectangle & s) : Shape(s) {
		copy(s);
	}

	Rectangle & operator = (const Rectangle & s) {
		if (this!=&s) {
			delete [] description;
			copy(s);
		}
	}

	~Rectangle() {
		delete [] description;
	}

	void draw () {
		Shape::draw();
		cout<<"rectangle "<<perimeter()<<" "<<area()<<endl;
	}

	double perimeter () {
		return 4*a;
	}

	double area () {
		return a*a;
	}

};

double totalArea (Shape ** shapes, int n) {
	double sum = 0.0;
	for (int i=0;i<n;i++)
		sum+=shapes[i]->area();

	return sum;
}

Shape * maxPerimeter(Shape ** shapes, int n) {
	Shape * max = shapes[0];

	for (int i=0;i<n;i++)
		if (*shapes[i]>*max)
			max=shapes[i];

	return max;
}

void drawAllFromType(Shape ** shapes, int n, char * type) {

	for (int i=0;i<n;i++) {
		if (strcmp(type,"circle")==0) {
			Circle * c = dynamic_cast<Circle *>(shapes[i]);
			if (c!=0)
				c->draw();
		}

		if (strcmp(type,"square")==0) {
			Square * c = dynamic_cast<Square *>(shapes[i]);
			if (c!=0)
				c->draw();
		}

		if (strcmp(type,"rectangle")==0) {
			Rectangle * c = dynamic_cast<Rectangle *>(shapes[i]);
			if (c!=0)
				c->draw();
		}
	}
}



int main () {

	int n;
	cin>>n;

	Shape ** shapes = new Shape * [n];

	int type;
	char id [5];
	char * description;
	int color; 
	double radius, a, b;
	for (int i=0;i<n;i++) {
		cin>>type>>id>>description>>color;

		switch(type) {
			case 0: //circle
			cin>>radius;
			shapes[i] = new Circle (id, description, (Color) color, radius);
			break;
			case 1: //square
			cin>>a;
			shapes[i] = new Square (id, description, (Color) color, a);
			break;
			case 2: //rectangle
			cin>>a>>b;
			shapes[i] = new Rectangle (id, description, (Color) color, a, b);
			break;
			default:
			break;

		}
	}


	cout<<"Total area: "<<totalArea(shapes,n)<<endl;
	cout<<"Max perimeter of a shape is: "<<(maxPerimeter(shapes,n))->perimeter()<<endl;

	cout<<"Draw only circles"<<endl;
	drawAllFromType(shapes,n,"circle");

	cout<<"Draw only squares"<<endl;
	drawAllFromType(shapes,n,"square");

	cout<<"Draw only rectangle"<<endl;
	drawAllFromType(shapes,n,"rectangle");

	return 0;

}