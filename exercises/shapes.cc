#include<iostream>
#include<cstring>

using namespace std;

enum Color {
	RED, GREEN, BLUE
};

class Shape {
private:
	char id [5];
	double area;
	Color color; 

public:
	Shape (char * id = "NOID",  Color color = RED, double area = 0.0) {
		strcpy(this->id, id);
		this->area = area;
		this->color = color;
	}

	Shape (const Shape &s) {
		strcpy(this->id, s.id);
		this->area = s.area;
		this->color = s.color;
	}

	double getArea() {
		return area;
	}

	void setArea(double area) {
		this->area = area;
	} 

	Color getColor() {
		return color;
	}

	char * getColorString () {
		if (color == RED)
			return "RED";
		else if (color == GREEN)
			return "GREEN";
		else
			return "BLUE";

	}

	void draw () {
		cout<<id<<" "<<getColorString()<<" "<<area<<endl;
	}

};

class Canvas {
private:
	Shape shapes [100];
	int n;
	
public:
	Canvas() {
		n = 0;
	}

	void addShape (Shape s) {
		if (n!=100)
			shapes[n++] = s;
	}

	void drawAll() {
		for (int i=0;i<n;i++)
			shapes[i].draw();
	}

	void drawOnly(Color c) {
		for (int i=0;i<n;i++)
			if (shapes[i].getColor()==c)
				shapes[i].draw();
	}

	double totalArea() {
		double sum = 0.0;
		for (int i=0;i<n;i++)
			sum+=shapes[i].getArea();
	}

	Canvas getHalfCanvas() {
		Canvas copy = Canvas(*this);

		for (int i=0;i<copy.n;i++) {
			copy.shapes[i].setArea(copy.shapes[i].getArea()/2);
		}

		return copy;
	}

};

int main () {

	int n;
	cin>>n;
	cout<<"ADITION OF SHAPES IN THE CANVAS"<<endl;
	Canvas canvas;

	for (int i=0;i<n;i++) {
		char id [5];
		int color;
		double area;

		cin>>id>>color>>area;
		Shape s (id, (Color) color, area);
		canvas.addShape(s);
	}

	cout<<"TESTING DRAW ALL"<<endl;

	canvas.drawAll();

	cout<<"TESTING DRAW RED SHAPES"<<endl;

	canvas.drawOnly(RED);

	cout<<"TESTING TOTAL AREA"<<endl;

	cout<<canvas.totalArea()<<endl;

	cout<<"TESTING HALF CANVAS"<<endl;
	Canvas reducedCanvas = canvas.getHalfCanvas();
	cout<<canvas.totalArea()<<" "<<reducedCanvas.totalArea()<<endl;

	if (reducedCanvas.totalArea() == canvas.totalArea()) {
		cout<<"DO NOT CHANGE THE AREA OF THE OBJECT IN THE CURRENT CANVAS. JUST IN THE NEW CANVAS"<<endl;
	}

	return 0;
}