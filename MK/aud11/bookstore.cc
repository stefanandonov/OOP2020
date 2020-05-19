#include<iostream>
#include <cstring>
#define MAX 50
using namespace std;

enum typeC {
  standard,
  loyal,
  vip
};

class UserExistsException {
public:
  void showMessage () {
    cout<<"The user already exists in the list!"<<endl;
  }
};

class Customer {
private:
  char name [50];
  char email [50];
  typeC type;
  static int basicDiscount;
  const static int extraDiscount;
  int numProducts;

  const char * getTypeInString () const {
    return ((type == standard) ? "standard" : ((type == loyal) ? "loyal" : "vip"));
  }

  int discount() const {
    return (type == standard) ? 0 : ((type==loyal) ? basicDiscount : (basicDiscount + extraDiscount));
  }

public:
  Customer (char * name = "unknown", char * email = "blabla@finki.ukim.mk", 
    typeC tC = standard, int numProducts = 0) {
    strcpy(this->name,name);
    strcpy(this->email, email);
    type = tC;
    this->numProducts = numProducts;
  }

  Customer (const Customer & c) {
    strcpy(this->name,c.name);
    strcpy(this->email, c.email);
    type = c.type;
    this->numProducts = c.numProducts;
  }

  static void setDiscount1 (int discount) {
    basicDiscount = discount;
  }

  friend ostream & operator << (ostream & out, const Customer & c) {
    /*
    [ime_na_kupuvac]
    [email_na_kupuvac]
    [broj_na_proizvodi]
    [vid_na_kupuvac] [popust_sto_moze_da_go_koristi]*/
    return out<<c.name<<endl<<c.email<<endl<<c.numProducts<<endl<<c.getTypeInString()<<" "<<c.discount()<<endl;


  }

  bool operator == (const Customer & other) {
    return (strcmp(this->email, other.email)==0);
  }

  typeC getType () {
    return type;
  }

  int getNumProducts() {
    return numProducts;
  }

  void setType (typeC type) {
    this->type = type;
  }

  void setType (int type) {
    this->type = (typeC) type;
  }

  void update () {
    if (type == standard && numProducts > 5) {
      type = loyal;
    }
    else if (type == loyal && numProducts > 10) {
      type = vip;
    }
  }
};

int Customer::basicDiscount = 10;
const int Customer::extraDiscount = 20;


class FINKI_bookstore {
  Customer * customers;
  int n;

  void copy (const FINKI_bookstore & c) {
    this->n = c.n;
    customers = new Customer [this->n];
    for (int i=0;i<this->n;i++)
      this->customers[i] = c.customers[i];
  }

  bool contains (const Customer & c) {
    for (int i=0;i<n;i++)
      if (customers[i]==c)
        return true;
    return false;
  }

public:
  FINKI_bookstore () {
    customers = new Customer [0];
    n = 0;
  }

  FINKI_bookstore (const FINKI_bookstore & fb) {
    copy(fb);
  }

  FINKI_bookstore & operator = (const FINKI_bookstore & fb) {
    if (this!=&fb) {
      delete [] customers;
      copy(fb);
    }
    return *this;
  }

  ~FINKI_bookstore () {
    delete [] customers;
  }

  void setCustomers (Customer * customers, int n) {
    //this->customers = customers; NE TOCNO
    this->n = n;
    this->customers = new Customer [this->n];
    for (int i=0;i<this->n;i++)
      this->customers[i] = customers[i];
  }

  FINKI_bookstore & operator += (const Customer & c) {
    if (contains(c))
      throw UserExistsException();
    Customer * tmp = new Customer[this->n + 1];
    for (int i=0;i<n;i++)
      tmp[i]=customers[i];
    tmp[n++] = c;
    delete [] customers;
    customers = tmp;
    return *this;
  }

  void update () {
    for (int i=0;i<n;i++) {
      // if (customers[i].getType()==standard && customers[i].getNumProducts()>5) 
      //   customers.setType(1); //loyal
      // if (customers[i].getType()==loyal && customers[i].getNumProducts()>10)
      //   customers.setType(2);//vip
      customers[i].update();
    }
  }

