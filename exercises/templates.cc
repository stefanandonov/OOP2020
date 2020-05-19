#include<iostream>
#include<string.h>
using namespace std;

class Student {
private:
	char name [10];
	double average;

public:
	Student (char * name = "", double average = 5.0) {
		strcpy(this->name,name);
		this->average = average;
	}

	Student (const Student & s) {
		strcpy(this->name,s.name);
		this->average = s.average;
	}

	bool operator > (const Student & s) {
		return this->average > s.average;
	}

	friend ostream & operator << (ostream & out, const Student & s) {
		return out<<s.name<<" "<<s.average;
	}
};

template <typename T>
T maxOfArray (T * tArray, int n) {
	T max = tArray[0];
	for (int i=0;i<n;i++)
		if (tArray[i]>max) 
			max = tArray[i];
	return max;
}

int main () {
	
	cout<<"test"<<endl;
	Student students[5];
	
	students[0] = Student("A",9.5);
	students[1] = Student("B",9.2);
	students[2] = Student("C",9.0);
	students[3] = Student("D",7.1);
	students[4] = Student("E",10.0);

	cout<<(maxOfArray(students, 5))<<endl;
	
	return 0;
}