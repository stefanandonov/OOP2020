#include <string.h>
#include <iostream>
using namespace std;

// Your Code goes here
class Server {
protected:
  char IP [45];
  char name [100];

public:
  Server (char * IP = "127.1.0.0", char * name = "unknown") {
    strcpy(this->IP, IP);
    strcpy(this->name, name);
  }

  Server (const Server & s) {
    strcpy(this->IP, s.IP);
    strcpy(this->name, s.name);
  }

  //virtual double total_price () = 0; 

  // bool operator > (Server & other) {
  //   return this->total_price() > other.total_price();
  // }
};

//bool operator > (Server & left, Server & right) {
//  return left.total_price() > right.total_price();
//}

class DedicatedServer : public Server {
  private:
    double startPrice;
    int RAM;
    int * hardDisks;
    int n;

    /*void copy (const DedicatedServer & other)  {
      this->startPrice = other.startPrice;
      this->RAM = other.RAM;
      this->n = other.n;
      this->hardDisks = new int [this->n];
      //strcpy(this->hardDisks, other.hardDisks); NEMOJTE PLS
      for (int i=0;i<this->n;i++) {
        this->hardDisks[i] = other.hardDisks[i];
      }
    }

    int sumOfHardDisks () const {
      int sum = 0;
      for (int i=0;i<n;i++) {
        sum+=hardDisks[i];
      }
      return sum;
    } */
  public: 
    DedicatedServer (char * IP = "127.1.0.0", char * name = "unknown", 
      double startPrice = 200, int RAM = 4) : Server(IP, name) {
      this->startPrice = startPrice;
      this->RAM = RAM;
      this->hardDisks = new int [0]; //prazna niza nemame nitu eden hard disk koga kupuvame server
      this->n = 0;
    }

   /* DedicatedServer (const DedicatedServer & other) : Server(other) {
      copy(other);
    }

    DedicatedServer & operator = (const DedicatedServer & other) {
      if (this!=&other) {
        delete [] hardDisks;
        strcpy(this->IP, other.IP);
        strcpy(this->name, other.name);
        copy(other);
      }
      return *this;
    }

    ~DedicatedServer () {
      delete [] hardDisks;
    }

    double total_price () {
      //основната цена + хард_диск_простор * 0.5 + рам_меморија * 20.
      return startPrice + sumOfHardDisks()*0.5 + RAM * 20.0;
    }

    DedicatedServer & operator += (int size) {
      int * tmp = new int [n+1];
      for (int i=0;i<n;i++)
        tmp[i]=hardDisks[i];
      tmp[n]=size;
      n++;
      delete [] hardDisks;
      hardDisks = tmp;
      return *this;
    }

    DedicatedServer & operator ++ () { //prefix
      RAM++;
      return *this;
    }

    DedicatedServer operator ++ (int) { //postinkrement
      DedicatedServer copy (*this);
      RAM++;
      return copy;
    } */

    friend ostream & operator << (ostream & out, const DedicatedServer & ds) {
      /*[име на хост]: [IP адреса]
    [основна цена], [рам меморија]
    [број на дискови], [вкупен капацитет на сите дискови]
      */
      out<<ds.name<<": "<<ds.IP<<endl;
      out<<ds.startPrice<<", "<<ds.RAM<<endl;
      //out<<ds.n<<", "<<ds.sumOfHardDisks()<<endl;
      return out;
    }
};

