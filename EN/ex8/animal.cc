#include<iostream>
#include<cstring>

using namespace std;

class Animal {
protected:
	char name [50];
public:
	Animal (char * name = "noName") {
		strcpy(this->name,name);
	}

	Animal (const Animal & a) {
		strcpy(this->name,a.name);
	}

	virtual bool canFly () = 0;

	virtual const char * sound () = 0 ;

	char * getName() {
		return name;
	}
};

class Dog : public Animal {
public:
	Dog (char * name = "noName") : Animal(name) {}

	Dog (const Dog & d) : Animal(d) {}
	const char * sound () {
		return "Af af af af af";
	}

	bool canFly () {
		return false;
	}
};

class Bird : public Animal {
public:
	Bird (char * name = "noName") : Animal(name) {}

	Bird (const Bird & b) : Animal(b) {}

	bool canFly () {
		return true;
	}

	const char * sound () {
		return "ciu ciu ciu ciu ciu";
	}
};

class ZeniZoo {
	Animal ** animals; //array of pointers
	// array of object of type Animal ??? * to Animal od & to animal
	int n;
public:
	ZeniZoo () {
		n=0;
		animals = new Animal * [0]; //empty array of pointers
	}

	ZeniZoo & operator += (Animal * a) {
		Animal ** tmp = new Animal * [n+1];
		for (int i=0;i<n;i++)
			tmp[i]=animals[i];
		tmp[n++]=a;
		delete [] animals;
		animals = tmp;
	}

	void print () {
		for (int i=0;i<n;i++) {
			cout<<animals[i]->getName()<<" ";		
			cout<<animals[i]->canFly()<<" "<<animals[i]->sound()<<endl;
		}
	}
};

int main () {

	ZeniZoo zoo;

	Animal * d = new Dog ("kuci");
	Animal * b = new Bird ("kiko");
	Animal * d1 = new Dog ("jeki");
	Animal * d2 = new Dog("lucy");
	Animal * b1 = new Bird("tweety");

	zoo+=d;
	zoo+=d1;
	zoo+=d2;
	zoo+=b;
	zoo+=b1;



	zoo.print();


	return 0;
}