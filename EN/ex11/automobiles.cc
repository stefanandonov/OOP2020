#include <iostream>
#include <cstring>

using namespace std;

enum tip {
    petrol,
    electric
};

class InvalidProductionDate {
    public:
    void showMessage() {
        cout<<"Invalid production year."<<endl;
    }
};


class Avtomobil {
    char model [100];
    tip type;
    static float basicServiceTime;
    int year;

    char * getTypeString () const {
        if (type == electric)
            return "Electrical";
        else
            return "Petrol";
    }

public:
    Avtomobil (char * model = "mercedes", tip type = petrol, int year = 2010) {
        strcpy(this->model, model);
        this->type = type;
        this->year = year;
    }

    Avtomobil (const Avtomobil & a) {
        strcpy(this->model, a.model);
        this->type = a.type;
        this->year = a.year;
    }

    float computeServiceTime () const {
        float result = basicServiceTime;
        if (year<2010)
            result+=1.0;
        if (type == electric)
            result-=0.5;
        return result;
    }

    friend ostream & operator << (ostream & out, const Avtomobil & a) {
        /*
        [car_model]
        [car_type] [hours_needed_for_service]
        */

        return out<<a.model<<endl<<a.getTypeString()<<" "<<a.computeServiceTime()<<endl;
    }

    int getYear() const {
        return year;
    }
    
    static void setPocetniCasovi (double value) {
        Avtomobil::basicServiceTime = value;
    }

};

float Avtomobil::basicServiceTime = 2.0;

class AvtoServis {
    char name [100];
    Avtomobil * automobiles;
    int n;

    void copy (const AvtoServis & as) {
        strcpy(this->name, as.name);
        this->n = as.n;
        this->automobiles = new Avtomobil [this->n];
        for (int i=0;i<n;i++)
            this->automobiles[i] = as.automobiles[i];
    }

public:
    AvtoServis (char * name = "") {
        strcpy(this->name, name);
        automobiles = new Avtomobil [0];
        n = 0;
    }

    AvtoServis (const AvtoServis & as) {
        copy(as);
    }

    AvtoServis & operator = (const AvtoServis & as) {
        if (this!=&as) {
            delete [] automobiles;
            copy(as);
        }
        return *this;
    }

    ~AvtoServis () {
        delete [] automobiles;
    }

    AvtoServis & operator += (const Avtomobil & a) {
        if (a.getYear()>2019 || a.getYear()<1900)
            throw InvalidProductionDate();

        Avtomobil * tmp = new Avtomobil [n+1];
        for (int i=0;i<n;i++) {
            tmp[i] = automobiles[i];
        }
        tmp[n++] = a;
        delete [] automobiles;
        automobiles = tmp;

        return *this;
    }

    void pecatiCasovi () {
        cout<<"Name: "<<name<<endl;
        for (int i=0;i<n;i++)
            cout<<automobiles[i];
    }


};


int main()
{
    int testCase;
    cin >> testCase;
    char ime[100];
    int tipAvtomobil;
    int godina;
    int n;
    Avtomobil avtomobili[50];
    if (testCase == 1){
        cout << "===== Testing the classs ======" << endl;
        cin >> ime;
        cin >> tipAvtomobil;
        cin >> godina;
        Avtomobil ig(ime,(tip)tipAvtomobil,godina);
        cin>>ime;
        AvtoServis t(ime);
        cout<<ig;
        }
    if (testCase == 2){
        cout << "===== testing the operator += ======" << endl;
        cin>>ime;
        cin >> n;
        AvtoServis t(ime);
        for(int i=0;i<n;i++)
        {
            cin >> ime;
            cin >> tipAvtomobil;
            cin >> godina;
            Avtomobil tmp(ime,(tip)tipAvtomobil,godina);
            try {
                t+=tmp;
            }
            catch (InvalidProductionDate & e) {
                e.showMessage();
            }
        }
        t.pecatiCasovi();
    }
    if (testCase == 3){
        cout << "===== Testing exceptions ======" << endl;
        cin>>ime;
        cin >> n;
        AvtoServis t(ime);
        for(int i=0;i<n;i++)
        {
            cin >> ime;
            cin >> tipAvtomobil;
            cin >> godina;
            Avtomobil tmp(ime,(tip)tipAvtomobil,godina);
            
            try {
                t+=tmp;
            }
            catch (InvalidProductionDate & e) {
                e.showMessage();
            }
        }
        t.pecatiCasovi();
    }
    if (testCase == 4){
        cout <<"===== Testing constructors ======"<<endl;
         cin>>ime;
        cin >> n;
        AvtoServis t(ime);
        for(int i=0;i<n;i++)
        {
            cin >> ime;
            cin >> tipAvtomobil;
            cin >> godina;
            Avtomobil tmp(ime,(tip)tipAvtomobil,godina);
            try {
                t+=tmp;
            }
            catch (InvalidProductionDate & e) {
                e.showMessage();
            }
        }
        AvtoServis t2 = t;
        t2.pecatiCasovi();
    }
    if (testCase == 5){
        cout << "===== Testing static members ======" << endl;
        cin>>ime;
        cin >> n;
        AvtoServis t(ime);
        for(int i=0;i<n;i++)
        {
            cin >> ime;
            cin >> tipAvtomobil;
            cin >> godina;
            Avtomobil tmp(ime,(tip)tipAvtomobil,godina);

            t+=tmp;
        }
        t.pecatiCasovi();
        cout << "===== Changing static members ======" << endl;
        Avtomobil::setPocetniCasovi(4);
        t.pecatiCasovi();
    }

        if (testCase == 6){
        cout << "===== Testing the complete functioning ======" << endl;
        cin>>ime;
        cin >> n;
        AvtoServis t(ime);
        for(int i=0;i<n;i++)
        {
            cin >> ime;
            cin >> tipAvtomobil;
            cin >> godina;
            Avtomobil tmp(ime,(tip)tipAvtomobil,godina);
            try {
                t+=tmp;
            }
            catch (InvalidProductionDate & e) {
                e.showMessage();
            }
        }
        Avtomobil::setPocetniCasovi(4);
        AvtoServis t2 = t;
        t2.pecatiCasovi();
    }

    return 0;

}