// Testing
int main() {
  int test_case;
  char hostname[101];
  char ip[46];
  int ram;
  int basic_price;
  int disk_space;
  int num_cores;
  int bandwith;

  int num_inc;

  cin >> test_case;
  if (test_case == 1) {
    // Test Case Business Invoice - Constructor, operator <<
    cin >> ip >> hostname;
    cin >> basic_price >> ram;
    DedicatedServer ds(ip, hostname, basic_price, ram);
    cout << ds;
  } /*else if (test_case == 2) {
    // Test Case Business Invoice - Constructor, operators <<, ++
    cin >> ip >> hostname;
    cin >> basic_price >> ram;
    DedicatedServer ds(ip, hostname, basic_price, ram);
    cout << ds;

    cin >> num_inc;
    for (int i = 0; i < num_inc; ++i) {
      ds++;
    }
    cout << ds;
  } else if (test_case == 3) {
    // Test Case Business Invoice - Constructor, total_price, operators <<,
    cin >> ip >> hostname;
    cin >> basic_price >> ram;
    DedicatedServer ds(ip, hostname, basic_price, ram);
    cout << ds;

    cin >> num_inc;
    for (int i = 0; i < num_inc; ++i) {
      ds++;
    }

    cin >> num_inc;
    for (int i = 0; i < num_inc; ++i) {
      cin >> disk_space;
      ds += disk_space;
    }

    cout << ds;
  } else if (test_case == 4) {
    cin >> ip >> hostname;
    cin >> basic_price >> ram;
    DedicatedServer ds(ip, hostname, basic_price, ram);
    cout << ds;
    cout << ds.total_price()<< endl;
    cin >> num_inc;
    for (int i = 0; i < num_inc; ++i) {
      ds++;
    }

    cin >> num_inc;
    for (int i = 0; i < num_inc; ++i) {
      cin >> disk_space;
      ds += disk_space;
    }

    cout << ds;
    cout << ds.total_price();

  } else if (test_case == 5) {
    cin >> ip >> hostname;
    cin >> num_cores >> bandwith;
    VirtualServer vs(ip, hostname, num_cores, bandwith);
    cout << vs;
  } else if (test_case == 6) {
    cin >> ip >> hostname;
    cin >> num_cores >> bandwith;
    VirtualServer vs(ip, hostname, num_cores, bandwith);
    cout << vs;
    cin >> num_inc;
    for (int i = 0; i < num_inc; ++i) {
      vs++;
    }

    cin >> num_inc;
    vs += num_inc;

    cout << vs;

  } else if (test_case == 7) {
    cin >> ip >> hostname;
    cin >> num_cores >> bandwith;
    VirtualServer vs(ip, hostname, num_cores, bandwith);
    cout << vs;
    cout << vs.total_price() << endl;

    cin >> num_inc;
    for (int i = 0; i < num_inc; ++i) {
      vs++;
    }

    cin >> num_inc;
    vs += num_inc;
    cout << vs;
    cout << vs.total_price();
  } else if (test_case == 8) {

    int num_servers;
    int server_type;

    cin >> num_servers;
    Server **s = new Server *[num_servers];
    for (int j = 0; j < num_servers; ++j) {

      cin >> server_type;
      if (server_type == 1) {
        cin >> ip >> hostname;
        cin >> basic_price >> ram;
        DedicatedServer *dsp =
            new DedicatedServer(ip, hostname, basic_price, ram);

        cin >> num_inc;
        for (int i = 0; i < num_inc; ++i) {
          (*dsp)++;
        }

        cin >> num_inc;
        for (int i = 0; i < num_inc; ++i) {
          cin >> disk_space;
          (*dsp) += disk_space;
        }

        cout << *(dsp);
        cout << dsp->total_price() << endl;

        s[j] = dsp;
      }
      if (server_type == 2) {

        cin >> ip >> hostname;
        cin >> num_cores >> bandwith;
        VirtualServer *vsp =
            new VirtualServer(ip, hostname, num_cores, bandwith);

        cin >> num_inc;
        for (int i = 0; i < num_inc; ++i) {
          (*vsp)++;
        }

        cin >> num_inc;
        (*vsp) += num_inc;

        cout << (*vsp);
        cout << vsp->total_price() << endl;
        s[j] = vsp;
      }
    }

    cout << "The cost of all servers is:\n";
    cout << totalCost(s, num_servers);
    cout << endl;

    cout << "Biggest invoice:\n";
    Server &server = biggestInvoice(s, num_servers);

    Server *ss = &server;
    DedicatedServer *bip;
    VirtualServer *pip;
    if (dynamic_cast<DedicatedServer *>(ss)) {
      bip = dynamic_cast<DedicatedServer *>(ss);
      cout << *bip << bip->total_price();
    }
    if (dynamic_cast<VirtualServer *>(ss)) {
      pip = dynamic_cast<VirtualServer *>(ss);
      cout << *pip << pip->total_price();
    }
  }*/
  return 0;
}
