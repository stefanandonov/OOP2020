#include<iostream>
#include<cstring>
using namespace std;

class Date {
private:
	int day, month, year;
public:
	Date (int day = 1, int month = 1, int year = 1946) {
		this->day = day;
		this->month = month;
		this->year = year;
	}

	Date (const Date & d) {
		this->day = d.day;
		this->month = d.month;
		this->year = d.year;
	}

	int compare (Date drug) {
		if (this->year == drug.year) {
			if (this->month == drug.month) {
				if (this->day == drug.day)
					return 0;
				else if (this->day > drug.day)
					return 1;
				else 
					return -1;
			} else if (this->month > drug.month) {
				return 1;
			} else 
			return -1;
		} else if (this->year > drug.year) {
			return 1;
		} else 
			return 0;
	}

	void print () {
		cout<<day<<"."<<month<<"."<<year<<endl;
	}
};

class Employee {
private:
	char name [20];
	double salary;
	Date birthDate;

public:
	//default constructor 
	Employee () {
		strcpy(this->name, "no name");
		this->salary = 14500;
		Date d;
		this->birthDate = d;
	}
	//constructor with arguments
	Employee(char * name, double salary, Date birthDate) {
		strcpy(this->name, name);
		this->salary = salary;
		this->birthDate = birthDate; //copy constructor
	}

	//copy constructor
	Employee (const Employee & e) {
		strcpy(this->name, e.name);
		this->salary = e.salary;
		this->birthDate = e.birthDate;
	}

	void print () {
		cout<<name<<" "<<salary<<" ";
		birthDate.print();
	}

	int compareBySalary (Employee other) {
		if (this->salary > other.salary)
			return 1;
		else if (this->salary == other.salary)
			return 0;
		else 
			return -1;
	}

	int compareByDateOfBirth (Employee other) {
		return this->birthDate.compare(other.birthDate);
	}
};

Employee highestPaidEmployee (Employee * employees, int n) {
	Employee max = employees[0];
	for (int i=1;i<n;i++) {
		if (employees[i].compareBySalary(max)==1) {
			max = employees[i];
		}
	}

	return max;

}
Employee youngestEmployee (Employee * employees, int n) {
	Employee max = employees[0];
	for (int i=1;i<n;i++) {
		if (employees[i].compareByDateOfBirth(max)==1) {
			max = employees[i];
		}
	}

	return max;
}

int main () {
	Date d1(1, 1, 1980);
    Date d2(1, 2, 1983);
    Date d3(11, 12, 1984);

    Employee v[3];
    Employee v1("Marjan", 40000, d1);
    Employee v2("Stefan", 30000, d2);
    Employee v3("Marko", 20000, d3);
    v[0] = v1;   v[1] = v2;   v[2] = v3;

    cout << "Youngest employee: " << endl;
    youngestEmployee(v, 3).print();

    cout << "Highest paid employee:: " << endl;
    highestPaidEmployee(v, 3).print();

    return 0;
}