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

	Array & operator += (int n) { //+= (overload += for addition)
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
		return *this;
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

	Array & operator -= (int n) {  //-=
		int occ = contains(n);
		if (occ == 0)
			return *this;
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

		return *this;
	}

	friend ostream & operator << (ostream & out, const Array & a) {
		out<<"Capacity: "<<a.capacity;
		out<<" Size: "<<a.size<<" ";
		out<<"Elements: ";
		for (int i=0;i<a.size;i++)
			out<<a.array[i]<<" ";
		out<<endl;
		return out;
	}

	// void print() { <<
	// 	cout<<"Capacity: "<<capacity;
	// 	cout<<" Size: "<<size<<" ";
	// 	cout<<"Elements: ";
	// 	for (int i=0;i<size;i++)
	// 		cout<<array[i]<<" ";
	// 	cout<<endl;
	// }

	// >> 
	friend istream & operator >> (istream & in, Array & a) {
		int n;
		in>>n;

		for (int i=0;i<n;i++) {
			int number;
			in>>number;
			a+=number;
		}
	}

	// [] //access a elements at an index

	int & operator [] (int idx) {
		return array[idx];
	}

	// == (two array objects are equal)
	bool operator == (const Array & a) {
		if (this->size!=a.size)
			return false;
		for (int i=0;i<this->size;i++) {
			if (this->array[i]!=a.array[i])
				return false;
		}

		return true;
	}

	// != 
	bool operator != (const Array & a) {
		return !((*this)==a); //Array  == Array 
	}

	//++ (prefix and postfix) 

	//++a prefix
	Array & operator ++ () {
		for (int i=0;i<size;i++)
			++array[i];
		return *this;
	}
	//a++ postfix
	Array operator ++ (int) {
		Array copy (*this); //copy constructor
		for (int i=0;i<size;i++)
			++array[i];
		return copy;
	}



};

int main () {

	Array a;

	for (int i=1;i<=150;i++) {
		a+=i;
	} 

	a[0] = 10;

	a-=10;

	cout<<a;

	cout<<a++;
	cout<<++a;

	Array b = a;
	cout<<(a==b);
	b[10] = 6;
	cout<<(a==b);

	return 0;

}