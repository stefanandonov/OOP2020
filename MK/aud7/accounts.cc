#include<iostream>
#include<cstring>

using namespace std;

class DebitAccount {
	char name [100];
	long number;
	double balance; 

public:
	DebitAccount (char * name = "", long number = 1111111, double balance = 0.0) {
		strcpy(this->name, name);
		this->number = number;
		this->balance = balance;
	}

	DebitAccount (const DebitAccount & da) {
		strcpy(this->name, da.name);
		this->number = da.number;
		this->balance = da.balance;
	}

	double getBalance() {
		return this->balance;
	}

	void setBalance(double balance) {
		this->balance = balance;
	}

	friend ostream & operator << (ostream & out, const DebitAccount & da) {
		return out<<da.name<<" "<<da.number<<" "<<da.balance<<endl;
	}

	void deposit (double amount) { //uplata
		this->balance+=amount;
	}

	void withdraw (double amount) { //povlekuvanje isplata
		if (amount > balance) {
			cout<<"This action is not allow!"<<endl;
			return ;
		}else {
			balance-=amount;
		}
	}
};

class CreditAccount : public DebitAccount {
private:
	double limit;
	double interest;
	double minus;

public:
	CreditAccount (char * name = "", long number = 1111111, 
		double balance = 0.0, double limit = 10000, 
		double interest = 0.01) : DebitAccount(name, number, balance) {
		this->limit = limit;
		this->interest = interest;
		this->minus = 0;
	}

	CreditAccount (const DebitAccount & da, double limit = 10000, double interest = 0.01) 
	: DebitAccount(da) {
		this->limit = limit;
		this->interest = interest;
		this->minus = 0;
	}

	CreditAccount (const CreditAccount & ca) : DebitAccount(ca) {
		this->limit = ca.limit;
		this->interest = ca.interest;
		this->minus = ca.minus;
	}

	friend ostream & operator << (ostream & out, const CreditAccount & ca) {
		DebitAccount da (ca);
		return out<<da<<" "<<ca.limit<<" "<<ca.interest<<" "<<ca.minus<<endl;
	}

	void withdraw (double amount) { //povlekuvanje isplata
		if (amount<=balance) {
			//balance-=amount;
			DebitAccount::withdraw(amount);
		}
		else if (amount <= balance + limit) {
			double diff = amount - balance;
			minus += diff * (1+interest);
			limit -= diff;
			DebitAccount::withdraw(balance);
		}
		else {
			cout<<"This action is not allow!"<<endl;
		}
	}
};

int main () {

	return 0;
}