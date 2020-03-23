#include<iostream>
#include<cstring>
#include<cmath>

using namespace std;

class Momche {
private:
	char ime [100];
	char prezime [100];
	int godini;
public:
	//default constr. i const. so argumenti
	Momche (char * ime = "", char * prezime ="", int godini = 18) {
		strcpy(this->ime, ime);
		strcpy(this->prezime, prezime);
		this->godini = godini;
	}

	//copy-constructor
	Momche (const Momche & m) {
		cout<<"Momche copy constructor called"<<endl;
		strcpy(this->ime, m.ime);
		strcpy(this->prezime, m.prezime);
		this->godini = m.godini;
	}

	int getGodini () {
		return godini;
	}

	void print () {
		cout<<"Momche: "<<ime<<" "<<prezime<<" "<<godini<<" ";
	}
};

class Devojche {
private:
	char ime [100];
	char prezime [100];
	int godini;
public:
	Devojche (char * ime = "", char * prezime ="", int godini = 18) {
		strcpy(this->ime, ime);
		strcpy(this->prezime, prezime);
		this->godini = godini;
	}

	//copy-constructor
	Devojche (const Devojche & d) {
		cout<<"Devojce copy constructor called"<<endl;
		strcpy(this->ime, d.ime);
		strcpy(this->prezime, d.prezime);
		this->godini = d.godini;
	}

	void print () {
		cout<<"Devojche: "<<ime<<" "<<prezime<<" "<<godini<<" ";
	}

	int getGodini () {
		return godini;
	}
};

class Sredba {
private:
	Momche m;
	Devojche d;

public:
	//const with arguments
	Sredba (Momche m, Devojche d) {
		this->m = m;
		this->d = d;
	}

	Sredba (const Sredba & s) {
		this->m = s.m;
		this->d = s.d;
	}

	void print () {
		cout<<"Sredba: ";
		//NE VAKA cout<<m.print();
		m.print();
		d.print();
		cout<<endl;
	}

	Momche getM () {
		return m;
	}

	Devojche getD () {
		return d;
	}

	void setM (Momche m) {
		this->m = m;
	}

	void setD (Devojche d) {
		this->d = d;
	}

	void siOdgovaraat () {
		if (abs(m.getGodini() - d.getGodini())<=5)
			cout<<"Si odgovaraat"<<endl;
		else
			cout<<"Ne si odgovaraat"<<endl;
	}

};

int main () {
	Momche m ("Trajce", "Trajkov", 21);
	Devojche d ("Tea", "Todorova", 18);

	//ekspliciten povik na copy constructor;
	Momche m1 = m;

	//implicitno povik na copy constructor i za momche i za devojce
	Sredba s (m1,d);
	s.print();
	s.siOdgovaraat();

	Devojche d1 ("Teodora", "Todorova", 15);
	//implicitno se povikuva za devojche
	s.setD(d1);
	s.print();
	s.siOdgovaraat();


	return 0;
}