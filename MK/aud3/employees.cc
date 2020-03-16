#include<iostream>
#include<cstring>
using namespace std;

enum type {
	employee, director, dptrManager
};

class Employee{
private:
	char name [100];
	double salary;
	type position;

	void printPosition () {
		switch(position) {
			case employee:
				cout<<"simple employee"<<" ";
				break;
			case director:
				cout<<"Director of the company"<<" ";
				break;
			case dptrManager:
				cout<<"Manager of department"<<" ";
				break;

		}
	}

public:
	Employee () {
		strcpy(name, "NO NAME");
		salary = 0;
		position = type(0);
	}
	Employee(char * nname, double ssalary, int ttype){
		//DONT DO THIS. name = nname;
		strcpy(name, nname);
		salary = ssalary;
		position = type(ttype);
	}

	void setName (char * nname) {
		strcpy(name, nname);
	}

	void setSalary (double newSalary) {
		salary = newSalary;
	}

	void setPosition (int ttype) {
		position = type(ttype);
	}

	double getSalary() {
		return salary;
	}

	void print() {
		cout<<name<<" ";
		printPosition();
		cout<<salary<<endl;
	}

	int compare (Employee other) {
		if (salary > other.salary)
			return 1;
		else if (salary == other.salary)
			return 0;
		else 
			return -1;
	}
};

void sort (Employee * employees, int n) {
	Employee temp;
	for (int i = 0; i < n - 1; i++)
        for (int j = i; j < n; j++)
            if (employees[i].compare(employees[j])<0) {
                temp = employees[j];
                employees[j] = employees[i];
                employees[i] = temp;
            }
}

int main () {

	int n;
	cin>>n;

	Employee employees [20];

	for (int i = 0;i<n;i++) {
		char name [100];
		double salary;
		int type;
		cin>>name>>salary>>type;

		employees[i].setName(name);
		employees[i].setSalary(salary);
		employees[i].setPosition(type);
	}

	sort(employees, n);

	for (int i=0;i<n;i++) {
		employees[i].print();
	}

	return 0;
}