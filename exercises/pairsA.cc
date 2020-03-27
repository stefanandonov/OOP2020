#include <iostream>
#include <cstring>
using namespace std;


class Pair {
private:
    char * key;
    float value;

    void copy (const Pair &p) {
        this->key = new char [strlen(p.key)+1];
        strcpy(this->key, p.key);
        this->value = p.value;
    }

public:
    Pair (char * key = "" , float value = 0.0) {
        this->key = new char [strlen(key)+1];
        strcpy(this->key, key);
        this->value = value;
    }

    Pair (const Pair &p) {
        copy (p);
    }

    Pair & operator = (const Pair &p) {
        if (this!=&p) {
            delete [] key;
            copy(p);
        }
        
        return *this;
    }
  

    ~Pair () {
        delete [] key;
    }

    Pair & operator ++ () {
        ++value;
        return *this;
    }

    Pair  operator ++ (int) {
        Pair tmp (key,value);
        ++value;
        return tmp;
    }

    Pair operator + (Pair p) {
        if (strlen(this->key)>=strlen(p.key)) {
            return Pair (this->key, this->value + p.value);
        } else {
            return Pair (p.key, this->value + p.value);
        }
    }

    friend ostream & operator << (ostream &out, const Pair & p) {
        return out<<"('"<<p.key<<"', "<<p.value<<")"<<endl;
    }

    bool operator != (Pair & p) {
        return strcmp(key, p.key)!=0 || value!=p.value;
    }

    char * getKey () {
        return key;
    }
};

class Collection {
private:
    Pair * pairs;
    int length;

    void copy (const Collection &c) {
        pairs = new Pair [c.length];
        for (int i=0;i<c.length;i++)
            pairs[i] = c.pairs[i];
        this->length = c.length;
    }

public:
    Collection() {
        pairs = new Pair [0];
        length = 0;
    }

    Collection (const Collection & c) {
        copy(c);
    }

    Collection & operator = (const Collection & c) {
        if (this!=&c) {
            delete [] pairs;
            copy(c);
        }
        return *this;
    }

    ~Collection() {
        delete [] pairs;
    }

    Collection & operator += (const Pair & p) {
        Pair * tmp = new Pair [length + 1];
        
        for (int i=0;i<length;i++)
            tmp[i] = pairs[i];

        tmp[length++] = p;

        delete [] pairs;
        pairs = tmp;
        
        return *this;
    }

    friend ostream &operator << (ostream & out, const Collection &c) {
        out<<"Size: "<<c.length<<endl;
        for (int i=0;i<c.length;i++)
            out<<c.pairs[i];
        return out;
    }

    bool operator == (Collection & c) {
        if (this->length!=c.length)
            return false;
        else {
            for (int i=0;i<this->length;i++)
                if (pairs[i]!=c.pairs[i])
                    return false;


            return true;
        }
    }

    Pair * find (const char * key) {

        for (int i=0;i<length;i++) {
            if (strcmp(key, pairs[i].getKey())==0) {
                return &pairs[i];
            }
        }

        return NULL;
    }



};

void read(char *k, float *v) {
    cin >> k;
    cin >> *v;
}
int main() {
    char key[50];
    float value;
    cout << "----- class Pair -----" << endl;
    read(key, &value);
    cout << "----- constructor -----" << endl;
    Pair p1(key, value);
    read(key, &value);
    Pair p2(key, value);
    Pair p3(p1);
    cout << "----- operator << -----" << endl;
    cout << p1;
    cout << p2;
    cout << "----- operator ++(int) -----" << endl;
    cout << p1++;
    cout << p1;
    cout << "----- operator ++ -----" << endl;
    cout << ++p2;
    cout << "----- operator + -----" << endl;
    Pair p = p1 + p2;
    cout << "----- operator = -----" << endl;
    p3 = p;
    cout << p3;

    cout << "----- class Collection -----" << endl;
    cout << "----- constructor -----" << endl;
    Collection k;
    cout << "----- operator += -----" << endl;
    k += p1;
    k += p2;
    k += p3;
    cout << "----- operator << -----" << endl;
    cout << k;
    cout << "----- copy constructor -----" << endl;
    Collection k2(k);
    cout << "----- operator == -----" << endl;
    if(k == k2) {
        cout << "k == k2" << endl;
    }
    k2 += p1;
    if(k == k2) {
        // not equal
        cout << "k == k2" << endl;
    }
    cout << "----- find -----" << endl;
    //cout<<key<<endl;
    Pair* f = k.find(key);
    cout << *f;
    strcat(key, "other");
    f = k.find(key);
    if(f == NULL) {
        cout << key << " not found" << endl;
    }
    else cout << *f;
    return 0;
}