  friend ostream & operator << (ostream & out, const FINKI_bookstore & fb) {
    for (int i=0;i<fb.n;i++)
      out<<fb.customers[i];
    return out;
  }

};

int main(){
  int testCase;
  cin >> testCase;

  char name[MAX];
  char email[MAX];
  int tC;
  int discount;
  int numProducts;


  if (testCase == 1){
    cout << "===== Test Case - Customer Class ======" << endl;
    cin.get();
    cin.getline(name,MAX);
    cin.getline(email,MAX);
    cin >> tC;
    cin >> numProducts;
    cout << "===== CONSTRUCTOR ======" << endl;
    Customer c(name, email, (typeC) tC, numProducts);
    cout << c;

  }

  if (testCase == 2){
    cout << "===== Test Case - Static Members ======" << endl;
    cin.get();
    cin.getline(name,MAX);
    cin.getline(email,MAX);
    cin >> tC;
    cin >> numProducts;
    cout << "===== CONSTRUCTOR ======" << endl;
    Customer c(name, email, (typeC) tC, numProducts);
    cout << c;

    c.setDiscount1(5);

    cout << c;
  }

  if (testCase == 3){
    cout << "===== Test Case - FINKI-bookstore ======" << endl;
    FINKI_bookstore fc;
    int n;
    cin >> n;
    Customer customers[MAX];
    for(int i = 0; i < n; ++i) {
      cin.get();
      cin.getline(name,MAX);
      cin.getline(email,MAX);
      cin >> tC;
      cin >> numProducts;
      Customer c(name, email, (typeC) tC, numProducts);
      customers[i] = c;
    }

    fc.setCustomers(customers, n);

    cout << fc <<endl;
  }

  if (testCase == 4){
    cout << "===== Test Case - operator+= ======" << endl;
    FINKI_bookstore fc;
    int n;
    cin >> n;
    Customer customers[MAX];
    for(int i = 0; i < n; ++i) {
      cin.get();
      cin.getline(name,MAX);
      cin.getline(email,MAX);
      cin >> tC;
      cin >> numProducts;
      Customer c(name, email, (typeC) tC, numProducts);
      customers[i] = c;
    }

    fc.setCustomers(customers, n);
    cout << "OPERATOR +=" << endl;
    cin.get();
    cin.getline(name,MAX);
    cin.getline(email,MAX);
    cin >> tC;
    cin >> numProducts;
    Customer c(name, email, (typeC) tC, numProducts);
    fc+=c;

    cout << fc;
  }

  if (testCase == 5){
    cout << "===== Test Case - operator+= (exception) ======" << endl;
    FINKI_bookstore fc;
    int n;
    cin >> n;
    Customer customers[MAX];
    for(int i = 0; i < n; ++i) {
      cin.get();
      cin.getline(name,MAX);
      cin.getline(email,MAX);
      cin >> tC;
      cin >> numProducts;
      Customer c(name, email, (typeC) tC, numProducts);
      customers[i] = c;
    }

    fc.setCustomers(customers, n);
    cout << "OPERATOR +=" << endl;
    cin.get();
    cin.getline(name,MAX);
    cin.getline(email,MAX);
    cin >> tC;
    cin >> numProducts;
    
    Customer c (name, email, (typeC) tC, numProducts);
    try {
      fc+=c;
    }
    catch (UserExistsException & u) {
      u.showMessage();
    }
    
    cout << fc;
  }

  if (testCase == 6){
    cout << "===== Test Case - update method  ======" << endl << endl;
    FINKI_bookstore fc;
    int n;
    cin >> n;
    Customer customers[MAX];
    for(int i = 0; i < n; ++i) {
      cin.get();
      cin.getline(name,MAX);
      cin.getline(email,MAX);
      cin >> tC;
      cin >> numProducts;
      Customer c(name, email, (typeC) tC, numProducts);
      customers[i] = c;
    }

    fc.setCustomers(customers, n);

    cout << "Update:" << endl;
    fc.update();
    cout << fc;
  }
  return 0;
   
}
