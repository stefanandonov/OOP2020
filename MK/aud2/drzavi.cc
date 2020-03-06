#include<iostream>
using namespace std;

struct President {
	char firstName [50];
	char lastName [50];
	char party [50];
};

struct City {
	char name [100];
	int population;
};

struct Country {
	char name [100];
	President president;
	City capital;
	int population;

	int compare (Country other) {
		if (capital.population == other.capital.population)
			return 0;
		else if (capital.population > other.capital.population)
			return 1;
		else return -1;
	}

};

void printPresident (Country * countries, int n) {
	Country max = countries[0];

	for (int i=1;i<n;i++) {
		//if (countries[i].capital.population > max.capital.population)
		if (countries[i].compare(max)==1) {
			max = countries[i];
		}
	}

	cout<<max.president.firstName<<" "<<max.president.lastName<<endl;
}



int main () {

	int n;
	Country countries [10];
	cin>>n;

	for (int i=0;i<n;i++) {
		cin>>countries[i].name;
		cin>>countries[i].population;
		cin>>countries[i].capital.name;
		cin>>countries[i].capital.population;
		cin>>countries[i].president.firstName;
		cin>>countries[i].president.lastName;
		cin>>countries[i].president.party;
	}

	printPresident(countries, n);

	// c1.name = "Macedonia";
	// c1.president.firstName = "Stevo";
	// c1.president.lastName = "Pendarovski";
	// c1.president.party = "SDSM";
	// c1.capital.name = "Skopje";
	// c1.capital.population = 500000;
	// c1.population = 2000000;

	// c2.name = "Greece";
	// c2.president.firstName = "Prokopis";
	// c2.president.lastName = "Pavlopolus";
	// c2.president.party = "NEA DEMOKRATIA";
	// c2.capital.name = "Athens";
	// c2.capital.population = 660000;
	// c2.population = 10000000;

	// cout<<c1.compare(c2)<<endl;
	// cout<<c2.compare(c1)<<endl;


	return 0;
}