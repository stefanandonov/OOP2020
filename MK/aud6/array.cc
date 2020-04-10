#include<iostream>
using namespace std;

class Array {
private:
	int capacity;
	int size;
	int * numbers;
public:
	Array() {
		this->capacity = 5;
		this->size = 0;
		numbers = new int [this->capacity];
	}

	Array (int capacity) {
		this->capacity = capacity;
		this->size = 0;
		numbers = new int [this->capacity];
	}

	Array & operator += (int n) { // +=
		if (size == capacity) {
			int * tmp = new int [2 * capacity]; //1 kreirame kopija
			for (int i=0;i<size;i++) //2 kopirame od numbers vo temp
				tmp[i] = numbers[i];
			tmp[size]=n; //3 noviot element se stava na kraj
			delete [] numbers; //4 brisheme mem alokacija na originalna niza
			numbers = tmp; //5 originalot da pokazuva kon kopijata
			++size;
			capacity = 2 * capacity; //capacity*=2;
		}
		else {
			numbers[size]=n;
			size++;
		}

		return *this;
	}

	void change (int a, int b) {
		for (int i=0;i<size;i++)
			if (numbers[i]==a)
				numbers[i]=b;
	}

	int contains (int n) {
		int counter = 0;
		for (int i=0;i<size;i++) {
			if (numbers[i]==n) {
				++counter;
			}
		}
		return counter;
	}

	Array & operator -= (int n) { //-=
		int pojavuvanja = contains(n);
		if (pojavuvanja==0)
			return *this;
		else {
			int * tmp = new int [size - pojavuvanja];
			int j = 0;
			for (int i=0;i<size;i++) {
				if (numbers[i]!=n) {
					tmp[j]=numbers[i];
					++j;
				}
			}
			delete [] numbers;
			numbers = tmp;
			size -= pojavuvanja;
		}
		return *this;
	}

	// void print () { //<<
	// 	cout<<"Capacity: "<<capacity<<endl;
	// 	cout<<"Size: "<<size<<endl;
	// 	for (int i=0;i<size;i++) {
	// 		cout<<numbers[i]<<" ";
	// 	}
	// 	cout<<"Usage: "<<((size * 100.0) / capacity )<<endl;
	// }

	friend ostream & operator << (ostream & out, const Array & a) {
		out<<"Capacity: "<<a.capacity<<endl;
		out<<"Size: "<<a.size<<endl;
		for (int i=0;i<a.size;i++) {
			out<<a.numbers[i]<<" ";
		}
		out<<"Usage: "<<((a.size * 100.0) / a.capacity )<<endl;
		return out;
	}

	//TODO ==, !=, ++, --, []

	//1,1,1,1,2 == 1,1,1,1,2
	//1,1,1,1,1 != 1,1,1,1,2

	bool operator == (const Array & a) const {
		if (this->size!=a.size)
			return false;
		else {
			for (int i=0;i<this->size;i++)
				if (this->numbers[i]!=a.numbers[i])
					return false;
		}
		return true;
	}

	bool operator != (const Array & a) const {
		return !(*this==a);
	}

	//++ prefix
	Array & operator ++ () {
		for (int i=0;i<size;i++)
			++numbers[i];
		return *this;
	}

	//++ postfix
	Array operator ++ (int) {
		Array copy (*this);
		for (int i=0;i<size;i++)
			numbers[i]++;
		return copy;
	}
	//-- prefix
	Array & operator -- () {
		for (int i=0;i<size;i++)
			--numbers[i];
		return *this;
	}

	//-- postfix
	Array operator -- (int) {
		Array copy (*this);
		for (int i=0;i<size;i++)
			numbers[i]--;
		return copy;
	}

	int & operator [] (int idx) { //Array a;  a[idx] mi dozvoluva da napravam
		return numbers[idx];
	}

};


int main () {
	Array a; //default capacitet od 5
	//Array a1(15); //15 -> 30 -> 60 -> 120

	

	for (int i=0;i<4;i++)
		a+=(i); //0, 1, 2, 3
	//a.print();

	for (int i=4;i<8;i++){
		a+=(i);
	}
	a+=(1);
	a+=(1); //0,1,2,3,4,5,6,7,1,1
	//cout<<a;

	Array a1 (a);
	cout<<a1[3]<<endl;
	a1[3]=2;
	cout<<a1;

	cout<<++a1;
	cout<<a1++;

	// a-=(1);
	// cout<<a;



	cout<<--a1;
	cout<<a1--;
	//cout<<a1;


	return 0;
}