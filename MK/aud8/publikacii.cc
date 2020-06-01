#include<iostream>
#include<cstring>

using namespace std;

class Publikacija {
protected:
	int godina;
	char ime [50];

public:
	Publikacija (int godina = 0, char * ime = "") {
		this->godina = godina;
		strcpy(this->ime,ime);
	}

	int getGodina() {
		return this->godina;
	}

	const char * getIme() {
		return ime;
	}

	void pecati() {
		cout<<ime<<" "<<godina<<" ";
	}
};

class Kniga : public Publikacija {
protected: 
	int brojNaStranici;

public:
	Kniga (int godina = 0, char * ime = "", brojNaStranici = 0) : 
	Publikacija(godina,ime){
		this->brojNaStranici = brojNaStranici;
	}

	void pecati() {
		Publikacija::pecati();
		cout<<brojNaStranici<<" ";
	}
};

class Vesnik : protected Publikacija {
protected:
	int redBr;
	// site metodi i promenlivi od Publikacija ke se protected
public:
	Vesnik (int godina = 0, char * ime = "", redBr = 0) : 
	Publikacija(godina,ime){
		this->redBr = redBr;
	}

	void pecati() {
		Publikacija::pecati();
		cout<<redBr<<" ";
	}
};

class DnevenVesnik : private Vesnik {
private:
	int den;
	int mesec;
public:
	DnevenVesnik(int godina = 0, char * ime = "", redBr = 0
		int den = 1, int mesec = 1) : Vesnik(godina,ime,redBr) {
		this->den = den;
		this->mesec = mesec;
	}

	using Vesnik::pecati;
};

int main () {
	Vesnik vesnik (1999, "Fokus", 15);
	DnevenVesnik vecer (2000, "Vecher", 15, 4, 4);
	cout<<vecer.getIme()<<" "<<vecer.godina(); //nemame pristap
	cout<<vesnik.getIme()<<" "<<vesnik.godina(); //nemame pristap

}