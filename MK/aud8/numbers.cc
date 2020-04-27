#include<iostream>
using namespace std;

/*Raboti koi se dovrsheni naknadno:
- operatorot == e preoptovaren
- metodot check e napisan (proveruva dali ima ist broj vo nizata so 
toj shto sakame da go dodademe)
- imav greska vo += operatorot nizata tmp ne ja alocirav na n+1 elementi, tuku 
na n elementi popraveno e sega.
*/

class Number {
    public:
    virtual int intValue() = 0;
    virtual double doubleValue() = 0;
    virtual void print() = 0;
    
   	
    
}; 

bool operator== (Number & n1, Number & n2) {
    return n1.doubleValue() == n2.doubleValue();
}

//ТODO preoptovaruvanje na operatorot == 

class Integer : public Number{ //TODO da se dodadi izraz za nasleduvanje od Number
    private:
    int integer;
    
    public:
    Integer (int integer = 0) {
    	this->integer = integer;
    }

    int intValue() {
    	return integer;
    }
    double doubleValue() {
    	return (double) integer;
    }
    void print() {
    	cout<<"Integer: "<<integer<<endl;
    }    
    
};

class Double : public Number{ //TODO da se dodadi izraz za nasleduvanje od Number
    private:
    double number;
    
    public:
    Double (double number) {
    	this->number = number;
    }
    
    int intValue() {
    	return (int) number;
    }
    double doubleValue() {
    	return number;
    }
    void print() {
    	cout<<"Double: "<<number<<endl;
    }
};

class Numbers{
    private:
    Number ** numbers;
    int n;

    void copy (const Numbers & number) {
    	this->n = number.n;
    	this->numbers = new Number * [this->n];
    	for (int i=0;i<n;i++) {
    		numbers[i] = number.numbers[i];
    	}
    }
    
    public:
    //TODO default konstruktor
    Numbers() {
    	this->numbers = new Number * [0];
    	n=0;
    }
    
    //TODO copy konstruktor
    Numbers (const Numbers & number) {
    	copy(number);
    }    
    //TODO operator =
    Numbers & operator = (const Numbers & number) {
    	if (this!=&number) {
    		//for (int i=0;i<n;i++)
    		//	delete numbers[i];
    		delete [] numbers;
    		copy(number);
    	}
    	return *this;
    	
    }
    
    //TODO destruktor
    ~Numbers() {
    	//for (int i=0;i<n;i++)
    		//delete numbers[i];
    	delete [] numbers;
    }
    
    
    
    bool check (Number * number) { //proveruva dali brojot vekje postoi
        for (int i=0;i<n;i++)
            if (*numbers[i]==*number)
            	return true;
      	return false;
    }
    
    //TODO operator += (operatorot da prima pointer od objekt od Number, a ne referenca)
    Numbers & operator += (Number * number) {
        
        if (check(number))
            return *this;
        
    	Number ** temp = new Number * [this->n+1];
    	for (int i=0;i<n;i++)
    		temp[i]=numbers[i];
    	temp[n++]=number;
    	//for (int i=0;i<n;i++)
    		//delete numbers[i];
    	delete [] numbers;
    	numbers = temp;

    	return *this;
    }
    void statistics() {
    	//count i suma na site broevi, na site celi broevi, i na site decimalni broevi
    	/*Count of numbers: 9
	Sum of all numbers: 165.625
	Count of integer numbers: 5
	Sum of integer numbers: 47
	Count of double numbers: 4
	Sum of double numbers: 118.625*/

    	cout<<"Count of numbers: "<<n<<endl;
    	double sum = 0.0;
    	for (int i=0;i<n;i++)
    		sum+=numbers[i]->doubleValue();
    	cout<<"Sum of all numbers: "<<sum<<endl;

    	int countInteger = 0;
    	int sumInteger = 0;

    	for (int i=0;i<n;i++) {
    		Integer * ptr = dynamic_cast<Integer *>(numbers[i]);
    		if (ptr != 0) { //kastiranjeto e uspeshno, odnosno numbers[i]
    			//vo priroda e integer pokraj toa shto e i Number
    			countInteger++;
    			sumInteger+=ptr->intValue();
    		}
    	}

    	cout<<"Count of integer numbers: "<<countInteger<<endl;
    	cout<<"Sum of integer numbers: "<<sumInteger<<endl;
		cout<<"Count of double numbers: "<<(n - countInteger)<<endl;
		cout<<"Sum of double numbers: "<<(sum - sumInteger)<<endl;

    }
    
    //TODO void integersLessThan (Integer n)
    
    //TODO void doublesBiggerThan (Double n)
};

int main() {
	
	int n;
	cin>>n;
	Numbers numbers;
	for (int i=0;i<n;i++){
		int type;
		double number;
		cin>>type>>number;
		if (type==0){//Integer object
			Integer * integer = new Integer((int) number);
			numbers+=integer;
		}
		else {
			Double * doublee = new Double(number);
			numbers+=doublee;
		}
	}
	
	int lessThan;
	double biggerThan;
	
	cin>>lessThan;
	cin>>biggerThan;		
	
	cout<<"STATISTICS FOR THE NUMBERS\n";
	numbers.statistics();
	/*cout<<"INTEGER NUMBERS LESS THAN "<<lessThan<<endl;
	numbers.integersLessThan(Integer(lessThan));
	cout<<"DOUBLE NUMBERS BIGGER THAN "<<biggerThan<<endl;
	numbers.doublesBiggerThan(Double(biggerThan));*/
	
	return 0;
}