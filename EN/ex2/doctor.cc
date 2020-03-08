#include<iostream>
using namespace std;

struct Patient {
	char name [100];
	int insurance;
	int visits;
};

struct Doctor
{
	char name [100];
	int numPatients;
	Patient patients[10];
	double price;

	void print () {
		cout<<name<<" "<<profit()<<" "<<visits()<<endl;
	}

	double profit () {
		double sum = 0.0;
		for (int i=0;i<numPatients;i++){
			if (patients[i].insurance==0) {
				sum+=(price*patients[i].visits);
			}			
		}

		return sum;
	}

	int visits() {
		int sum =0;
		for (int i=0;i<numPatients;i++)
			sum+=patients[i].visits;
		return sum;
	}

	int compare (Doctor other) {
		if (profit()==other.profit()) {
			if (visits() == other.visits())
				return 0;
			else if (visits() > other.visits())
				return 1;
			else
				return -1;
		}
		else if (profit() > other.profit())
			return 1;
		else 
			return -1;
	}

};

void most_successful_doctor (Doctor * doctors, int n) {
	Doctor max = doctors[0];

	for (int i=1;i<n;i++) {
		// if (doctors[i].profit() > max.profit()) {
		// 	max = doctors[i];
		// }
		// else if (doctors[i].profit() == max.profit()) {
		// 	if (doctors[i].visits() > max.visits()) {
		// 		max = doctors[i];
		// 	}
		// }
		if (doctors[i].compare(max)==1){
			max = doctors[i];
		}
	}

	max.print();
}

int main () {
	/*
	 2 
	 Д-р.Јованка_Јовановска 
	 3 
	 300.00 
	 Јованова_Ивана 
	 1 
	 2 
	 Боцевска_Ивана 
	 0 
	 3 
	 Илиевска_Ангела 
	 1 
	 0 
	 Д-р.Трајче_Трајчев 
	 2 
	 650.00 
	 Крстевски_Филип 
	 1 
	 0 
	 Цветановски_Иван 
	 1 
	 10
	*/

	int n;
	cin>>n;
	Doctor doctors[10];

	for (int i=0;i<n;i++) {
		//TODO enter the info for the doctors
		cin>>doctors[i].name;
		cin>>doctors[i].numPatients;
		cin>>doctors[i].price;
		for (int j=0;j<doctors[i].numPatients;j++) {
			//TODO enter the info for the patients
			cin>>doctors[i].patients[j].name;
			cin>>doctors[i].patients[j].insurance;
			cin>>doctors[i].patients[j].visits;

		}
	}

	most_successful_doctor(doctors, n);

	return 0;
}