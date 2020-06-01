#include<iostream>

using namespace std;

double max (double a1, double a2) {
	return a1>=a2 ? a1 : a2;
	// if (a1>=a2)
	// 	return a1;
	// else
	// 	return a2;
}

template <typename T>
T max (T t1, T t2) {
	return t1>=t2 ? t1 : t2;
}

template <typename T>
T min (T t1, T t2) {
	return t1<t2 ? t1 : t2;
}

template <typename T>
T maxOfArray (T * tArray, int n) {
	T max = tArray[0];
	for (int i=1;i<n;i++) {
		if (tArray[i]>=max) { //class T has to have overloaded operator >=
			max = tArray[i]; //Class T has dynimical allocation, operator =, otherwise just copy constructor
		}
	}
	return max;
}

template <typename T>
T * maxOfArrayOfPointers (T ** tArray, int n) {
	T * max = tArray[0];
	for (int i=1;i<n;i++) {
		if (*tArray[i]>=*max) { //class T has to have overloaded operator >=
			max = tArray[i]; //Class T has dynimical allocation, operator =, otherwise just copy constructor
		}
	}
	return max;
}

template <typename T>
class Container {
	T * array;
	int n;

	void copy (const Container & other) {
		this->n = other.n;
		this->array = new T [this->n];
		//strcpy(array. other.array);
		for (int i=0;i<n;i++) {
			this->array[i] = other.array[i]
		}
	}
public:
	Container () {
		n = 0;
		array = new T [0];
	}

	Container (const Container & c) {
		copy(c);
	}

	Container & operator = (const Container & c) {
		if (this!=&c) {
			delete [] array;
			copy(c);
		}
		return *this;
	}

	~Container () {
		delete [] array;
	}

	Container & operator += (const T & t) {
		T * tmp = new T [n+1];
		for (int i=0;i<n;i++) {
			tmp[i] = array[i];
		}
		tmp[n]=t;
		n++;
		delete [] array;
		array = tmp;
		return *this;
	}
};

template <typename T>
class ContainerForAbstracClasses {
	T ** array;
	int n;

	void copy (const Container & other) {
		this->n = other.n;
		this->array = new T * [this->n];
		//strcpy(array. other.array);
		for (int i=0;i<n;i++) {
			this->array[i] = other.array[i]
		}
	}
public:
	ContainerForAbstracClasses () {
		n = 0;
		array = new T * [0];
	}

	ContainerForAbstracClasses (const Container & c) {
		copy(c);
	}

	ContainerForAbstracClasses & operator = (const Container & c) {
		if (this!=&c) {
			delete [] array;
			copy(c);
		}
		return *this;
	}

	~ContainerForAbstracClasses () {
		delete [] array;
	}

	ContainerForAbstracClasses & operator += (T * t) {
		T ** tmp = new T * [n+1];
		for (int i=0;i<n;i++) {
			tmp[i] = array[i];
		}
		tmp[n]=t;
		n++;
		delete [] array;
		array = tmp;
		return *this;
	}
};




int main () {
	cout<<max(5,6);
	cout<<max(6.1, 6.2);
	cout<<max(5, 6.1);
}