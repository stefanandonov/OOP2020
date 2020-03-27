#include<iostream>
#include<cstring>

using namespace std;

class Student {
private:
	int id;
	char name [20];
	double totalPoints;
public:
	//default and const with arguments
	Student (int id = 111111, char * name = "noname", double totalPoints = 0) {
		this->id = id;
		strcpy(this->name, name);
		this->totalPoints = totalPoints;
	}
	//copu constryctor
	Student (const Student & s) {
		this->id = s.id;
		strcpy(this->name, s.name);
		this->totalPoints = s.totalPoints;
	}

	int grade() {
		if (totalPoints>=90)
			return 10;
		else if (totalPoints >= 80)
			return 9;
		else if (totalPoints >=70)
			return 8;
		else if (totalPoints >=60)
			return 7;
		else if (totalPoints >= 50)
			return 6;
		else 
			return 5;
	}

	void print() {
		cout<<id<<" "<<name<<" "<<totalPoints<<" "<<grade()<<endl;
	}
};

class Course {
private:
	char name [10];
	Student students [100]; //initialy emptuy
	int n; //initialy zero

public:
	//default and with arguemtns
	Course (char * name = "SP") {
		strcpy(this->name, name);
		n = 0;
	}

	//copy constructor
	Course (const Course &c) {
		strcpy(this->name, c.name);
		n = c.n;
		// NEVER DO THIS ----->>>> strcpy(students, c.students);
		for (int i=0;i<n;i++)
			students[i] = c.students[i];
	}

	void addStudent (Student s) {
		students[n] = s;
		++n;
	}

	void print () {
		cout<<name<<":\n";
		for (int i=0;i<n;i++)
			students[i].print();
	}

};

int main () {

	Course sp;

	Student s1 (111112, "Stefan", 91);
	Student s2 (111113, "Trajce", 87);
	Student s3 (111114, "Petre", 65);
	Student s4 (111115, "Iva", 44);

	sp.addStudent(s1);
	sp.addStudent(s2);
	sp.addStudent(s3);
	sp.addStudent(s4);

	sp.print();
	return 0;
}