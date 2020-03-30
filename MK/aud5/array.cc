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

	void add (int n) {
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

	void deleteAll (int n) {
		int pojavuvanja = contains(n);
		if (pojavuvanja==0)
			return ;
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
	}

	void print () {
		cout<<"Capacity: "<<capacity<<endl;
		cout<<"Size: "<<size<<endl;
		for (int i=0;i<size;i++) {
			cout<<numbers[i]<<" ";
		}
		cout<<"Usage: "<<((size * 100.0) / capacity )<<endl;
	}
};


int main () {
	Array a; //default capacitet od 5
	//Array a1(15); //15 -> 30 -> 60 -> 120

	

	for (int i=0;i<4;i++)
		a.add(i); //0, 1, 2, 3
	//a.print();

	for (int i=4;i<8;i++){
		a.add(i);
	}
	a.add(1);
	a.add(1); //0,1,2,3,4,5,6,7,1,1
	a.print();

	a.deleteAll(1);
	a.print();

	return 0;
}