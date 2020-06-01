#include<iostream>
#include<cstring>

using namespace std;

enum tipC {
    basic,
    premium 
};

class Chlen {
    char ime [100];
    tipC tip;
    static int osnovenPopust;
    const static int dopolnitelPopust;
    int godina;

public:
    Chlen (char * ime = "", tipC tip = basic, int godina = 1903) {
        strcpy(this->ime, ime);
        this->tip = tip;
        this->godina = godina;
    }

    Chlen (const Chlen & c) {
        strcpy(this->ime, c.ime);
        this->tip = c.tip;
        this->godina = c.godina;
    }

};

int Chlen::osnovenPopust = 10;
const int Chlen::dopolnitelPopust = 15;

int main(){
	int testCase;
	cin >> testCase;

	char ime[100];
    int tipChlen;
	int popust;
    int god;


	if (testCase == 1){
		cout << "===== Testiranje na klasata Chlen ======" << endl;
        cin.get();
		cin.getline(ime,100);
        cin >> tipChlen;
		cin >> god;
        cout << "===== CONSTRUCTOR ======" << endl;
		Chlen c(ime, (tipC) tipChlen, god);
		cout << c;

	}

    if (testCase == 2){
		cout << "===== Testiranje na static clenovi ======" << endl;
		cin.get();
		cin.getline(ime,100);
        cin >> tipChlen;
		cin >> god;
        cout << "===== CONSTRUCTOR ======" << endl;
		Chlen c(ime, (tipC) tipChlen, god);
		cout << c;

		c.setPopust1(5);

        cout << c;
	}

	if (testCase == 3){
		cout << "===== Testiranje na klasata FINKI-club ======" << endl;
        FINKI_club fc;
        int n;
        cin >> n;
        Chlen chlen[100];
        for(int i = 0; i < n; ++i) {
            cin.get();
            cin.getline(ime,100);
            cin >> tipChlen;
            cin >> god;
            Chlen c(ime, (tipC) tipChlen, god);
            chlen[i] = c;
        }

        fc.setChlenovi(chlen, n);

        cout << fc <<endl;
	}

	if (testCase == 4){
		cout << "===== Testiranje na operatorot -= ======" << endl;
		FINKI_club fc;
		int n;
        cin >> n;
        Chlen chlen[100];
        for(int i = 0; i < n; ++i) {
            cin.get();
            cin.getline(ime,100);
            cin >> tipChlen;
            cin >> god;
            Chlen c(ime, (tipC) tipChlen, god);
            chlen[i] = c;
        }

        fc.setChlenovi(chlen, n);
        cout << "OPERATOR -=" << endl;
        int godina;
        cin >> godina;
        fc-=godina;

        cout << fc;
	}

	if (testCase == 5){
		cout << "===== Testiranje na operatorot -= (so iskluchok) ======" << endl;
		FINKI_club fc;
		int n;
        cin >> n;
        Chlen chlen[100];
        for(int i = 0; i < n; ++i) {
            cin.get();
            cin.getline(ime,100);
            cin >> tipChlen;
            cin >> god;
            Chlen c(ime, (tipC) tipChlen, god);
            chlen[i] = c;
        }

        fc.setChlenovi(chlen, n);
        cout << "OPERATOR -=" << endl;
        int godina;
        cin >> godina;
        fc-=godina;
        
        cout << fc;
	}

	if (testCase == 6){
		cout << "===== Testiranje na metodot naplatiChlenarina  ======" << endl << endl;
		FINKI_club fc(1000);
		int n;
        cin >> n;
        Chlen chlen[100];
        for(int i = 0; i < n; ++i) {
            cin.get();
            cin.getline(ime,100);
            cin >> tipChlen;
            cin >> god;
            Chlen c(ime, (tipC) tipChlen, god);
            chlen[i] = c;
        }

        fc.setChlenovi(chlen, n);

        cout << "Naplati chlenarina:" << endl;
        fc.naplatiChlenarina();
	}
	return 0;
}
