#include<iostream>
#include<cstring>

using namespace std;

//Your code here

class Tickets {
    
protected:
    static int discount;
    int ID [12];
    char event [100];
    float basicPrice;
public:
    Tickets() {
        for (int i=0; i<12; i++) { //01234567901
            ID[i]=i%10;
        }
        strcpy(event, "NO NAME");
        basicPrice = 1.0;

    }
    Tickets (int * ID, char * event,
             float basicPrice) {
        for (int i=0; i<12; i++) {
            this->ID[i] = ID[i];
        }
        strcpy(this->event, event);
        this->basicPrice = basicPrice;
    }

    Tickets (const Tickets & t) {
        for (int i=0; i<12; i++) {
            this->ID[i] = t.ID[i];
        }
        strcpy(this->event, t.event);
        this->basicPrice = t.basicPrice;
    }

    bool falsifikat(int from, int to) { //012345678901  5 8
        int number = 1000*ID[8] + 100*ID[9] + 10*ID[10] + ID[11];
        
        return !(number>=from&&number<=to);
            
            
        
        
        //for (int i=8; i<12; i++) {
        //    if (ID[i]<from || ID[i]>to) {
        //        return true;
        //    }            
        //}
        //return false;
        
    }
    
    virtual float presmetajCena () const = 0;

    //virtual float presmetajCena() const {
    //    return basicPrice*(1-(discount/100.0));
    //}

    friend ostream & operator << (ostream & out, const Tickets & t) {
        //ID - event - computed price
        for (int i=0;i<12;i++)
            out<<t.ID[i];
        return out<<"-"<<t.event<<"-"<<t.presmetajCena();
        
    }

    static void changeDiscount(int d) {
        discount = d;
    }

};

int Tickets::discount = 0;

class Online : public Tickets {
    bool premium;
    const static float premiumDiscount;
public:
    Online () : Tickets() {
        this->premium = false;
    }
    Online (int * ID, char * event,
            float basicPrice, bool premium) : Tickets(ID, event, basicPrice) {
        this->premium = premium;
    }

    Online (const Online & o) : Tickets (o) {
        this->premium = o.premium;
    }

    float presmetajCena () const {
        return (premium ?
                basicPrice*(1-(premiumDiscount+(discount/100.0))) :
                basicPrice*(1-(discount/100.0)));
    }
};

const float Online::premiumDiscount = 0.15;

class Offline : public Tickets {
    bool reservation;
    const static float extraCharge;
public:
    Offline () : Tickets() {
        this->reservation = false;
    }
    Offline (int * ID, char * event,
             float basicPrice, bool reservation) : Tickets(ID, event, basicPrice) {
        this->reservation = reservation;
    }

    Offline (const Offline & o) : Tickets (o) {
        this->reservation = o.reservation;
    }

    float presmetajCena () const {
        return (reservation ?
                basicPrice*(1+extraCharge-(discount/100.0)) :
                basicPrice*(1-(discount/100.0)));
    }

};

const float Offline::extraCharge = 0.1; //10%;

void vkupenPrihod(Tickets ** t, int n, int from, int to) {
    float sum = 0.0;
    for (int i=0; i<n; i++) {
        if (!t[i]->falsifikat(from,to)) {
            sum+=t[i]->presmetajCena();
        }
    }

    cout<<sum<<endl;
}

// DO NOT CHANGE THE MAIN FUNCTION, EXCEPT THE MARKED PART FOR HANDLING WITH THE EXCEPTION
int main() {
    int testCase;
    cin >> testCase;
    int ID[12];
    char nastan[100];
    float price;
    bool premium;
    bool rezervacija;
    int od, doo;

    if (testCase == 1) {
        cout << "===== TESTING CONSTRUCTORS ======" << endl;
        for (int i = 0; i < 12; i++)
            cin >> ID[i];
        cin >> nastan;
        cin >> price;
        cin >> premium;
        Online o1(ID, nastan, price, premium);
        cout << o1 << endl;
        for (int i = 0; i < 12; i++)
            cin >> ID[i];
        cin >> nastan;
        cin >> price;
        cin >> rezervacija;
        Offline o2(ID, nastan, price, rezervacija);
        cout << o2 << endl;

    } else if (testCase == 2) {
        cout << "===== TESTING METHOD vkupenPrihod()  ======" << endl;
        int n;
        cin >> n;
        Tickets** t = new Tickets*[n];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < 12; j++)
                cin >> ID[j];
            cin >> nastan;
            cin >> price;

            if (i % 2 == 0) {
                cin >> premium;
                t[i] = new Online(ID, nastan, price, premium);
            } else {
                cin >> rezervacija;
                t[i] = new Offline(ID, nastan, price, rezervacija);
            }
        }
        cin >> od;
        cin >> doo;
        vkupenPrihod(t, n, od, doo);
        for (int i = 0; i < n; ++i) {
            //delete t[i];
        }
        delete[] t;
    } else if (testCase == 3) {
        cout << "===== TESTING DISCOUNT STATIC ======" << endl;
        int n;
        cin >> n;
        //cout<<n<<endl;
        Tickets** t = new Tickets*[n];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < 12; ++j)
                cin >> ID[j];
            cin >> nastan;
            //cout<<nastan<<endl;
            cin >> price;
            //cout<<price<<endl;
            if (i % 2 == 0) {
                cin >> premium;
                t[i] = new Online(ID, nastan, price, premium);
            } else {
                cin >> rezervacija;
                //cout<<rezervacija<<endl;
                t[i] = new Offline(ID, nastan, price, rezervacija);
            }
        }
        int d;
        cin >> d;
        Tickets::changeDiscount(d);
        for (int i = 0; i < n; ++i)
            cout << *t[i] << endl;

    }
}
