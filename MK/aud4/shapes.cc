#include<iostream>
#include<cstring>
using namespace std;

enum Type {
	CIRCLE, SQUARE, RECTANGLE, PENTAGON
};

class Shape {
private:
	Type type;
	char description [150];
public:
	Shape () {
		type = CIRCLE;
		strcpy(description, "No specified description from user!");
	}

	Shape (int _type, char * _description) {
		type = Type(_type);
		strcpy(description, _description);
	}

	Shape (Type _type, char * _description) {
		type = _type;
		strcpy(description, _description);
	}


	void print () {
		cout<<"Format e: "<<endl;
		if (type == CIRCLE) {
			cout<<"krug"<<endl;
		} else if (type == SQUARE) {
			cout<<"kvadrat"<<endl;
		} else {
			cout<<"pravoagolnik"<<endl;
		}
		cout<<"Opis na formata:\n"<<description<<endl;
	}
};
int main (){ 
	//default forma 
	//tuka se povikuva default konstruktor
	Shape shape1;
	shape1.print();

	int type;
	char desc [150];

	cin>>type>>desc;
	//tuka se povikuva konstruktor so argumenti
	//tuka kreirame forma po nasha zelba
	Shape shape2 (type, desc);
	shape2.print();

	cin>>type>>desc;
	Shape shape3 (Type(type), desc);
	shape3.print();


	
	return 0;
}