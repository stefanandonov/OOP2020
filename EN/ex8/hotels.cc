#include<iostream>
#include<cstring>

using namespace std;

class HotelReservation {
protected:
	char name [50];
	int days;
	int people;

public:
	HotelReservation (char * name ="noname", int days = 1, int people = 1) {
		strcpy(this->name,name);
		this->days = days;
		this->people = people;
	}

	HotelReservation (const HotelReservation & hr) {
		strcpy(this->name,hr.name);
		this->days = hr.days;
		this->people = hr.people;
	}

	virtual int price (int payment) {
		if (payment >= price()) {
			return payment - price();
		}
		else {
			cout<<"Not enough money"<<endl;
			return -1;
		}
	}

	virtual int price() {
		return days * people * 25;
	}
};

class BBHotelReservation : public HotelReservation {

public:
	BBHotelReservation (char * name ="noname", int days = 1, int people = 1) : 
	HotelReservation(name,days,people) {}

	BBHotelReservation (const BBHotelReservation & bbhr) : HotelReservation(bbhr) {}

	int price() {
  		return HotelReservation::price() + days*people*5;
	}
};

class Hotel {
private:
	char name [50];
	int balance;

public:
	Hotel(char * name = "Prespav") {
		strcpy(this->name, name);
		balance = 0;
	}

	int payForReservation(HotelReservation &hr, int payment) {
		int change = hr.price(payment);
		if (change!=-1) {
			balance+=hr.price();
		}
		return change;
	}
};

int main () {
	Hotel h("Bristol");
	HotelReservation * hr1 = new HotelReservation("Petko", 5, 5);
	int price = h.payForReservation(*hr1, 1000);
	if (price != -1)
		cout << "Change : " << price << endl;
	BBHotelReservation *hr2 = new BBHotelReservation("Risto", 5, 5);
	price = h.payForReservation(*hr2, 1000);
	if (price != -1)
		cout << "Change : " << price << endl;
	// pointer to the base class pointing to object of derived
	HotelReservation * hr3 = new BBHotelReservation("Ana", 4, 2);
	price = h.payForReservation(*hr3, 100);
	if (price != -1)
		cout << "Change : " << price << endl;
	BBHotelReservation hr4("Tome", 5, 3);
	price = h.payForReservation(hr4, 1000);
	if (price != -1)
	cout << "Change : " << price << endl;
		return 0;
}