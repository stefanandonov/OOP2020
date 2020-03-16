#include<iostream>
using namespace std;

class Cube {
private:
	int a;
public:
	//default konstruktor
	Cube() {
		cout<<"Kreirana default kocka so strana a = 15"<<endl;
		a=15;
	}
	//konstruktor so argumenti
	Cube(int aa) {
		cout<<"Kreirana naracana kocka so strana a = "<<aa<<endl;
		a = aa;
		//this->a = aa;
	}

	~Cube() {
		cout<<"Kocka so strana "<<a<<"e unistena"<<endl;
	}

	void print () {
		cout<<"Kocka a = "<<a<<endl;
	}
};

int main () {
	Cube c; //se povikuva default konstruktor
	Cube c1(20);
	Cube c2(25);

	c.print();
	c1.print();
	c2.print();

	return 0;
}