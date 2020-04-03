#include<iostream>

using namespace std;

class Array {
private:
	int * array;
	int capacity;
	int size;

	void copy (const Array & a) {
		this->capacity = a.capacity;
		this->size = a.size;
		this->array = new int [this->capacity];
		for (int i=0;i<size;i++) {
			this->array[i] = a.array[i];
		}
	}

public:
	Array () {
		size = 0;
		capacity = 5;
		this->array = new int [capacity];
	}

	Array (int capacity) {
		this->capacity = capacity;
		this->size = 0;
		this->array = new int [capacity];
	}

	Array (const Array & a) {
		copy(a);
	}

	Array & operator = (const Array & a) {
		if (this!=&a) {
			delete [] array;
			copy(a);
		}
		return *this;
	}

	~Array () {
		delete [] array;
	}

	void add (int n) {
		if (this->size == this->capacity) { //it's full, we have to expand
			int * tmp = new int [2*capacity]; //1 temp allocation
			for (int i=0;i<size;i++) //2 copying into temp
				tmp[i]=array[i];
			tmp[size] = n; //3 add the new thing
			++size; //4 increase the size
			capacity*=2;
			delete [] array; //5 delete the origin 
			array = tmp; //6 make the origin point to the temp
		} else {
			array[size] = n;
			++size;
		}
	}

	void replaceAll (int a, int b) {
		for (int i=0;i<size;i++) {
			if (array[i]==a)
				array[i]=b;
		}
	}

	int contains (int n) {
		int count = 0;
		for (int i=0;i<size;i++)
			if (array[i]==n)
				++count;

		return count;
	}

	void deleteAll (int n) {
		int occ = contains(n);
		if (occ == 0)
			return ;
		int * tmp = new int [capacity];
		int j = 0;
		for (int i=0;i<size;i++) {
			if (array[i]!=n) {
				tmp[j]  = array[i];
				++j;
			}
		}
		//size = j;
		size -= occ;
		delete [] array;
		array = tmp;
	}

	void print() {
		cout<<"Capacity: "<<capacity;
		cout<<" Size: "<<size<<" ";
		cout<<"Elements: ";
		for (int i=0;i<size;i++)
			cout<<array[i]<<" ";
		cout<<endl;
	}


};

int main () {

	Array a;

	for (int i=1;i<=150;i++) {
		a.add(i);
		a.print();
	} 

	return 0;

}