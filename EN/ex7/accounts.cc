#include<iostream>
#include<cstring>

using namespace std;

class DebitAccount {
protected:
	char name [50];
	long number;
	double balance;

public:
	DebitAccount (char * name = "", long number = 111111, double balance = 0.0) {
		strcpy(this->name, name);
		this->number = number;
		this->balance = balance;
	}

	DebitAccount (const DebitAccount &da) {
		strcpy(this->name, da.name);
		this->number = da.number;
		this->balance = da.balance;
	}

	void review () {
		cout<<name<<" "<<number<<" "<<balance<<endl;
	}

	void deposit (double amount) {
		balance+=amount;
	}

	bool withdraw (double amount) {
		if (amount <= balance) {
			balance-=amount;
			return true;
		}
		else { //i don't have the money
			return false;
		}
	}
};

class CreditAccount : public DebitAccount {
private:
	double interest; // in percents
	double minus; //debt 
	double limit;
public:
	CreditAccount (char * name = "", long number = 111111, double balance = 0.0,
		double interest = 0.05, double minus = 0, double limit = 1000) 
	: DebitAccount(name, number, balance){
		this->interest = interest;
		this->minus = minus;
		this->limit = limit;
	}

	CreditAccount (const CreditAccount & da) : DebitAccount(da) {
		this->interest = da.interest;
		this->minus = da.minus;
		this->limit = da.limit;
	}

	void review () {
		cout<<"Card informations: ";
		DebitAccount::review();
		cout<<"Interest: "<<interest<<" Debt: "<<minus<<" Limit: "<<limit<<endl;
	}

	void deposit (double amount) {
		if (minus!=0.0) {
			if (amount>minus) { //5000 4000
				amount-=minus; //1000 0
				minus=0;
			}
			else if (amount==minus) { //5000 5000
				amount = 0; //0 0
				minus = 0;
				return ;
			}
			else { //4000 5000
				minus-=amount; //debt = 1000
				return ;
			}
		}

		DebitAccount::deposit(amount);
	}

	bool withdraw (double amount) { //balance 10000, amount = 11000
		bool result = DebitAccount::withdraw(amount);
		if (result) {
			return true;
		}
		else {
			if (amount <= (balance+limit)) { //a=11000 b=10000 l=2000
				double remainder = amount-balance;
				minus+=(remainder*(1+interest)); //minus += 1050
				balance = 0;
				return true;
			}
			else {
				return false;
			}
		}
	}



};
int main () {

	return 0;
}