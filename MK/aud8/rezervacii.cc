#include<iostream>
#include<cstring>

using namespace std;

class HotelskaRezervacija {
protected:
	int denovi;
	int clenovi;
	char kontakt [20];
	static int cenaPoDen;

public:
	HotelskaRezervacija (char * kontakt, int denovi, int clenovi) {
		this->denovi = denovi;
		this->clenovi = clenovi;
		strcpy(this->kontakt, kontakt);
	}

	static int getCenaPoDen() {
		return cenaPoDen;
	}

	static void setCenaPoDen (int cena) {
		cenaPoDen = cena;
	}

	virtual int vratiCena() {
		return denovi * clenovi * HotelskaRezervacija::getCenaPoDen();
	}

	int vratiCena (int uplata) {
		if (uplata < vratiCena()) {
			cout<<"Ne moze da ja uplatite rezervacijata :("<<endl;
			return -1;
		}else {
			return uplata - vratiCena();
		}
	}

};

int HotelskaRezervacija::cenaPoDen = 25;
// void HotelskaRezervacija::setCenaPoDen(25);

class PolupansionskaHotelskaRezervacija : public HotelskaRezervacija {
private: 
	static int cenaPojadok;
public:
	PolupansionskaHotelskaRezervacija (char * kontakt, int denovi, int clenovi) : 
	HotelskaRezervacija(kontakt, denovi, clenovi) {}

	int vratiCena () {
		return HotelskaRezervacija::vratiCena() 
		+ clenovi * denovi * PolupansionskaHotelskaRezervacija::cenaPojadok;
		//return clenovi * denovi * (HotelskaRezervacija::cenaPoDen + PolupanskionskaHotelskaRezervacija::cenaPojadok);
	}

	static void setCenaPojadok (int cena) {
		cenaPojadok = cena;
	}

};

int PolupansionskaHotelskaRezervacija::cenaPojadok = 5;

class Hotel {
private:
	char ime [50];
	int saldo;

public:
	Hotel (char * ime) {
		strcpy(this->ime,ime);
		this->saldo =0;
	}

	int uplatiZaRezervacija(HotelskaRezervacija &hr, int uplata) {
		int ostatok = hr.vratiCena(uplata);
		if (ostatok==-1) 
			return -1;
		saldo += hr.vratiCena();
		return ostatok;
	}


};

int main () {
	Hotel h("Bristol");
	cout<<"test"<<endl;
	HotelskaRezervacija * hr1 = new HotelskaRezervacija("Petko",5,5);
	int cena = h.uplatiZaRezervacija(*hr1,1000);
	if (cena!=-1)
		cout<<"Kusur : "<<cena<<endl;
	PolupansionskaHotelskaRezervacija *hr2= new PolupansionskaHotelskaRezervacija("Risto",5,5);
	cena=h.uplatiZaRezervacija(*hr2,1000);
	if (cena!=-1)
		cout<<"Kusur : "<<cena<<endl;
	//покажувач кон основна класа покажува кон објект од изведена
	HotelskaRezervacija::setCenaPoDen(30);
	PolupansionskaHotelskaRezervacija::setCenaPojadok(7);
	HotelskaRezervacija * hr3=new PolupansionskaHotelskaRezervacija("Ana",4,2);
	cena=h.uplatiZaRezervacija(*hr3,100);
	if (cena!=-1)
		cout<<"Kusur : "<<cena<<endl;
	PolupansionskaHotelskaRezervacija hr4 ("Tome",5,3);
	cena=h.uplatiZaRezervacija(hr4,1000);
	if (cena!=-1)
	cout<<"Kusur : "<<cena<<endl;
}