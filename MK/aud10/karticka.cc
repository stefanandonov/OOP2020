#include<iostream>
#include<cstring>
#include<ctype.h>

using namespace std;

class Exception {
protected:
	char msg [50];
public:
	Exception (char * msg) {
		strcpy(this->msg, msg);
	}

	void showMessage() {
		cout<<msg<<endl;;
	}
};

class InvalidIdException : public Exception {
public:
	InvalidIdException (char * msg) : Exception(msg) {}
};

class NotSufficientAmount : public Exception {
public:
	NotSufficientAmount (char * msg) : Exception(msg) {}
};

class Karticka {
protected:
	double saldo;
	char id [16];

private:
	bool valid (char * id) {
		if (strlen(id)!=15)
			return false;
		for (int i=0;i<strlen(id);i++) {
			if (!isdigit(id[i]))
				return false;
		}
		return true;
	}
public:
	Karticka (char * id = "1111111111111", double saldo = 0.0) {
		if (!valid(id))
			//cout<<"Transakciskata smetka e nevalidna"<<endl;
			throw InvalidIdException("Transakciskata smetka e nevalidna");
		strcpy(this->id, id);
		this->saldo = saldo;
	}

	Karticka (const Karticka & k) {
		strcpy(this->id, k.id);
		this->saldo = k.saldo;
	}

	void uplati (double suma) {
		saldo+=suma;
	}

	virtual void isplati (double suma) {
		if (suma < this->saldo) {
			this->saldo-=suma;
		}
		else {
			throw NotSufficientAmount("Nemate dovolno sredstva");
		}
	}

	void print () {
		cout<<id<<": "<<saldo<<endl;
	}
};

class Maestro : public Karticka {
private:
	const static double popust;
public:
	Maestro (char * id = "1111111111111", double saldo = 0.0) : Karticka(id,saldo) {

	}

	Maestro (const Maestro & m) : Karticka(m) {

	}

	void isplati (double suma) {
		suma*=(1-popust);
		Karticka::isplati(suma);
	}
};

const double Maestro::popust = 0.05;

class Master : public Karticka {
private:
	const static double malPopust;
	static double golemPopust;
	double limit;
public:
	Master (char * id = "1111111111111", double saldo = 0.0, 
		double limit = 1000) : Karticka(id,saldo) {
		this->limit = limit;
	}

	Master (const Master & m) : Karticka(m) {
		this->limit = m.limit;
	}

	void isplati (double suma) {
		if (limit>6000) {
			suma*=(1-golemPopust);
		}
		else {
			suma*=(1-malPopust);
		}
		
		Karticka::isplati(suma);
	}
};

const double Master::malPopust = 0.03;
double Master::golemPopust = 0.1;

class Kasa {
	int den;
	int mesec;
	int godina;
	double sredstvaVoGotovina;
	double sredstvaOdKarticki;

public:
	Kasa (int den = 1, int mesec = 1, int godina = 1, double sredstvaVoGotovina = 0) {
		this->den = den;
		this->mesec = mesec;
		this->godina = godina;
		this->sredstvaVoGotovina = sredstvaVoGotovina;
		this->sredstvaOdKarticki = 0;
	}

	void kasaPrimi (double gotovina) {
		sredstvaVoGotovina+=gotovina;
	}

	void kasaPrimi (double iznos, Karticka & karticka) {
		try {
			karticka.isplati(iznos);
			sredstvaOdKarticki+=iznos;
		}
		catch (NotSufficientAmount & e) {
			e.showMessage();
		}
	}

	void prikaziKasa () {
		cout<<den<<" ";
		cout<<mesec<<" ";
		cout<<godina<<" ";
		cout<<"Vo gotovina: "<<sredstvaVoGotovina<<endl;
		cout<<"Na karticki: "<<sredstvaOdKarticki<<endl;
		cout<<"Vkupna sostojba: "<<(sredstvaVoGotovina + sredstvaOdKarticki)<<endl;
	}
};



int main () {
	// Karticka k1;

	// try {
	// 	k1 = Karticka ("012345678912345",5000);
	// }
	// catch (InvalidIdException & e) {
	// 	e.showMessage();
	// }

	// k1.isplati(6000);

	Kasa denesna (11,5,2020,1000);

	Karticka * karticki [10];
	int n = 0;

	try {
		Karticka * k = new Maestro("012345678912345",5000);
		karticki[n] = k;
		++n;
		
	}
	catch (InvalidIdException & e) {
		e.showMessage();
	}

	try {
		Karticka * k = new Master("012A45678912345",5000, 1000);
		cout<<"prodolzuva"<<endl;
		karticki[n] = k;
		++n;
		
	}
	catch (InvalidIdException & e) {
		e.showMessage();
	}

	try {
		Karticka * k = new Master("111111111111111",100000, 7000);
		karticki[n] = k;
		++n;
		
	}
	catch (InvalidIdException & e) {
		e.showMessage();
	}

	cout<<n<<endl;
	

	denesna.kasaPrimi(10000);

	for (int i=0;i<n;i++)
		denesna.kasaPrimi(7000, *karticki[i]);

	denesna.prikaziKasa();

	for (int i=0;i<n;i++)
		karticki[i]->print();




	
	return 0;
}