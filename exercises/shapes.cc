#include<iostream>
#include<cstring>

using namespace std;

enum Color {
	RED, GREEN, BLUE
};

class Shape {
private:
	char id [5];
	char * description;
	double area;
	Color color; 

	void copy (const Shape &s) {
		strcpy(this->id, s.id);
		this->description = new char [strlen(s.description)+1];
		strcpy(this->description, s.description);
		this->area = s.area;
		this->color = s.color;
	}

public:
	Shape (char * id = "NOID",  char * description = "nodescription", Color color = RED, double area = 0.0) {
		strcpy(this->id, id);
		this->description = new char [strlen(description)+1];
		strcpy(this->description, description);
		this->area = area;
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

	double getArea() {
		return area;
	}

	void setArea(double area) {
		this->area = area;
	} 

	Color getColor() {
		return color;
	}

	char * getColorString () const {
		if (color == RED)
			return "RED";
		else if (color == GREEN)
			return "GREEN";
		else
			return "BLUE";

	}

	void expand (double percent) {
		area*=(1.0+percent);
	}

	friend ostream & operator << (ostream &out, const Shape & s) {
		return out<<s.id<<" "<<s.getColorString()<<" "<<s.area<<" ["<<s.description<<"]"<<endl;
	}

	friend istream & operator >> (istream &in, Shape & s) {
		in>>s.id>>s.description;
		int type;
		in>>type;
		s.color = (Color)type;
		in>>s.area;
		return in;
	}

	Shape & operator *= (double coef) {
		area*=coef;
		return *this;
	}

	friend class Canvas;

};

class Canvas {
private:
	Shape * shapes;
	int n;

	void copy (const Canvas &c) {
		this->n = c.n;
		this->shapes = new Shape[this->n];
		for (int i=0;i<this->n;i++)
			this->shapes[i] = c.shapes[i];
	}
	
public:
	Canvas() {
		n = 0;
		shapes = new Shape [0];
	}

	Canvas(const Canvas & c) {
		copy(c);
	}

	Canvas & operator = (const Canvas &c){
		if (this!=&c) {
			delete [] shapes;
			copy(c);
		}
		return *this;
	}

	void addShape (Shape s) {
		Shape * tmp = new Shape [n+1];
		for (int i=0;i<n;i++)
			tmp[i]=shapes[i];
		tmp[n++]=s;
		delete [] shapes;
		shapes = tmp;		
	}

	bool containsId (char * id) {
		for (int i=0;i<n;i++)
			if (strcmp(shapes[i].id, id)==0)
				return true;

		return false;
	}

	void removeShapeById (char * id) {
        //cout<<containsId(id)<<endl;
		if (!containsId(id))
			return ;

		Shape * tmp = new Shape[n-1];
		for (int i=0, j=0;i<n;i++) {
            //cout<<shapes[i].id<<" "<<id<<" "<<strcmp(shapes[i].id, id)<<endl;
            if (strcmp(shapes[i].id, id)!=0) {
                //cout<<j<<","<<i<<endl;
                tmp[j++]=shapes[i];                
            }

		}
        --n;
		delete [] shapes;
		shapes = tmp;
	}

	int hasShapeWithColor (Color color) {
		int count = 0;
        for (int i=0;i<n;i++) {
            //cout<<shapes[i].color<<" "<< color<<endl;
			if (shapes[i].color == color)
				++count;
        }
        

		return count;
	}

	void removeShapesByColor (Color color) {
		int count = hasShapeWithColor(color);
        
        if (count == 0) 
            return ;

		Shape * tmp = new Shape[n-count];
        for (int i=0,j=0;i<n;i++) {
            
			if (shapes[i].color != color)
				tmp[j++]=shapes[i];
        }
		delete [] shapes;
		shapes = tmp;
        n-=count;
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
        return sum;
	}

	Canvas getHalfCanvas() {
		Canvas copy = Canvas(*this);
		for (int i=0;i<copy.n;i++) {
			copy.shapes[i].reduce();
		}

		return copy;
	}

	void expandAll (double percent) {
		for (int i=0;i<n;i++)
			shapes[i].expand(percent);
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
		char description [100];

		cin>>id>>description>>color>>area;
		Shape s (id, description, (Color) color, area);
		canvas.addShape(s);
	}

	cout<<"TESTING = FOR CLASS CANVAS"<<endl;
	Canvas c;
	c = canvas;

	cout<<"TESTING DRAW ALL"<<endl;

	c.drawAll();

	cout<<"TESTING DRAW RED SHAPES"<<endl;

	c.drawOnly(RED);

	cout<<"TESTING TOTAL AREA"<<endl;

	cout<<c.totalArea()<<endl;

	cout<<"TESTING HALF CANVAS"<<endl;
	Canvas reducedCanvas = c.getHalfCanvas();
	cout<<c.totalArea()<<" "<<reducedCanvas.totalArea()<<endl;

	if (reducedCanvas.totalArea() == c.totalArea()) {
		cout<<"DO NOT CHANGE THE AREA OF THE OBJECT IN THE CURRENT CANVAS. JUST IN THE NEW CANVAS"<<endl;
	}

	cout<<"TESTING EXPAND ALL"<<endl;
	c.expandAll(0.10);
	cout<<c.totalArea()<<endl;

	cout<<"TESTING REMOVE BY ID"<<endl;
	c.removeShapeById("A1");
	c.removeShapeById("Z11");
    
    c.drawAll();

	cout<<"TESTING REMOVE BY COLOR"<<endl;
	c.removeShapesByColor(RED);

	c.drawAll();

	return 0;
}