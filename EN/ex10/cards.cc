#include<iostream>
#include<cstring>
#include<ctype.h>

using namespace std;


class NotSufficientAmountException {
public:
	void showMessage() {
		cout<<"You don't have enough money to do the transaction"<<endl;
	}
};

class InvalidIdException {
public:
	void showMessage() {
		cout<<"The ID you entered is not valid"<<endl;
	}
};

class Card {
protected:
	char ID [16];
	double balance; 

private:
	bool isValid (char * ID) {
		if (strlen(ID)!=15)
			return false;

		for (int i=0;i<strlen(ID);i++) {
			if (!isdigit(ID[i]))
				return false;
		}

		return true;
	}

public:
	Card (char * ID = "111111111111111", double balance = 0.0) {
		if (!isValid(ID))
			throw InvalidIdException();
		strcpy(this->ID, ID);
		this->balance = balance;
	}

	Card (const Card & c) {
		strcpy(this->ID, c.ID);
		this->balance = c.balance;
	}

	void deposit (double amount) {
		balance += amount;
	}

	virtual void withdraw (double amount) {		
		if (amount > balance) {
			throw NotSufficientAmountException();
		}
		balance-=amount;
	}
};

class Maestro : public Card {
private:
	const static double discount;
public:
	Maestro (char * ID = "111111111111111", double balance = 0.0) 
	: Card (ID, balance) {
	}

	Maestro (const Maestro & c) : Card(c) {
		
	}

	void withdraw  (double amount) {
		amount-=(amount*discount);
		//amount*=(1-discount);
		Card::withdraw(amount);
	}
};

const double Maestro::discount = 0.05;

class Master : public Card {
private:
	double limit;
	const static double smallDiscount;
	static double greaterDiscount;

public:
	Master (char * ID = "111111111111111", double balance = 0.0, 
		double limit = 1000.0) 
	: Card (ID, balance) {
		this->limit = limit;
	}

	Master (const Master & c) : Card(c) {
		this->limit = c.limit;
	}

	void withdraw (double amount) {
		if (limit>6000) {
			amount-=(amount*greaterDiscount);
		}
		else {
			amount-=(amount*smallDiscount);
		}

		Card::withdraw(amount);
	}
};

const double Master::smallDiscount = 0.03; //3%
double Master::greaterDiscount = 0.1; //10%

class Register {
private:
	int day;
	int month;
	int year;
	double cashBalance;
	double cardBalance;

public:
	Register (int day = 1, int month = 1, int year = 2020,
		double cashBalance = 0.0, double cardBalance = 0.0) {
		this->day = day;
		this->month = month;
		this->year = year;
		this->cashBalance = cashBalance;
		this->cardBalance = cardBalance;
	}

	Register (const Register & r) {
		this->day = r.day;
		this->month = r.month;
		this->year = r.year;
		this->cashBalance = r.cashBalance;
		this->cardBalance = r.cardBalance;
	}

	void pay (double cash) {
		cashBalance+=cash;
	}

	void pay (double amount, Card & c) {
		try {
			c.withdraw(amount);
			cardBalance+=amount;
		}
		catch (NotSufficientAmountException & e) {
			e.showMessage();
		}
		cout<<"statement"<<endl;
		
	}

	void show () {
		cout<<day<<"."<<month<<"."<<year<<endl;
		cout<<"Cash balance: "<<cashBalance<<endl;
		cout<<"Cards balance: "<<cardBalance<<endl;
	}
};

int main () {

	Register reg; 
	Card * card1 = new Master ("123456789012345", 10000, 7000);
	Card * card2 = new Master ("123456789012346", 9000, 5000);
	Card * card3 = new Maestro("123456789012347", 1000);
	
	

	Card ** cards = new Card * [3];
	cards[0]=card1;
	cards[1]=card2;
	cards[2]=card3;

	
	// try {
	// 	reg.pay(7000);
	// 	reg.pay(9000, card1);
	// 	reg.pay(10000, card2);
	// 	reg.pay(500, card3);
	// }	
	// catch (NotSufficientAmountException & e) {
	// 	e.showMessage();
	// } not okay
	double amount;
	for (int i=0;i<3;i++) {
		cin>>amount;
		reg.pay(amount, *cards[i]);
	}
	
	return 0;
}










