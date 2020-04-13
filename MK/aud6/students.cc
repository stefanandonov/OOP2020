#include<iostream>
#include<cstring>

using namespace std;

class Ucenik {
private:
	char * ime;
	double prosek;
	int godina;

	void copy (const Ucenik & u) {
		this->ime = new char [strlen(u.ime)+1];
		strcpy(this->ime, u.ime);
		this->prosek = u.prosek;
		this->godina = u.godina;
	}
public:
	Ucenik (char * ime = "", double prosek = 6.0, int godina = 1) {
		this->ime = new char [strlen(ime)+1];
		strcpy(this->ime, ime);
		this->prosek = prosek;
		this->godina = godina;
	}

	Ucenik (const Ucenik & u) {
		copy(u);
	}

	Ucenik & operator = (const Ucenik & u) {
		if (this!=&u) {
			delete [] ime;
			copy(u);
		}
		return *this;
	}

	~Ucenik() {
		delete [] ime;
	}

	//++, <<, >>, >
	Ucenik & operator ++ () {
		++godina;
		return *this;
	}

	double getProsek() {
		return prosek;
	}

	friend ostream & operator << (ostream & out, const Ucenik & u) {
		return out<<u.ime<<" "<<u.godina<<" "<<u.prosek<<endl;
	}

	friend istream & operator >> (istream & in, Ucenik & u) {
		return in>>u.ime>>u.godina>>u.prosek;
	}

	friend bool operator > (const Ucenik & left, const Ucenik & right);
	friend bool operator >= (const Ucenik & left, double prosek);
};

//left.prosek > right.prosek
bool operator >= (const Ucenik & left, double prosek) {
	return left.prosek >= prosek;
}

bool operator > (const Ucenik & left, const Ucenik & right) {
	return left.prosek > right.prosek;
}

class Paralelka {
private:
	Ucenik * ucenici;
	int n;

	void copy (const Paralelka & p) {
		this->n = p.n;
		ucenici = new Ucenik [p.n];
		for (int i=0;i<n;i++)
			ucenici[i] = p.ucenici[i];
	}

public:
	Paralelka() {
		ucenici = new Ucenik [0];
		n = 0;
	}

	Paralelka (const Paralelka & p) {
		copy(p);
	}

	Paralelka & operator = (const Paralelka & p) {
		if (this!=&p) {
			delete [] ucenici;
			copy(p);
		}
		return *this;
	}

	~Paralelka () {
		delete [] ucenici;
	}

	//+=, ++, >>

	Paralelka & operator += (Ucenik & u) {
		Ucenik * tmp = new Ucenik [n+1];
		for (int i=0;i<n;i++)
			tmp[i] = ucenici[i];
		tmp[n] = u;
		++n;
		delete [] ucenici;
		ucenici = tmp;

		return *this;
	}

	Paralelka & operator ++ () {
		for (int i=0;i<n;i++)
			++ucenici[i]; //ucenici[i]++ nema da raboti
		return *this;
	}

	friend ostream & operator << (ostream & out, const Paralelka & p) {
		for (int i=0;i<p.n;i++)
			out<<p.ucenici[i];
		return out;
	}

	void nagradi() { //site sho imaat prosek > 9.0
		for (int i=0;i<n;i++) {
			if (ucenici[i] >= 9.0)
				cout<<ucenici[i];
		}
	}



	void najvisokProsek() {
		Ucenik max = ucenici[0];
		for (int i=1;i<n;i++) {
			if (ucenici[i] > max) {
				max = ucenici[i];
			}
		}
		cout<<max.getProsek()<<endl;
	}
};

int main () {
	Ucenik u1("Martina Martinovska", 9.5, 3);
	Ucenik u2("Darko Darkoski", 7.3, 2);
	Ucenik u3("Angela Angelovska", 10, 3);

	Paralelka p;
	p += u1;
	p += u2;
	p += u3;

	cout << p;
	cout << "Nagradeni:" << endl;
	p.nagradi();
	cout << endl;
	p.najvisokProsek();
	cout << endl;
	++u2;
	cout << p;
	cout << endl;
	++p;
	cout << p;

	return 0;
}