#include<iostream>
#include<cstring>

using namespace std;

class Datum {
private:
	int den, mesec, godina;

public:
	Datum (int den = 0, int mesec = 0, int godina = 0) {
		this->den = den;
		this->mesec = mesec;
		this->godina = godina;
	}

	Datum (const Datum & d) {
		this->den = d.den;
		this->mesec = d.mesec;
		this->godina = d.godina;
	}

	int sporedi (Datum drug) {
		if (this->godina == drug.godina) {
			if (this->mesec == drug.mesec) {
				if (this->den == drug.den)
					return 0;
				else if (this->den > drug.den)
					return 1;
				else 
					return -1;
			} else if (this->mesec > drug.mesec) {
				return 1;
			} else 
			return -1;
		} else if (this->godina > drug.godina) {
			return 1;
		} else 
			return 0;
	}

	void print () {
		cout<<den<<"."<<mesec<<"."<<godina;
	}
};

class Vraboten {
private:
	char ime [100];
	double plata;
	Datum datum;
public:
	Vraboten() {
		strcpy(this->ime,"NO NAME");
		this->plata = 0.0;
		datum = Datum(1,1,1945);
	}
	Vraboten (char * ime, double plata, Datum datum) {
		strcpy(this->ime, ime);
		this->plata = plata;
		//copy const for datum called here
		this->datum = datum;
	}

	Vraboten (const Vraboten & v) {
		strcpy(this->ime, v.ime);
		this->plata = v.plata;
		//copy const for datum called here
		this->datum = v.datum;
	}

	void print () {
		cout<<"Vraboten so ime: "<<ime<<", zema plata: "<<plata;
		cout<<". Roden na datum: ";
		datum.print();
		cout<<endl;
	}

	int sporediPoPlata(Vraboten drug) {
		if (this->plata == drug.plata)
			return 0;
		else if (this->plata > drug.plata)
			return 1;
		else return -1;
	}

	int sporediPoDatum(Vraboten drug) {
		return this->datum.sporedi(drug.datum);
		// if (this->datum.compare(drug.datum)==0)
		// 	return 0;
		// else if (this->datum.compare(drug.datum)==1)
		// 	return 1;
		// else return -1;
	}
};

Vraboten najplatenVraboten (Vraboten * vraboteni, int n) {
	//TODO max po plata
	Vraboten max = vraboteni[0];
	for (int i=0;i<n;i++) {
		if (vraboteni[i].sporediPoPlata(max)==1) {
			max = vraboteni[i];
		}
	}

	return max;
}

Vraboten najmladVraboten (Vraboten * vraboteni, int n) {
	//TODO min po plata

	Vraboten max = vraboteni[0];
	for (int i=0;i<n;i++) {
		if (vraboteni[i].sporediPoDatum(max)==1) {
			max = vraboteni[i];
		}
	}

	return max;
}

int main () {

	Datum d1(1, 1, 1980);
    Datum d2(1, 2, 1983);
    Datum d3(11, 12, 1984);

    Vraboten v[3];
    Vraboten v1("Marjan", 40000, d1);
    Vraboten v2("Stefan", 30000, d2);
    Vraboten v3("Marko", 20000, d3);
    v[0] = v1;   v[1] = v2;   v[2] = v3;

    cout << "Najmlad vraboten: " << endl;
    najmladVraboten(v, 3).print();

    cout << "Vraboten so najgolema plata: " << endl;
    najplatenVraboten(v, 3).print();

    return 0;
}