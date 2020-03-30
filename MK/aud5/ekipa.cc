#include<iostream>
#include<cstring>

using namespace std;

class Ekipa {
private:
	char ime [30];
	char grad [30];
	char stadion [30];

	void copy (const Ekipa & e) {
		strcpy(this->ime, e.ime);
		strcpy(this->grad, e.grad);
		strcpy(this->stadion, e.stadion);
	}

public:
	//const with arguments & default constr
	Ekipa (char * ime = "", char * grad = "", char * stadion = "") {
		strcpy(this->ime, ime);
		strcpy(this->grad, grad);
		strcpy(this->stadion, stadion);
	}

	Ekipa (const Ekipa & e) {
		copy(e);
	}

	Ekipa & operator = (const Ekipa & e) {
		if (this==&e)
			return *this;
		else {
			copy(e);
		}
	}

	void pecati () {
		cout<<ime<<" "<<grad<<" "<<stadion<<endl;
	}
};

class Natprevar {
private:
	Ekipa * domakjin;
	Ekipa * gostin;
	int goloviDomakjin;
	int goloviGostin;

public:
	Natprevar () {
		domakjin = new Ekipa();
		gostin = new Ekipa();
		goloviGostin = 0;
		goloviDomakjin = 0;
	}
	Natprevar(Ekipa * domakjin, Ekipa * gostin, 
		int goloviDomakjin, int goloviGostin) {
		this->domakjin = domakjin;
		this->gostin = gostin;
		this->goloviDomakjin = goloviDomakjin;
		this->goloviGostin = goloviGostin;
	}

	~Natprevar() {
		delete domakjin;
		delete gostin;
	}

	void pecati () {
		cout<<"Domakjin: ";
		domakjin->pecati();
		cout<<"Gostin: ";
		gostin->pecati();
		cout<<goloviDomakjin<<":"<<goloviGostin<<endl;
	}

	friend bool eFatenNatprevarot(Natprevar natprevar, char tip);


};

bool eFatenNatprevarot (Natprevar natprevar, char tip) {
	//tip moze da bide '1', '2' ili 'X'
	switch(tip) {
		case '1':
			return natprevar.goloviDomakjin > natprevar.goloviGostin;
		case '2':
			return natprevar.goloviDomakjin < natprevar.goloviGostin;
		case 'X':
			return natprevar.goloviDomakjin == natprevar.goloviGostin;
	}
}

int main() {

	Ekipa * e1 = new Ekipa("Real Madrid", "Madrid", "Bernabeu");
	Ekipa * e2 = new Ekipa("Barca", "Barcelona", "Camp nou");

	e1->pecati();
	e2->pecati();

	Natprevar n (e1,e2,1,1);

	cout<<eFatenNatprevarot(n, '1')<<endl;
	cout<<eFatenNatprevarot(n, 'X')<<endl;
	cout<<eFatenNatprevarot(n, '2')<<endl;

	return 0;
}