#include<iostream>
#include<cstring>

using namespace std;

class IndexOutOfBoundsException {};

//genericki funkcii za univerzalni raboti

template <typename T> 
T max (T a, T b) { //mozam max(2,3), max(5,6), max(5,6.5)
	return a>=b ? a : b;  //preoptovareno operator >= ako stanuva zbor za klasi 
}

//vrakjanje na max od niza od objekti od tip T
template <typename T>
T maxOfArray (T * array, int n) {
	T max = array[0];
	for (int i=1;i<n;i++)
		if (array[i]>=max)  ////preoptovareno operator >= ako stanuva zbor za klasi 
			max = array[i];
	return max;
}

//vrakjanje na max od niza od pointeri kon objekti od apstraktna klasa T
template <typename T>
T * maxOfArrayOfPointers (T ** array, int n) {
	T * max = array[0];
	for (int i=1;i<n;i++)
		if (*array[i]>=*max)  ////preoptovareno operator >= ako stanuva zbor za klasi 
			max = array[i];
	return max;
}

//vrakjanje na min od niza od objekti od tip T
template <typename T>
T minOfArray (T * array, int n) {
	T min = array[0];
	for (int i=1;i<n;i++)
		if (array[i]<min)  ////preoptovareno operator < ako stanuva zbor za klasi 
			min = array[i];
	return min;
}

//vrakjanje na min od niza od pointeri kon objekti od apstraktna klasa T
template <typename T>
T * minOfArrayOfPointers (T ** array, int n) {
	T * min = array[0];
	for (int i=1;i<n;i++)
		if (*array[i]<*min)  ////preoptovareno operator >= ako stanuva zbor za klasi 
			min = array[i];
	return min;
}

template <typename T>
void print (T * array, int n) {
	for (int i=0;i<n;i++)
		array[i].print();
}


template <typename T> 
class GenericClass {
	T * array;
	int n;

	void copy (const GenericClass & c) {
		this->n = c.n;
		array = new T [this->n];
		for (int i=0;i<this->n;i++)
			this->array[i]=c.array[i];
	}

public:
	GenericClass () {
		n = 0;
		array = new T [0];
	}

	GenericClass (const GenericClass & c) {
		copy(c);
	}

	GenericClass & operator = (const GenericClass & c) {
		if (this!=&c) {
			delete [] array;
			copy(c);
		}
		return *this;
	}

	~GenericClass () {
		delete [] array;
	}

	GenericClass & operator += (const T & t) {
		//array[n++]=t;
		T * tmp = new T [n+1];
		for (int i=0;i<n;i++)
			tmp[i]=array[i];
		tmp[n]=t;
		n++;
		delete [] array;
		array = tmp;

		return *this;
	}

	GenericClass & operator -= (const T & t) {
		if (contains(t)) {
			T * tmp = new T [n-1];
			int j=0;
			for (int i=0;i<n;i++) {
				if (!(array[i]==t)) // T klasata da go ima preoptovareno !=
					tmp[j++]=array[i];
			}
			--n;
			delete [] array;
			array = tmp;
		}
		return *this;
	}

	T & operator [] (int idx) {
		if (idx>=n || idx<0)
			throw IndexOutOfBoundsException();
		return array[idx];
	}

	bool contains (T element) {
		for (int i=0;i<n;i++)
			if (array[i]==element) //T klasa da go ima preoptovareno == 
				return true;
		return false;
	}
};

int main () {

}