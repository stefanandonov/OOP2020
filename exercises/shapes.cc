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
	Shape (const char * id = "NOID",  char * description = "nodescription", Color color = RED, double area = 0.0) {
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

	bool operator == (char * id) {
		return strcmp(this->id,id)==0;
	}

	bool operator == (Color c){
		return this->color == c;
	}

	bool operator > (const Shape & s) const {
		return this->area > s.area;
	}

	Shape operator + (const Shape & s) {
		if (s>(*this)) {
			return Shape(s.id, s.description, s.color, this->area + s.area);
		}
		else
			return Shape(this->id, this->description, this->color, this->area + s.area);
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

	Canvas & operator += (Shape s) {
		Shape * tmp = new Shape [n+1];
		for (int i=0;i<n;i++)
			tmp[i]=shapes[i];
		tmp[n++]=s;
		delete [] shapes;
		shapes = tmp;	
		return *this;	
	}

	bool containsId (char * id) {
		for (int i=0;i<n;i++)
			if (shapes[i]==id)
				return true;

		return false;
	}

	Canvas & operator -= (char * id) {
        //cout<<containsId(id)<<endl;
		if (!containsId(id))
			return *this;

		Shape * tmp = new Shape[n-1];
		for (int i=0, j=0;i<n;i++) {
            //cout<<shapes[i].id<<" "<<id<<" "<<strcmp(shapes[i].id, id)<<endl;
            if (!(shapes[i]==id)) {
                //cout<<j<<","<<i<<endl;
                tmp[j++]=shapes[i];                
            }

		}
        --n;
		delete [] shapes;
		shapes = tmp;
		return *this;
	}

	int hasShapeWithColor (Color color) {
		int count = 0;
        for (int i=0;i<n;i++) {
            //cout<<shapes[i].color<<" "<< color<<" "<<(shapes[i]==color)<<endl;
			if (shapes[i]==color)
				++count;
        }
        

		return count;
	}

	Canvas & operator -= (Color color) {
		int count = hasShapeWithColor(color);
       
        if (count == 0) 
            return *this;

		Shape * tmp = new Shape[n-count];
        for (int i=0,j=0;i<n;i++) {
            
			if (!(shapes[i] == color))
				tmp[j++]=shapes[i];
        }
		delete [] shapes;
		shapes = tmp;
        n-=count;
        return *this;
	}

	

	friend ostream & operator << (ostream & out, const Canvas & c){
		for (int i=0;i<c.n;i++)
			out<<c.shapes[i];
		return out;
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
			copy.shapes[i]*=0.5;
		}

		return copy;
	}

	void expandAll (double percent) {
		for (int i=0;i<n;i++)
			shapes[i]*=(1+percent);
	}

	Shape sum() {
		Shape s; 
		for (int i=0;i<n;i++)
			s = s+shapes[i];
        return s;
	}
    
    Shape & operator [] (int idx) {
        return shapes[idx];
    }

};

int main () {

	int n;
	cin>>n;
	
	Canvas canvas;

	cout<<"TEST FOR >> AND << IN SHAPE CLASS"<<endl;
	Shape s;
	cin>>s;
	cout<<s;
	
	cout<<"TEST FOR += OF CLASS CANVAS"<<endl;
	canvas+=s;
	for (int i=1;i<n;i++) {
		cin>>s;
		canvas+=s;
	}
    
    cout<<"TESTING + FOR CLASS SHAPE AND [] FOR CLASS CANVAS"<<endl;
    cout<<(canvas[0]+canvas[3]);

	cout<<"TESTING = FOR CLASS CANVAS"<<endl;
	Canvas c;
	c = canvas;

	cout<<"TESTING << FOR CLASS CANVAS"<<endl;
	cout<<c;


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

	cout<<"TESTING OPERATOR -= (REMOVE BY ID)"<<endl;
	c-=("A1");
	c-=("Z11");
    
    cout<<c;

	cout<<"TESTING OPERATOR -= (REMOVE BY COLOR)"<<endl;
	c-=(RED);
	cout<<c;

	cout<<"TESTING SUM METHOD AND + OPERATOR IN CLASS SHAPE"<<endl;
	cout<<c.sum();

	return 0;
}