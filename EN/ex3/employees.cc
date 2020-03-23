#include<iostream>
#include<cstring>
using namespace std;

enum Position {
	//0, 1, 2
	MANAGER, OWNER, EMPLOYEE
};

class Employee {
private:
	char name [100];
	Position position;
	double salary;

public:
	Employee (char * nname = "", Position pp = EMPLOYEE, double s = 15000) {
		strcpy(name, nname);
		position = pp;
		salary = s;
	}

	void setName (char * nname) {
		strcpy(name, nname);
	}

	void setPosition (Position p) {
		position = p;
	}

	void setSalary (double s) {
		salary = s;
	}

	void print () {
		cout<<name<<" "<<salary<<" "<<position<<endl;
	}

	int compare (Employee other) {
		if (salary == other.salary)
			return 0; //they are equal
		else if (salary > other.salary)
			return 1;
		else return -1;
	}
};

// int compare (Employee e1, Employee e2) {
// 	e1.salary this is not working! we have to be i
// inside the class 
// }

void sort (Employee * employees, int n) {
	Employee temp;
	for (int i = 0; i < n - 1; i++)
        for (int j = i; j < n; j++) {
        	if (employees[j].compare(employees[i])==1) {
        		temp = employees[j];
        		employees[j] = employees[i];
        		employees[i] = temp;
        	}
        }            
}

void print (Employee * employees, int n) {
	cout<<endl;
	for (int i=0;i<n;i++)
		employees[i].print();
}


int main () {
	Employee employees [100];
	int n;
	cin>>n;
	char name [100];
	int position;
	double salary;
	for (int i=0;i<n;i++) {
		cin>>name>>position>>salary;
		//cout<<name<<position<<salary;
		employees[i].setName(name);
		employees[i].setPosition(Position(position));  
		employees[i].setSalary(salary);
	}

	sort(employees,n);
	print(employees,n);
	return 0;
}