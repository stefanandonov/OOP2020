#include<iostream>
#include<cstring>

using namespace std;

class Exception {
protected:
	char msg [50];
public:
	Exception (char * msg) {
		strcpy(this->msg, msg);
	}

	void showMessage() {
		cout<<msg<<endl;;
	}
};

class NegativeValueException : public Exception {
public:
	NegativeValueException () : Exception ("Ne moze da vnesete negativna cena!") {}
};

class Product {
protected:
	char name [50];
	double price;

public:
	Product (char * name = "", double price = 0.0) {
		strcpy(this->name, name);
		this->price = price;
	}
	Product (const Product & p) {
		strcpy(this->name, p.name);
		this->price = p.price;
	}

	void changePrice (double price) {
		if (price<0)
			throw NegativeValueException();
		this->price = price;
	}

	double getPrice() {
		return price;
	}

	void print () {
		cout<<name<<" "<<price<<endl;
	}


};

class Discount {
public:
	static double EUR;
	static double USD;
	virtual double discount_price() = 0;
	virtual double price() = 0;
	virtual void print_rule() = 0;
};

double Discount::EUR = 61.5;
double Discount::USD = 55.5;

class FoodProduct : public Product, public Discount {
public:
	FoodProduct (char * name = "", double price = 0.0) : Product (name, price){
		
	}
	FoodProduct (const FoodProduct & p) : Product(p) {
		
	}

	double discount_price() {
		return Product::getPrice();
	}
	double price() {
		return Product::getPrice();
	}
	void print_rule() {
		cout<<"храната нема попуст"<<endl;
	}
};

class Drink : public Product, public Discount {
private:
	char brand [50];
	bool alcoholic;
public:
	Drink (char * name = "", double price = 0.0, 
		char * brand = "strumka", bool alcoholic = false) : Product(name, price) {
		strcpy(this->brand, brand);
		this->alcoholic = alcoholic;
	}

	Drink (const Drink & d) : Product(d) {
		strcpy(this->brand, d.brand);
		this->alcoholic = d.alcoholic;
	}

	double discount_price() {		
		if (alcoholic && price()/Discount::EUR > 20) 
			return price()*0.95;
		if (!alcoholic && strcmp(brand, "Coca-Cola")==0)
			return price()*0.9;
		return price();
	}
	double price() {
		return Product::getPrice();
	}
	void print_rule() {
		cout<<"Пијалоците и тоа алкохолните поскапи од 20 евра имаат "
		<<"попуст 5%, а неалкохолните од брендот Coca-Cola имаат попуст "
		<<"од 10%"<<endl;
	}
};

class Cosmetics : public Product, public Discount {
public:
	Cosmetics (char * name = "", double price = 0.0) : Product(name, price) {
		
	}
	Cosmetics (const Cosmetics & p) : Product(p) {
		
	}

	double discount_price() {		
		if (price()/Discount::EUR > 5) 
			return price()*0.88;
		if (price()/Discount::USD > 20)
			return price()*0.86;
		return price();
	}
	double price() {
		return Product::getPrice();
	}
	void print_rule() {
		cout<<"Сите козметички производи поскапи од 5 евра имаат попуст"<<
		" 12%, а оние поскапи од 20 долари имаат попуст 14%"<<endl;
	}
};

double total_price_with_discount (Discount ** d, int n) {
	double sum = 0;

	for (int i=0;i<n;i++) {
		sum += d[i]->discount_price();
	}

	return sum;
}

int main () {
	int n = 0;
	float newPrice;
	Discount **d = new Discount*[10];
	d[n++] = new FoodProduct("leb", 30);
	d[n++] = new Drink("viski", 1350, "Jack Daniel's", true);
	d[n++] = new FoodProduct("sirenje", 390);
	d[n++] = new Drink("votka", 850, "Finlandia", true);
	d[n++] = new Cosmetics("krema", 720);
	d[n++] = new Drink("sok", 50, "Coca-Cola", false);
	d[n++] = new Cosmetics("parfem", 3500);

	cout << "Vkupnata cena na site proizvodi e: " << total_price_with_discount(d, n) << endl;
	//se menuva cenata na site Kozmeticki proizvodi
	cout << "Promena na cenata na kozmetickite proizvodi " << endl;
	for (int i = 0; i < n; ++i) {
		Cosmetics* c = dynamic_cast<Cosmetics *>(d[i]);
		if (c != 0){
			c->print();
			cin >> newPrice;
			try{
				c->changePrice(newPrice);
			}
			catch (NegativeValueException i){
				i.showMessage();
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		delete d[i];
	}
	delete[] d;
	return 0;
}