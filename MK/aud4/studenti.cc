#include<iostream>
#include<cstring>

using namespace std;

class Student {
private:
	int index;
	char name [100];
	int firstTest, secondTest, firstExam, secondExam;

public:
	//default i konstr so argument
	Student(int index = 111111, char * name = "no name", 
		int firstTest = 0, int secondTest = 0, 
		int firstExam = 0, int secondExam = 0) {

		this->index = index;
		strcpy(this->name, name);
		this->firstTest = firstTest;
		this->secondTest = secondTest;
		this->firstExam = firstExam;
		this->secondExam = secondExam;
	}

	Student (const Student & s) {
		this->index = s.index;
		strcpy(this->name, s.name);
		this->firstTest = s.firstTest;
		this->secondTest = s.secondTest;
		this->firstExam = s.firstExam;
		this->secondExam = s.secondExam;
	}

	double totalPoints () {
			return firstTest * 0.75 + secondTest * 0.75 
			+ firstExam * 0.40 + secondExam * 0.45;
	}

	int grade (double points) {
		if (points>=90.0)
			return 10;
		else if (points>=80.0)
			return 9;
		else if (points>=70.0)
			return 8;
		else if (points>=60.0)
			return 7;
		else if (points>=50.0)
			return 6;
		else 
			return 5;
	}

	void print () {
		cout<<index<<" "<<name<<" "<<totalPoints();
		cout<<" "<<grade(totalPoints())<<endl;
	}
};

class Predmet {
	char name [10];
	Student students [100];
	int n;
public:
	Predmet (char * name = "SP") {
		strcpy(this->name, name);
		n = 0;
	}

	Predmet (const Predmet & p) {
		strcpy(this->name, p.name);
		this->n = p.n;

		//students = p.students NE
		// STRCPY (students, p.students);	NEEEEEEEEEEEEEEEEEe	
		for (int i=0;i<n;i++)
			this->students[i] = p.students[i];
	}

	void addStudent (Student s) {
		if (n==100) {
			return ;
		}
		students[n] = s; //0,1,2,3,..99
		++n;
	}

	void print () {
		cout<<"Subject with name :"<<name<<" has "<<n<<" students:"<<endl;
		for (int i=0;i<n;i++)
			students[i].print();
	}
};

int main () {

	Predmet sp ("SP");
	Student s (123456, "Trajce", 10, 10, 40, 90);
	Student s1 (123457, "Petar", 10, 10, 45, 65);
	Student s2 (123459, "Petar", 2, 2, 20, 30);
	Student s3 (123460, "Petar", 3, 5, 40, 60);
	

	sp.addStudent(s);
	sp.addStudent(s1);
	sp.addStudent(s2);
	sp.addStudent(s3);

	sp.print();

	return 0;
}