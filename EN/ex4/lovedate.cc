#include<iostream>
#include<cstring>
using namespace std;

enum Gender {
	male, female, other
};

class Mate {
private:
	char name [20];
	int age;
	Gender gender;

	void printGender() {
		if (gender == male)
			cout<<"male";
		else if (gender == female)
			cout<<"female";
		else 
			cout<<"other";
	}
public:
	//const with arguments
	//default constructor
	Mate (char * name = "no name", int age = 18, Gender gender = other) {
		strcpy(this->name,name);
		this->age = age;
		this->gender = gender;
	}
	//T (const T & object)
	Mate (const Mate & m) {
		cout<<"Copy constructor for Mate called"<<endl;;
		strcpy(this->name,m.name);
		this->age = m.age;
		this->gender = m.gender;
	}

	void print () {
		cout<<name<<" "<<age<<" ";
		printGender();
		cout<<endl;
	}

	int getAge() {
		return age;
	}
};

class Date {
private:
	Mate m1, m2;
public:
	Date () {

	}

	Date (Mate m1, Mate m2) {
		this->m1 = m1;
		this->m2 = m2;
	}

	Date (const Date & d) {
		cout<<"Copy constr for Date called!"<<endl;
		this->m1 = d.m1;
		this->m2 = d.m2;
	}

	bool isSuccess () {
		//check if the age diff is less or eq than 5
		if (abs(m1.getAge() - m2.getAge())<=5)
			return true;
		else
			return false;
	}

	void print () {
		if (isSuccess()) {
			cout<<"Great couple"<<endl;
			m1.print();
			m2.print();
		} else {
			cout<<"You can go to jail!"<<endl;
		}
	}
};

int main () {
	Mate m ("Stefan", 23, male);
	Mate f ("Some girl", 20, female);
	Mate m1 = m; //explicit call to the copy constructor
	Mate f1 (f); //explicit call
	//m1.print();
	//f1.print();

	Date d (m1, f1); //implicitly the Mate copy const 2 time here
	Date d1 (d); //copy for Date here

	d1.print();
	return 0;
}