#include<iostream>
#include<cstring>

using namespace std;

class Student {
private:
	char * name;
	double average;
	int year;

	void copy (const Student &s) {
		this->name = new char [strlen(s.name)+1];
		strcpy(this->name, s.name);
		this->average = s.average;
		this->year = s.year;
	}

public:
	Student (char * name = "", double average=6.0, int year = 1) {
		this->name = new char [strlen(name)+1];
		strcpy(this->name, name);
		this->average = average;
		this->year = year;
	}

	Student (const Student & s) {
		copy(s);
	}

	Student & operator = (const Student & s) {
		if (this!=&s) {
			delete [] name;
			copy(s);
		}
		return *this;
	}

	~Student () {
		delete [] name;
	}

	//++, >, >>
	Student & operator ++ () {
		++this->year;
		return *this;
	}

	bool operator > (const Student & other) {
		return this->average > other.average;
	}

	bool operator >= (double average) { //reward student > 9.0
		return this->average >= average;
	}

	friend ostream & operator << (ostream & out, const Student & s) {
		return out<<s.name<<" "<<s.year<<" "<<s.average<<endl;
	}

	friend istream & operator >> (istream & in, Student & s) {
		return in>>s.name>>s.year>>s.average;
	}

	double getAverage() {
		return average;
	}
};

class Group {
private:
	Student * students;
	int n;

	void copy (const Group & c){
		this->students = new Student [c.n];
		this->n=c.n;
		for (int i=0;i<this->n;i++) {
			this->students[i] = c.students[i];
		}		
	}
public:
	Group () {
		n = 0;
		students = new Student [0];
	}

	Group (const Group &c) {
		copy(c);
	}

	Group & operator = (const Group &c) {
		if (this!=&c) {
			delete [] students;
			copy(c);
		}
		return *this;
	}

	~Group () {
		delete [] students;
	}

	//++, +=, <<, reward(), highestAverage()

	Group & operator ++ () {
		for (int i=0;i<n;i++) {
			++students[i];
		}
		return *this;
	}

	Group & operator += (const Student & s) {
		Student * tmp = new Student [n+1];
		for (int i=0;i<n;i++)
			tmp[i] = students[i];
		tmp[n] = s;
		++n;
		delete [] students;
		students = tmp;
		return *this;
	}

	friend ostream & operator << (ostream & out, const Group & g) {
		for (int i=0;i<g.n;i++) {
			out<<g.students[i];
		}
		return out;
	}

	void reward() {
		for (int i=0;i<n;i++) {
			if (students[i]>=9.0)
				cout<<students[i];
			}
	}

	void highestAverage () {
		Student max = students[0];

		for (int i=1;i<n;i++) {
			if (students[i]>max) {
				max = students[i];
			}
		}

		cout<<"Highest average in the group is: "<<max.getAverage()<<endl;

	}
};

int main () {

	Student s1("Martina Martinovska", 9.5, 3);
	Student s2("Darko Darkoski", 7.3, 2);
	Student s3("Angela Angelovska", 10, 3);

	Group group;
	group+= s1;
	group+= s2;
	group+= s3;

	cout << group;
	cout << "Reward:" << endl;
	group.reward();
	cout << endl;

	group.highestAverage();
	cout << endl;
	++s2;
	cout << group;
	cout << endl;
	++group;
	cout << group;

	return 0;
}