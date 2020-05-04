#include<iostream>
#include<cmath>

using namespace std;

class GeomTelo { //apstraktna klasa, barem eden chisto virtuelen metod
protected:
	double visina;
public:
	GeomTelo (double visina = 0.0) {
		this->visina = visina;
	}

	GeomTelo (const GeomTelo & gt) {
		this->visina = gt.visina;
	}

	virtual void pecati() = 0;
	virtual double volumen() = 0;

	double getVisina() {
		return visina;
	}
};

bool operator > (GeomTelo & left, GeomTelo & right) {
	return left.volumen() > right.volumen();
}

class Konus : public GeomTelo {
private:
	double radius;
public:
	Konus (double visina = 0.0, double radius = 0.0) : GeomTelo(visina) {
		this->radius = radius;
	}

	Konus (const Konus & k) : GeomTelo(k) {
		this->radius = k.radius;
	}

	void pecati() {
		cout<<"Konus so osnova: "<<radius<<", visina: "<<visina<<", volumen: "<<volumen()<<endl;
	}

	double volumen() {
		return (radius * radius * 3.14 * visina)/3;
	}
};

class Cilindar : public GeomTelo {
private:
	double radius;
public:
	Cilindar (double visina = 0.0, double radius = 0.0) : GeomTelo(visina) {
		this->radius = radius;
	}

	Cilindar (const Cilindar & c) : GeomTelo(c) {
		this->radius = c.radius;
	}

	void pecati() {
		cout<<"Cilindar so osnova: "<<radius<<", visina: "<<visina<<", volumen: "<<volumen()<<endl;
	}

	double volumen() {
		return (radius * radius * 3.14 * visina);
	}
};

class Kvadar : public GeomTelo {
private:
	double a;
	double b;
public:
	Kvadar (double visina = 0.0, double a = 0.0, double b=0.0) : GeomTelo(visina) {
		this->a = a;
		this->b = b;
	}

	Kvadar (const Kvadar & k) : GeomTelo(k) {
		this->a = k.a;
		this->b = k.b;
	}

	void pecati() {
		cout<<"Kvadar so osnovi: "<<a<<" i "<<b<<", visina: "<<visina<<", volumen: "<<volumen()<<endl;
	}

	double volumen() {
		return a*b*visina;
	}
};

void teloSoNajgolemVolumen (GeomTelo ** gt, int n) {
	GeomTelo * max = gt[0];
	for (int i=1;i<n;i++) {
		if (*(gt[i])>*(max)) { //mora da se preoptovari
			max=gt[i];
		}
	}
	max->pecati();
}

int telaBezKruznaOsnova (GeomTelo ** gt, int n) {
	int count = 0;
	Kvadar * ptr;

	for (int i=0;i<n;i++) {
		ptr = dynamic_cast<Kvadar *>(gt[i]);
		if (ptr!=0) {
			++count;
		}
	}

	return count;
}

int main () {

	GeomTelo ** tela; 
	int n;
	cin>>n;
	tela = new GeomTelo * [n];
	int tip;
	double a, b, r, h;

	for (int i=0;i<n;i++) {
		cin>>tip>>h;

		if (tip==1) { //konus
			cin>>r;
			tela[i] = new Konus (h, r);
		}
		else if (tip == 2) { //cilindar {
			cin>>r;
			tela[i] = new Cilindar (h, r); 
		}
		else { //kvadar
			cin>>a>>b;
			tela[i] = new Kvadar(h, a, b);
		}
	}

	teloSoNajgolemVolumen(tela, n);

	cout<<"Tela bez kruzna osnova (kvadari): "<<telaBezKruznaOsnova(tela, n);
	return 0;
}